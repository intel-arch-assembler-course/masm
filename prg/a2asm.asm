;include ..\include\console.inc
.486
.model flat,stdcall
option casemap:none

.data
    public xasm2
xasm2 dd 555555
    extrn xp1:dword; xp1 из p1.pas

.code
    extern OutHex:near; OutHex из p1.pas
    public Q
Q   proc; uses eax ebx,x:dword,y:dword
    push ebp
    mov  ebp,esp
    push eax
    push ebx
x   equ  dword ptr [ebp+8]
y   equ  dword ptr [ebp+12]
    mov  eax,xp1; xp1 из p1.pas
    mov  eax,y
    add  eax,eax
    mov  ebx,x
    mov  [ebx],eax
    push dword ptr [ebp+12]
    call OutHex
    push xp1
    call OutHex
    pop  ebx
    pop  eax
    pop  ebp
    ret  8
Q   endp

    end
