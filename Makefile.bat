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

set WINDIR=win
set BUILDDIR=build
set SRCDIR=src
set MAIN=main
set SRCFILESEXT=*.cpp *.c
set EXEC=program

set option=%1
echo    make %option%
echo.

IF [%option%]==[]       (call :MAKE)
IF [%option%]==[help]   (call :HELP)
IF [%option%]==[run]    (call :MAKE && call :RUN)
IF [%option%]==[clean]  (call :CLEAN)
goto END

REM **** RULES ****

:HELP
echo *****************************************************
echo ** ./Makefile.bat                                  **
echo **     Executes MAKE rule (compile and link)       **
echo ** ./Makefile.bat help                             **
echo **     Displays help informations                  **
echo ** ./Makefile.bat run                              **
echo **     Executes MAKE rule and run executable       **
echo ** ./Makefile.bat clean                            **
echo **     Delete /win and /build directories          **
echo *****************************************************
goto :EOF

:MAKE
IF NOT exist %WINDIR%   (md %WINDIR%)
IF NOT exist %BUILDDIR% (md %BUILDDIR%)
IF NOT exist %SRCDIR%   (md %SRCDIR%)
cd %SRCDIR%
set DEPENDANCIES=
for %%f in (%SRCFILESEXT%) do (
    echo    COMPILING %%f INTO %%~nf.o
    g++ -c %%f -o ../%WINDIR%/%%~nf.o
    if NOT [%%~nf]==[%MAIN%] (
        set DEPENDANCIES=!DEPENDANCIES!win/%%~nf.o 
    )
)
echo.
cd ..
echo    LINKING %BUILDDIR%/%EXEC%.exe FROM %WINDIR%/%MAIN%.o AND %DEPENDANCIES%
g++ -o %BUILDDIR%/%EXEC%.exe %WINDIR%/%MAIN%.o %DEPENDANCIES%
echo.
goto :EOF

:RUN
start %BUILDDIR%/%EXEC%.exe
goto :EOF

:CLEAN
IF exist %WINDIR%   (rmdir %WINDIR% /q /s)
IF exist %BUILDDIR% (rmdir %BUILDDIR% /q /s)
goto :EOF

:END
echo ===  MAKEFILE END  === 