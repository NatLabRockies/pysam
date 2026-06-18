@ECHO OFF

REM requires environment variables for SAMNT, ORTOOLSDIR, PYSAMDIR, and SSCDIR 
REM optional "-version" argument of python version 3.9, 3.10, 3.11, 3.12, 3.13, or 3.14 can be specified
REM any other or no argument will result in all python versions to be built
REM optional "-tests" argument of "skip" will not run the tests in the "tests" folder
REM e.g. build_win.bat -python=3.12 -tests=skip to build python 3.12 wheel and skip running tests


REM do not persist variables for subsequent runs
SET version=""
SET python_version="pysam_build_3.9 pysam_build_3.10 pysam_build_3.11, pysam_build_3.12 pysam_build_3.13 pysam_build_3.14"
SET tests="run"

:loop
IF NOT "%1"=="" (
    IF "%1"=="-python" (
        SET version=%2
        SHIFT
    )
    IF "%1"=="-tests" (
        SET tests=%2
        SHIFT
    )
    SHIFT
    GOTO :loop
)
if "%version%"=="3.9" (
     SET python_version="pysam_build_3.9"
)
if "%version%"=="3.10" (
    SET python_version="pysam_build_3.10"
)
if "%version%"=="3.11" (
    SET python_version="pysam_build_3.11"
)
if "%version%"=="3.12" (
    SET python_version="pysam_build_3.12"
)
if "%version%"=="3.13" (
    SET python_version="pysam_build_3.13"
)
if "%version%"=="3.14" (
    SET python_version="pysam_build_3.14"
)

ECHO python = %python_version%
ECHO tests = %tests%


mkdir %SSCDIR%\..\build_pysam
cd %SSCDIR%\..\build_pysam

REM skip api_autogen since the files should not need to be regenerated
cmake -G "Visual Studio 17 2022" -DCMAKE_CONFIGURATION_TYPES="Release" -DSAM_SKIP_TOOLS=1 -DSAM_SKIP_TESTS=1 -DSAM_SKIP_AUTOGEN=0 -DSAMAPI_EXPORT=1 -DUSE_XPRESS=0 -DUSE_COINOR=1 -DCMAKE_SYSTEM_VERSION=10.0 -DCMAKE_SYSTEM_PREFIX_PATH="%ORTOOLSDIR%" -Dabsl_DIR="%ORTOOLSDIR%\lib\cmake\absl" -Dutf8_range_DIR="%ORTOOLSDIR%\lib\cmake\utf8_range" -Dortools_DIR="%ORTOOLSDIR%\lib\cmake\ortools" ..
devenv /build Release system_advisor_model.sln /Project SAM_api
if errorlevel 1 (
    echo Error in Build
    exit /b %errorlevel%
)

cd %PYSAMDIR%
echo y | rmdir build /s
echo y | del dist\*

REM Stage external files (libs, defaults) into PySAM\
python prepare_build.py
if errorlevel 1 (
    echo Error in prepare_build
    exit /b %errorlevel%
)

FOR %%i IN (%python_version%) DO (
	call conda deactivate
    call conda activate %%i
    echo y | pip install -r tests/requirements.txt
    echo y | pip install build
    echo y | pip uninstall NREL-PySAM
    pip install .
    if NOT "%tests%"=="skip" (
        pytest -s tests
    	if errorlevel 1 (
    	   echo Error in Tests
    	   exit /b %errorlevel%
    	)
    )
    python -m build --wheel
)
REM Clean up staged files
python prepare_build.py --clean
REM %bash% build_conda.sh
REM anaconda upload -u nrel dist/*.tar.bz2

REM only upload to PyPi after Github Actions test of new package passes
REM twine upload dist/*.whl

REM rmdir %SSCDIR%\..\build_pysam /s
