@ECHO OFF

set version=""
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

if NOT "%tests%"=="skip" (
    pytest -s tests
    if errorlevel 1 (
       echo Error in Tests
       exit /b %errorlevel%
    )
)
