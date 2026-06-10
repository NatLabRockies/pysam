#!/bin/sh

export SSCDIR=/io/ssc
export SAMNTDIR=/io/sam
export PYSAMDIR=/io/pysam

if [ "$(uname -m)" = "aarch64" ]; then
    ORTOOLS=or-tools_aarch64_AlmaLinux-8.10_cpp_v9.14.6206
else
    ORTOOLS=or-tools_x86_64_AlmaLinux-8.10_cpp_v9.14.6206
    export CC=gcc
    export CXX=g++
fi

export ORTOOLSDIR=/${ORTOOLS}
mkdir ${ORTOOLSDIR}
curl -L https://github.com/google/or-tools/releases/download/v9.14/${ORTOOLS}.tar.gz -o ${ORTOOLS}.tar.gz
tar xvzf ${ORTOOLS}.tar.gz -C ${ORTOOLSDIR} --strip-components=1

mkdir -p /io/build_linux_ssc
cd /io/build_linux_ssc
rm -rf *
cmake ${SSCDIR} -DCMAKE_BUILD_TYPE=Release -DSAM_SKIP_TOOLS=1 -DSAMAPI_EXPORT=1 -DSAM_SKIP_TESTS=1 -DUSE_XPRESS=0 -DUSE_COINOR=1 -DCMAKE_SYSTEM_PREFIX_PATH="$ORTOOLSDIR" -Dabsl_DIR="$ORTOOLSDIR\lib\cmake\absl" -Dutf8_range_DIR="$ORTOOLSDIR\lib\cmake\utf8_range" -Dortools_DIR="$ORTOOLSDIR\lib\cmake\ortools" ../ssc || exit
cmake --build . --target shared -j 6 || exit
cmake --build . --target ssc -j 6 || exit

mkdir -p /io/build_linux_sam
cd /io/build_linux_sam
rm -rf *
cmake ${SAMNTDIR}/api -DCMAKE_BUILD_TYPE=Release -DSAMAPI_EXPORT=1 -DSAM_SKIP_AUTOGEN=1 -DUSE_XPRESS=0 -DUSE_COINOR=1 -DCMAKE_SYSTEM_PREFIX_PATH="$ORTOOLSDIR" -Dabsl_DIR="$ORTOOLSDIR\lib\cmake\absl" -Dutf8_range_DIR="$ORTOOLSDIR\lib\cmake\utf8_range" -Dortools_DIR="$ORTOOLSDIR\lib\cmake\ortools" ../sam/api || exit
make -j 6 || exit

cd $PYSAMDIR

# Stage external files (libs, defaults) into PySAM/
/opt/python/cp312-cp312/bin/python prepare_build.py || exit

for PYTHONENV in cp39-cp39 cp310-cp310 cp311-cp311 cp312-cp312 cp313-cp313 cp314-cp314
do
   yes | /opt/python/$PYTHONENV/bin/pip install -r tests/requirements.txt
   yes | /opt/python/$PYTHONENV/bin/pip install auditwheel build
   yes | /opt/python/$PYTHONENV/bin/pip uninstall NREL-PySAM
   /opt/python/$PYTHONENV/bin/python -m build --wheel || exit
   WHEEL=$(ls dist/nrel_pysam-*-$PYTHONENV-*linux*.whl)
   auditwheel repair "$WHEEL" -w dist/wheelhouse/
   REPAIRED_WHEEL=$(ls dist/wheelhouse/nrel_pysam-*-$PYTHONENV-*linux*.whl)
   yes | /opt/python/$PYTHONENV/bin/pip install "$REPAIRED_WHEEL"
   /opt/python/$PYTHONENV/bin/python -m pytest -s tests/test_dispatch_optimization.py
   retVal=$?
   if [ $retVal -ne 0 ]; then
       echo "Error in Tests"
       exit 1
   fi
done

# Clean up staged files
/opt/python/cp312-cp312/bin/python prepare_build.py --clean
