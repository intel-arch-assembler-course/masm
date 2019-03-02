extern read : proc
extern write : proc
extern exit : proc

.code
InputStr macro Buf:REQ,Len:=<128>,prompt:VARARG
	Local L,M1,M2
;ifnb <prompt>
;	outstr prompt
;endif
	push	ecx
	push	eax
	mov     eax, Len
	push	eax
	push	Buf
	mov	ecx, 0
	push	ecx
	call	read
	push	ebx
	mov	ebx,Buf
	cmp	eax,0
	je	L
	cmp	byte ptr [ebx+eax-1],10;  LF в буфере
	jne	M1
	sub	eax,1
M1:	cmp	byte ptr [ebx+eax-1],13;  CR в буфере
	jne	L
	sub	eax,1
L:	mov	byte ptr [ebx+eax],0
	pop	ebx
	pop	eax
	pop	ecx
endm
