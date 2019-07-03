# Компиляция и компоновка программы на JWasm

test: test.o
	ld -o test  -m elf_i386 --dynamic-linker=/lib32/ld-linux.so.2  test.o -lc
#	ld -o test -static -m elf_i386 --no-dynamic-linker test.o /usr/lib/i386-linux-musl/libc.a

test.o: test.s
	jwasm -mf -Iinclude/unix -elf -Sa test.s 

clean:
	rm test.o test
