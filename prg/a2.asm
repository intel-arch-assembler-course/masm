;include ..\include\console.inc
.486
.model flat,stdcall
option casemap:none

    public NN
NN  equ    100

.data
    public xa2
xa2 dd 555555
    extrn za1:dword; za1 из a1.asm

.code
    public Q
Q   proc uses eax ebx, x:dword,y:dword
    local z:dword 
; автоматически вставляются команды:
;    push ebp
;    mov  ebp,esp
;    sub  esp,4; local z:dword = [ebp-4]
;    push eax
;    push ebx
; действуют неявные директивы:
;z   equ  dword ptr [ebp-4]
;x   equ  dword ptr [ebp+8]
;y   equ  dword ptr [ebp+12]
    mov  eax,za1; za1 из a1.asm
    mov  eax,y
    add  eax,eax
    mov  ebx,x
    mov  [ebx],eax
    inc  eax

; перед ret автоматически вставляются команды:

;    pop  ebx; 5B
;    pop  eax; 58
;    mov  esp,ebp; 8B E5  уничтожение local z:dword
;    pop  ebp; 5D
;    ret  8;   C2 00 08

    ret;  8
Q   endp

    public QQ@8
QQ@8  proc; eax:=-111
    push ebp
    mov  ebp,esp
    mov  eax,-111
    pop  ebp
    ret
QQ@8  endp

    end
