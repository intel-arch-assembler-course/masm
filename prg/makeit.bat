@echo off

  set Name=a1
  set path=..\bin;..\..\bin
  set include=..\include;..\..\include
  set lib=..\lib;..\..\lib

  ml /c /coff /Fl %Name%.asm
  if errorlevel 1 goto errasm

Rem  Link /?
  Link /subsystem:console ^
       /section:.text,W /section:.bss,E /section:.data,RWE ^
       %Name%.obj a2.obj 

  if errorlevel 1 goto errlink

  %Name%.exe Par1,Par2
  goto TheEnd

:errlink
  echo Link Error !!!!!!!!!!!!!!!!!
  goto TheEnd

:errasm
  echo Assembler Error !!!!!!!!!!!!
  goto TheEnd

:TheEnd

pause
