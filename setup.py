"""
Minimal setup.py — only defines C extension modules.

All static metadata lives in pyproject.toml (PEP 621).
Run `python prepare_build.py` before building to stage shared libraries
and default files into PySAM/.
"""

import os
import sys
from pathlib import Path

from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext

this_directory = Path(__file__).parent.resolve()
pkg_dir = this_directory / "PySAM"
samntdir = os.environ.get("SAMNTDIR", "")

# ---------------------------------------------------------------------------
# Platform-specific compiler / linker flags
# ---------------------------------------------------------------------------

extra_compile_args = []
extra_link_args = []
defines = []
libs = ["SAM_api", "ssc"]

if sys.platform == "darwin":
    os.environ["MACOSX_DEPLOYMENT_TARGET"] = "12"
    extra_compile_args = [
        "-Wno-implicit-function-declaration",
        "-Wno-unused-function",
        "-Wno-strict-prototypes",
        "-Wno-ignored-attributes",
    ]
    extra_link_args = ["-headerpad_max_install_names", "-Wl,-rpath,@loader_path/"]

elif sys.platform == "linux":
    extra_compile_args = [
        "-Wno-implicit-function-declaration",
        "-Wno-unused-function",
        "-Wno-strict-prototypes",
        "-Wno-attributes",
    ]
    extra_link_args = ["-Wl,-rpath,$ORIGIN/"]

elif sys.platform == "win32":
    defines = [("__WINDOWS__", "1")]


# ---------------------------------------------------------------------------
# Discover OR-Tools libraries staged in PySAM/ by prepare_build.py
# ---------------------------------------------------------------------------

def _discover_ortools_libs(pkg_path):
    """Scan pkg_path for staged OR-Tools shared libraries, return lib names."""
    found = []
    if sys.platform in ("darwin", "linux"):
        for p in sorted(pkg_path.glob("lib*.so")):
            name = p.stem
            if name.startswith("lib") and name not in ("libSAM_api", "libssc", "libsscd"):
                found.append(name[3:])  # strip "lib" prefix
    elif sys.platform == "win32":
        for p in sorted(pkg_path.glob("*.lib")):
            name = p.stem
            if name not in ("SAM_api", "ssc", "sscd"):
                found.append(name)
    return found

libs += _discover_ortools_libs(pkg_dir)


# ---------------------------------------------------------------------------
# Include directories for C extensions
# ---------------------------------------------------------------------------

include_dirs = [str(this_directory / "csrc")]
if samntdir:
    include_dirs += [samntdir + "/api/src", samntdir + "/api/include"]


# ---------------------------------------------------------------------------
# Build extension module list from modules/*.c
# ---------------------------------------------------------------------------

extension_modules = []
modules_dir = this_directory / "modules"
for src_file in sorted(modules_dir.glob("*.c")):
    mod_name = src_file.stem
    extension_modules.append(
        Extension(
            f"PySAM.{mod_name}",
            [str(src_file.relative_to(this_directory))],
            define_macros=defines,
            include_dirs=include_dirs,
            library_dirs=[str(pkg_dir)],
            libraries=libs,
            extra_compile_args=extra_compile_args,
            extra_link_args=extra_link_args,
        )
    )


# ---------------------------------------------------------------------------
# Custom build_ext to handle macOS LDSHARED quirk
# ---------------------------------------------------------------------------

class CustomBuildExt(build_ext):
    def build_extensions(self):
        if sys.platform == "darwin":
            # Ensure extensions link as shared libraries, not bundles
            self.compiler.linker_so = [
                x.replace("-bundle", "-dynamiclib")
                for x in self.compiler.linker_so
            ]
        super().build_extensions()


setup(
    ext_modules=extension_modules,
    cmdclass={"build_ext": CustomBuildExt},
)
