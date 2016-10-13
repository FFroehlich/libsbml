@echo off 
Setlocal EnableDelayedExpansion
SET THIS_DIR=%~dp0
SET LIBSBML_SRC=%THIS_DIR%\..\..\..\
SET BUILD_DIR=%THIS_DIR%\build_32
SET NAME=python-libsbml

pushd %THIS_DIR%\python-src

:: configure files
cmake -DSRC_DIR=%LIBSBML_SRC% -DBUILD_DIR=%BUILD_DIR% -DOUT_DIR=%THIS_DIR%\out -DNAME=%NAME% -P configure-files.cmake

:: create builds for different python versions
:: build in parallel (means that installers | wheels have to be created later)
start buildV.bat 2 5 BUILD EXIT_WHEN_DONE
start buildV.bat 2 6 BUILD EXIT_WHEN_DONE
call buildV.bat 2 7 BUILD 
start buildV.bat 3 1 BUILD EXIT_WHEN_DONE
start buildV.bat 3 2 BUILD EXIT_WHEN_DONE
start buildV.bat 3 3 BUILD EXIT_WHEN_DONE
start buildV.bat 3 4 BUILD EXIT_WHEN_DONE
call buildV.bat 3 5 BUILD

if not exist %THIS_DIR%\dist mkdir %THIS_DIR%\dist

:: wheels
call buildV.bat 2 7 WHEEL
call buildV.bat 3 3 WHEEL
call buildV.bat 3 4 WHEEL
call buildV.bat 3 5 WHEEL
move dist\*.whl %THIS_DIR%\dist

:: create installers and wheels
call buildV.bat 2 5 INSTALLER
call buildV.bat 2 6 INSTALLER
call buildV.bat 2 7 INSTALLER
call buildV.bat 3 1 INSTALLER
call buildV.bat 3 2 INSTALLER
call buildV.bat 3 3 INSTALLER
call buildV.bat 3 4 INSTALLER
call buildV.bat 3 5 INSTALLER

move dist\*.exe %THIS_DIR%\dist

popd