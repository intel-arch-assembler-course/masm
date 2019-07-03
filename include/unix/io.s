
extern _exit: near, fputc: near, _GLOBAL_OFFSET_TABLE_: dword, stdout@GOT :dword, fflush: near , got: dword

.code

_get_ecx_base proc
    mov     ecx, [esp]
    ret
_get_ecx_base endp

; Перевод строки
;
;newline equ NEWLINE
;Newline equ NEWLINE

;NEWLINE macro n:=<1>
;   repeat n
;        OUTCHAR 13    
;        OUTCHAR 10
;    endm
;endm


; Выход из программы
;
;Exit equ EXIT
;exit equ EXIT

EXIT macro x:=<0>
    call    _get_ecx_base
    add     ecx, offset _GLOBAL_OFFSET_TABLE_
    mov     eax, stdout@GOT[ecx]
    push    [eax]
    call fflush
    add  esp, 4

    push x
    call _exit
endm

; Вывод символа
;
OUTCHAR macro symb:req

        push    ecx
        call    _get_ecx_base
        add     ecx, offset _GLOBAL_OFFSET_TABLE_
        mov     eax, stdout@GOT[ecx]
        push    [eax]
        movzx   eax, symb
        push    eax
        call    fputc
        add     esp, 8
        pop     ecx

endm
