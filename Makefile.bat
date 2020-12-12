@echo off
cls
echo === MAKEFILE BEGIN ===

set WINDIR=win
set BUILDDIR=build
set SRCDIR=src
set PROGRAMNAME=program

if NOT exist %WINDIR%   (md %WINDIR%)
if NOT exist %BUILDDIR% (md %BUILDDIR%)
if NOT exist %SRCDIR%   (md %SRCDIR%)

set option=%1
echo make %option%

g++ -c %SRCDIR%/main.cpp -o %WINDIR%/main.o 
g++ -o %BUILDDIR%/%PROGRAMNAME%.exe %WINDIR%/main.o

if %option%==run    (goto RUN)
if %option%==clean  (goto CLEAN)

:RUN
start %BUILDDIR%/%PROGRAMNAME%.exe
goto END

:CLEAN
cd %WINDIR%
del main.o
cd ..
cd %BUILDDIR%
del %PROGRAMNAME%.exe
cd ..
goto END

:END

echo ===  MAKEFILE END  === 