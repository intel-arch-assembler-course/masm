include inputstr.s

.data
	buf db 256 dup (0)

.code
public main
main:
	mov ebx, offset buf
	inputstr ebx,255
	mov ecx, 8
	push ecx
	mov ecx, offset buf
	push ecx
	mov ecx, 1
	push ecx
	call write
	xor eax, eax
	call exit
	end main
end
