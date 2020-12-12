REM ***********************************************
REM @file Makefile.bat
REM @author XAVIER DUPUIS (xavier0978@hotmail.fr)
REM @brief 
REM @version 0.1
REM @date 2020-12-12
REM 
REM @copyright Copyright (c) 2020
REM ***********************************************

@echo off
cls
title Makefile
echo === MAKEFILE BEGIN ===
echo.

set WINDIR=win
set BUILDDIR=build
set SRCDIR=src
set MAIN=main
set SRCFILESEXT=*.cpp *.c
set PROGRAMNAME=program


set option=%1
echo    make %option%
echo.

IF [%option%]==[]       (call :MAKE)
IF [%option%]==[run]    (call :MAKE && call :RUN)
IF [%option%]==[clean]  (call :CLEAN)
goto END

:MAKE
IF NOT exist %WINDIR%   (md %WINDIR%)
IF NOT exist %BUILDDIR% (md %BUILDDIR%)
IF NOT exist %SRCDIR%   (md %SRCDIR%)
cd %SRCDIR%
for %%f in (%SRCFILESEXT%) do (
    echo    Compiled %%f into %%~nf.o
    g++ -c %%f -o ../%WINDIR%/%%~nf.o
    )
echo.
cd ..
g++ -o %BUILDDIR%/%PROGRAMNAME%.exe %WINDIR%/%MAIN%.o
echo    Linked %PROGRAMNAME%.exe from %MAIN%.o
echo.
goto :EOF

:RUN
start %BUILDDIR%/%PROGRAMNAME%.exe
goto :EOF

:CLEAN
IF exist %WINDIR%   (rmdir %WINDIR% /q /s)
IF exist %BUILDDIR% (rmdir %BUILDDIR% /q /s)
goto :EOF

:END
echo ===  MAKEFILE END  === 