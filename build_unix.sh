#!/bin/sh

#
# Building for Mac
#

# Building libssc and libSAM_api
# requires SAM-Dev/CMakeList.txt that contains lk, wex, ssc and sam as subdirectories

rm -rf ${SAMNTDIR}/../cmake-build-release
mkdir -p ${SAMNTDIR}/../cmake-build-release
cd ${SAMNTDIR}/../cmake-build-release || exit

if [ "$(python3 -c "import platform; print(platform.processor())")" = "arm" ]
then
    cmake -DCMAKE_BUILD_TYPE=Release \
    -DSAM_SKIP_AUTOGEN=0 -DSAMAPI_EXPORT=1 \
    -DUSE_XPRESS=0 -DUSE_COINOR=1 -DCMAKE_SYSTEM_PREFIX_PATH="$ORTOOLSDIR" \
    -Dabsl_DIR="$ORTOOLSDIR/lib/cmake/absl" -Dutf8_range_DIR="$ORTOOLSDIR/lib/cmake/utf8_range" \
    -Dortools_DIR="$ORTOOLSDIR/lib/cmake/ortools" ..
else
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_DEPLOYMENT_TARGET=12 \
    -DCMAKE_OSX_SYSROOT=/Library/Developer/CommandLineTools/SDKs/MacOSX15.4.sdk \
    -DCMAKE_CXX_FLAGS="-isystem /Library/Developer/CommandLineTools/SDKs/MacOSX15.4.sdk/usr/include/c++/v1" \
    -DSAM_SKIP_AUTOGEN=1 -DSAMAPI_EXPORT=1 \
    -DUSE_XPRESS=0 -DUSE_COINOR=1 -DCMAKE_SYSTEM_PREFIX_PATH="$ORTOOLSDIR" \
    -Dabsl_DIR="$ORTOOLSDIR/lib/cmake/absl" -Dutf8_range_DIR="$ORTOOLSDIR/lib/cmake/utf8_range" \
    -Dortools_DIR="$ORTOOLSDIR/lib/cmake/ortools" ..
fi
cmake --build . --target SAM_api -j 6

# Building the PyPi and Anaconda packages
# requires Anaconda installed with an environment per Python version from 3.6 to 3.10
# named pysam_build_3.6 pysam_build_3.7 pysam_build_3.8, etc

cd $PYSAMDIR || exit
source $(conda info --base)/etc/profile.d/conda.sh
rm -rf build
rm -rf dist/*

for PYTHONENV in pysam_build_3.9 pysam_build_3.10 pysam_build_3.11 pysam_build_3.12 pysam_build_3.13 pysam_build_3.14
do
   conda activate $PYTHONENV
   yes | pip install -r tests/requirements.txt
   yes | pip uninstall NREL-PySAM
   python setup.py install || exit
   pytest -s tests
   retVal=$?
   if [ $retVal -ne 0 ]; then
       echo "Error in Tests"
       exit 1
   fi
   python setup.py bdist_wheel
done

# yes | $PYSAMDIR/build_conda.sh || exit

#
# Building for Manylinux1
#

cd ..
if [ "$(python3 -c "import platform; print(platform.processor())")" = "arm" ]
then
    docker pull quay.io/pypa/manylinux_2_28_aarch64
    # docker run --rm -dit -v $(pwd):/io quay.io/pypa/manylinux_2_28_aarch64 /bin/bash
    docker run --rm -v $(pwd):/io quay.io/pypa/manylinux_2_28_aarch64 /io/pysam/build_manylinux.sh || exit
else
    docker pull quay.io/pypa/manylinux_2_28_x86_64
    # docker run --rm -dit -v $(pwd):/io quay.io/pypa/manylinux_2_28_x86_64 /bin/bash
    docker run --rm -v $(pwd):/io quay.io/pypa/manylinux_2_28_x86_64 /io/pysam/build_manylinux.sh || exit
fi

rename -s linux manylinux2014 $PYSAMDIR/dist/*-linux_*
docker pull continuumio/anaconda3
docker run --rm --env PYSAMDIR=/io/pysam -v $(pwd):/io continuumio/anaconda3 /io/pysam/build_conda.sh

# anaconda upload -u nrel $PYSAMDIR/dist/osx-64/*.tar.bz2
# anaconda upload -u nrel $PYSAMDIR/dist/linux-64/*.tar.bz2

# only upload to PyPi after Github Actions test of new package passes
# twine upload $PYSAMDIR/dist/*.whl

