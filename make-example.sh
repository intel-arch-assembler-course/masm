#!/bin/sh
: ${JWASM:=jwasm}
$JWASM -5 -mf -elf -Iinclude/unix/ example.s
gcc -m32 example.o -o example
