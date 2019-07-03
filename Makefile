# Компиляция и компоновка программы на JWasm
test: test.s
	jwasm -mf -Iinclude/unix -elf -Sa test.s 
	ld -o test -static -m elf_i386 --no-dynamic-linker test.o /usr/lib/i386-linux-musl/libc.a

clean:
	rm test.o test
