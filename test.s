include io.s

public _start

    .code
_start:
        mov al, 'Z'
        OUTCHAR al
        EXIT
end
