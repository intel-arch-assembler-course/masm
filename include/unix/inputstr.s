;**********************************************************
; InputStr - ввод строки до ENTER, не длиннее Len
;            или до конца строки
;**********************************************************
inputstr equ InputStr
INPUTSTR equ InputStr
InputStr macro Buf:REQ,Len:=<128>,prompt:VARARG
     Local L,M1,M2
ifnb <prompt>
     outstr prompt
endif
     push   ecx
     push   edx
     push Len
     push Buf
     call StdIn
     pop Buf
     pop Len
     pop    edx
     pop    ecx
     push   ebx
     mov    ebx,Buf
     cmp    eax,0
     je     L
     cmp    byte ptr [ebx+eax-1],10;  CR,LF в буфере
     jne    M1
     sub    eax,2
     jmp    L
M1:  cmp    byte ptr [ebx+eax-1],13;  CR в буфере
     jne    L
     sub    eax,1
L:   mov    byte ptr [ebx+eax],0
     pop    ebx
endm
