@echo off

  set Name=io_proc
  set path=..\bin;..\..\bin
  set include=..\include;..\..\include
  set lib=..\lib;..\..\lib

  ml /c /coff /Fl /Sn %Name%.asm

  LIB /OUT:io_proc.lib io_proc.obj

  if errorlevel 1 goto errasm

  goto TheEnd

:errasm
  echo Assembler Error !!!!!!!!!!!!
  goto TheEnd

:TheEnd

pause
