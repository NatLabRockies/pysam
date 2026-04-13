#!/usr/bin/env python
"""
Pre-build preparation script for PySAM.

Run this BEFORE `pip install .` or `python -m build --wheel` to stage
external files (shared libraries, OR-Tools libs, defaults) into the
PySAM/ package directory.

Required environment variables:
  SAMNTDIR   - Path to the SAM repository root
  ORTOOLSDIR - Path to the OR-Tools installation

Usage:
  python prepare_build.py           # Stage files for building
  python prepare_build.py --clean   # Remove staged files
"""

import argparse
import glob
import json
import marshal
import os
import shutil
import subprocess
import sys
from pathlib import Path

MANIFEST_FILE = "PySAM/.staged_files.json"


def _decode(o):
    """Convert string-encoded numbers in JSON defaults to floats."""
    if isinstance(o, str):
        try:
            return float(o)
        except ValueError:
            return o
    elif isinstance(o, dict):
        return {
            k: v if k in ("hybrid_dispatch_schedule", "biopwr_plant_tou_grid") else _decode(v)
            for k, v in o.items()
        }
    elif isinstance(o, list):
        return [_decode(v) for v in o]
    else:
        return o


def stage_platform_libs(pkg_dir, staged):
    """Copy SAM_api and ssc shared libraries into pkg_dir."""
    samntdir = os.environ["SAMNTDIR"]

    if sys.platform == "darwin":
        # Look for libs in the typical cmake build output locations
        search_dirs = [
            Path(samntdir) / ".." / "cmake-build-release",
            Path(samntdir) / ".." / "build_pysam",
        ]
        lib_names = ["libSAM_api.so", "libssc.so"]
    elif sys.platform == "linux":
        search_dirs = [
            Path("/io/build_linux_sam"),
            Path("/io/build_linux_ssc"),
            Path(samntdir) / ".." / "cmake-build-release",
        ]
        lib_names = ["libSAM_api.so", "libssc.so"]
    elif sys.platform == "win32":
        search_dirs = [
            Path(samntdir) / ".." / "build_pysam" / "Release",
            Path(samntdir) / ".." / "cmake-build-release" / "Release",
        ]
        lib_names = ["SAM_api.dll", "SAM_api.lib", "ssc.dll", "ssc.lib"]
    else:
        print(f"Unsupported platform: {sys.platform}", file=sys.stderr)
        sys.exit(1)

def stage_ortools(pkg_dir, staged):
    """Copy OR-Tools runtime libraries into pkg_dir."""
    ortoolsdir = os.environ.get("ORTOOLSDIR")
    if not ortoolsdir:
        print("  ORTOOLSDIR not set, skipping OR-Tools staging.")
        return

    if sys.platform == "darwin":
        lib_subdir = "lib"
        patterns = ["libabsl*", "libre2*", "libscip*"]
    elif sys.platform == "linux":
        lib_subdir = "lib64"
        patterns = ["libabsl*", "libre2*", "libscip*"]
    elif sys.platform == "win32":
        lib_subdir = "lib"
        patterns = ["absl*", "re2*", "scip*"]
    else:
        return

    ortools_lib_dir = Path(ortoolsdir) / lib_subdir

    for pattern in patterns:
        for lib_file in glob.glob(str(ortools_lib_dir / pattern)):
            lib_path = Path(lib_file)
            if lib_path.is_symlink():
                continue
            dest = pkg_dir / lib_path.name
            shutil.copy2(str(lib_path), str(dest))

            if sys.platform == "darwin":
                subprocess.run(
                    ["install_name_tool", "-id", f"@rpath/{dest.name}", str(dest)],
                    check=True,
                )
            elif sys.platform == "linux":
                linker_name = dest.name.split(".so")[0] + ".so"
                linker_link = pkg_dir / linker_name
                if linker_link.exists():
                    os.remove(linker_link)
                os.symlink(dest.name, str(linker_link))
                staged.append(str(linker_link))

            staged.append(str(dest))
            print(f"  Staged OR-Tools lib: {dest.name}")


def stage_defaults(pkg_dir, staged):
    """Generate .df default files from SAM JSON defaults."""
    samntdir = os.environ["SAMNTDIR"]
    defaults_src = Path(samntdir) / "api" / "api_autogen" / "library" / "defaults"
    defaults_dst = pkg_dir / "defaults"

    if defaults_dst.exists():
        shutil.rmtree(defaults_dst)
    defaults_dst.mkdir()
    staged.append(str(defaults_dst))

    count = 0
    for filename in sorted(os.listdir(defaults_src)):
        name, ext = os.path.splitext(filename)
        if ext != ".json":
            continue
        with open(defaults_src / filename) as f:
            data = json.load(f)
        dic = data[list(data.keys())[0]]
        out_path = defaults_dst / (name.lower() + ".df")
        with open(out_path, "wb") as out:
            marshal.dump(dic, out)
        staged.append(str(out_path))
        count += 1

    print(f"  Generated {count} default files in {defaults_dst}")


def save_manifest(staged):
    """Save the list of staged files for cleanup."""
    with open(MANIFEST_FILE, "w") as f:
        json.dump(staged, f, indent=2)
    print(f"\nManifest written to {MANIFEST_FILE}")


def do_stage():
    """Stage all external files into PySAM/ for building."""
    pkg_dir = Path("PySAM")
    if not pkg_dir.is_dir():
        print(f"ERROR: Package directory {pkg_dir} not found.", file=sys.stderr)
        print("Run this script from the pysam repo root.", file=sys.stderr)
        sys.exit(1)

    staged = []

    print("Staging platform libraries...")
    stage_platform_libs(pkg_dir, staged)

    print("Staging OR-Tools libraries...")
    stage_ortools(pkg_dir, staged)

    print("Generating defaults...")
    stage_defaults(pkg_dir, staged)

    save_manifest(staged)
    print(f"\nDone. {len(staged)} files staged. Ready to build.")


def do_clean():
    """Remove staged files using the manifest."""
    if not os.path.exists(MANIFEST_FILE):
        print("No manifest found. Nothing to clean.")
        return

    with open(MANIFEST_FILE) as f:
        staged = json.load(f)

    # Remove files first, then directories (reverse order handles nested paths)
    files = [p for p in staged if os.path.isfile(p) or os.path.islink(p)]
    dirs = [p for p in staged if os.path.isdir(p)]

    for p in files:
        os.remove(p)
        print(f"  Removed {p}")

    for d in sorted(dirs, key=len, reverse=True):
        if os.path.isdir(d):
            shutil.rmtree(d)
            print(f"  Removed directory {d}")

    os.remove(MANIFEST_FILE)
    print(f"\nCleanup complete. Removed {len(files)} files and {len(dirs)} directories.")


def main():
    parser = argparse.ArgumentParser(description="PySAM pre-build file staging")
    parser.add_argument("--clean", action="store_true",
                        help="Remove previously staged files")
    args = parser.parse_args()

    if args.clean:
        do_clean()
    else:
        do_stage()


if __name__ == "__main__":
    main()
