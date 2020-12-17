@echo off
REM COMMENT PREVIOUS LINE FOR DEBUGGING PERSPECTIVE

REM ***********************************************
REM @file Makefile.bat
REM @author XAVIER DUPUIS (xavier0978@hotmail.fr)
REM @brief 
REM @version 0.1
REM @date 2020-12-12
REM 
REM @copyright Copyright (c) 2020
REM ***********************************************

setLocal EnableDelayedExpansion 
cls
title Makefile
echo === MAKEFILE BEGIN ===
echo.

set SRC_DIR=src
set BIN_DIR=bin
set BUILD_DIR=build
set MAIN=main
set SRCFILESEXT=*.cpp *.c
set EXEC=program.exe

set option=%1
echo    make %option%
echo.

IF [%option%]==[]       (call :MAKE)
IF [%option%]==[help]   (call :HELP)
IF [%option%]==[start]  (call :MAKE && call :START)
IF [%option%]==[run]    (call :MAKE && call :RUN)
IF [%option%]==[clean]  (call :CLEAN)
goto END

REM **** RULES ****

:HELP
echo ***********************************************************
echo ** ./Makefile.bat                                        **
echo **     Executes MAKE rule (compile and link)             **
echo **                                                       **
echo ** ./Makefile.bat help                                   **
echo **     Displays help informations                        **
echo **                                                       **
echo ** ./Makefile.bat start                                  **
echo **     Executes MAKE rule and start in single window     **
echo **                                                       **
echo ** ./Makefile.bat run                                    **
echo **     Executes MAKE rule and run executable in console  **
echo **                                                       **
echo ** ./Makefile.bat clean                                  **
echo **     Delete /bin and /build directories                **
echo ***********************************************************
goto :EOF

:MAKE
IF NOT exist %BIN_DIR%   (md %BIN_DIR%)
IF NOT exist %BUILD_DIR% (md %BUILD_DIR%)
IF NOT exist %SRC_DIR%   (md %SRC_DIR%)
cd %SRC_DIR%
set DEPENDANCIES=
for %%f in (%SRCFILESEXT%) do (
    echo    COMPILING %%f INTO %%~nf.o
    g++ -c %%f -o ../%BIN_DIR%/%%~nf.o
    if NOT [%%~nf]==[%MAIN%] (
        set DEPENDANCIES=!DEPENDANCIES!%BIN_DIR%/%%~nf.o 
    )
)
echo.
cd ..
echo    LINKING %BUILD_DIR%/%EXEC% FROM %BIN_DIR%/%MAIN%.o AND %DEPENDANCIES%
g++ -o %BUILD_DIR%/%EXEC% %BIN_DIR%/%MAIN%.o %DEPENDANCIES%
echo.
goto :EOF

:START
start %BUILD_DIR%/%EXEC%
goto :EOF

:RUN
.\%BUILD_DIR%\%EXEC%
goto :EOF

:CLEAN
IF exist %BIN_DIR%   (rmdir %BIN_DIR% /q /s)
IF exist %BUILD_DIR% (rmdir %BUILD_DIR% /q /s)
goto :EOF

:END
echo ===  MAKEFILE END  === 