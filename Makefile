# Компиляция и компоновка программы на JWasm
test:
    jwasm -mf -elf test.s
    ld -static -m elf_i386 --no-dynamic-linker test.o /usr/lib/i386-linux-musl/libc.a