.NOLIST
.NOLISTMACRO

.586
.model flat,stdcall
option casemap:none
;option casemap:all
;option casemap:notpublic

;option proc:private

.stack 4096

   include io.inc
;include masm32.inc

   includelib masm32.lib
   includelib user32.lib
   includelib kernel32.lib
   includelib msvcrt.lib
   includelib io_proc.lib
   
