import json, marshal, os, shutil, subprocess
from setuptools import setup, Extension
import sys
from files.version import __version__
from pathlib import Path
import glob
from shutil import copy

###################################################################################################
#
# Setup for NREL-PySAM Package
#
###################################################################################################

latest_version = __version__

DEBUG = False

# defaults and include directories
defaults_dir = os.environ['SAMNTDIR'] + "/api/api_autogen/library/defaults/"
includepath = os.environ['SAMNTDIR'] + "/api/include"
srcpath = os.environ['SAMNTDIR'] + "/api/src"

this_directory = Path(os.environ['PYSAMDIR'])
libpath = this_directory / "files"

# prepare package description
with open(os.path.join(this_directory, 'RELEASE.md'), encoding='utf-8') as f:
    long_description = f.read()


# prepare package
libfiles = ['__init__.py', 'version.py']
extra_compile_args = ["-Wno-implicit-function-declaration", "-Wno-unused-function", "-Wno-strict-prototypes"]
extra_link_args = []
defines = []
libs = ['SAM_api']
if DEBUG:
    libs += ['sscd']
else:
    libs += ['ssc']

if sys.platform == 'darwin':
    from distutils import sysconfig
    vars = sysconfig.get_config_vars()
    vars['LDSHARED'] = vars['LDSHARED'].replace('-bundle', '-dynamiclib')
    libfiles += ['libSAM_api.so']
    if DEBUG:
        libfiles += ['libsscd.so']
    else:
        libfiles += ['libssc.so']
    extra_link_args = ["-headerpad_max_install_names", "-Wl,-rpath,@loader_path/"]
    extra_compile_args.append("-Wno-ignored-attributes")
elif sys.platform == 'linux':
    libfiles += ['libSAM_api.so']
    if DEBUG:
        libfiles += ['libsscd.so']
    else:
        libfiles += ['libssc.so']
    extra_link_args = ["-Wl,-rpath,$ORIGIN/"]
    extra_compile_args.append('-Wno-attributes')
elif sys.platform == 'win32':
    libfiles += ['SAM_api.dll', 'SAM_api.lib']
    if DEBUG:
        libfiles += ['sscd.dll', 'sscd.lib']
    else:
        libfiles += ['ssc.dll', 'ssc.lib']
    defines = [('__WINDOWS__', '1')]
    extra_compile_args = []
    if DEBUG:
        extra_compile_args = ["/DEBUG", "/Od"]

# get or-tools
ortools_libfiles = []
def copy_ortools(lib_path, platform):
    # copy ortools over and add to files
    ortools_lib_dir = Path(os.environ['ORTOOLSDIR']) / lib_path
    if platform != "win32":
        ortools_libs_pattern = ["libabsl*", "libre2*", "libscip*"]
    else:
        ortools_libs_pattern = ["absl*", "re2*", "scip*"]
    for ortools_lib in ortools_libs_pattern:
        for lib_file in glob.glob(str(ortools_lib_dir / ortools_lib)):
            if not Path(lib_file).is_symlink():
                dest = libpath / Path(lib_file).name
                copy(lib_file, str(dest))
                if platform == "darwin":
                    # Fix embedded install name so the linker records the correct filename
                    subprocess.run(
                        ['install_name_tool', '-id', f'@rpath/{dest.name}', str(dest)],
                        check=True
                    )
                libfiles.append(dest.name)
                ortools_libfiles.append(dest)
                if platform == "darwin":
                    libs.append(dest.stem.split("lib")[1])
                elif platform == "linux":
                    # For the linker to find it via the linker name, a symlink to "linker name" must exist alongside the versioned file
                    linker_name = dest.name.split(".so")[0] + ".so"
                    if (libpath / linker_name).exists():
                        os.remove(libpath / linker_name)
                    subprocess.run(
                        ['ln', '-s', str(libpath / dest.name), str(libpath / linker_name)],
                        check=True
                    )
                    libs.append(linker_name.split("lib")[1].split(".so")[0])

if sys.platform == 'darwin':
    copy_ortools("lib", "darwin")
elif sys.platform == "linux":
    copy_ortools("lib64", "linux")
elif sys.platform == "win32":
    copy_ortools("lib", "win32")

###################################################################################################
#
# Copy Required Source and Data Files
#
###################################################################################################

# serialize all defaults into dict
def _decode(o):
    if isinstance(o, str):
        try:
            return float(o)
        except ValueError:
            return o
    elif isinstance(o, dict):
        dic = {}
        for k, v in o.items():
            if k != "hybrid_dispatch_schedule" and k != "biopwr_plant_tou_grid":
                dic[k] = _decode(v)
            else:
                dic[k] = v
        return dic
    elif isinstance(o, list):
        return [_decode(v) for v in o]
    else:
        return o

os.chdir(this_directory)
defaults_df_dir = 'files/defaults'
if os.path.exists(defaults_df_dir):
    shutil.rmtree(defaults_df_dir)
os.mkdir(defaults_df_dir)
# generate defaults and copy them into installation
for filename in os.listdir(defaults_dir):
    with open(defaults_dir + '/' + filename) as f:
        name = os.path.splitext(filename)
        if name[1] != '.json':
            continue
        data = json.load(f)

        dic = data[list(data.keys())[0]]
        with open('files/defaults/' + name[0].lower() + '.df', "wb") as out:
            marshal.dump(dic, out)

for filename in os.listdir(defaults_df_dir):
    libfiles.append('defaults/' + os.path.splitext(filename)[0] + '.df')

# copy over stub pyi files into "files" folder for export
stub_files = []
for filename in os.listdir(os.path.join(this_directory, "stubs", "stubs")):
    if ".pyi" not in filename:
        continue
    shutil.copy(os.path.join(this_directory, "stubs", "stubs", filename), os.path.join(this_directory, "files"))
    stub_files.append(os.path.join(filename))
libfiles += stub_files

hybrid_stubs = []
for filename in os.listdir(os.path.join(this_directory, "files", "Hybrids")):
    if ".pyi" not in filename:
        continue
    hybrid_stubs.append(os.path.join("Hybrids", filename))
libfiles += hybrid_stubs


# make list of all extension modules
extension_modules = []
for filename in os.listdir(this_directory / "modules"):
    extension_modules.append(Extension('PySAM.' + os.path.splitext(filename)[0],
                             ['modules/' + filename],
                            define_macros=defines,
                            include_dirs=[srcpath, includepath, str(this_directory / "src")],
                            library_dirs=[str(libpath)],
                            libraries=libs,
                            extra_compile_args=extra_compile_args,
                            extra_link_args=extra_link_args
                            ))


###################################################################################################
#
# setup script
#
###################################################################################################

def read_lines(filename):
    with open(filename) as f_in:
        return f_in.readlines()

setup(
    name='NREL-PySAM',
    version=latest_version,
    url='https://nrel-pysam.readthedocs.io',
    description="National Renewable Energy Laboratory's System Advisor Model Python Wrapper",
    long_description=long_description,
    long_description_content_type='text/markdown',
    license='BSD 3-Clause',
    author="dguittet",
    author_email="dguittet@nrel.gov",
    include_package_data=True,
    packages=['PySAM', 'PySAM.Hybrids'],
    package_dir={'PySAM': 'files', 'PySAM.Hybrids': 'files/Hybrids'},
    package_data={
        '': libfiles},
    tests_require=["pytest"],
    ext_modules=extension_modules
)


# Clean up
shutil.rmtree(defaults_df_dir)
for f in stub_files:
    os.remove(this_directory / "files" / f)
for f in ortools_libfiles:
    os.remove(f)
