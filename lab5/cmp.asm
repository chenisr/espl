section .text
	global cmpstr
cmpstr:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	mov eax,DWORD [ebp+8]
        movzx	eax, BYTE [eax]
	mov ebx,DWORD [ebp+12]
        movzx	ebx, BYTE [ebx]
.L1:    
	cmp eax,ebx
	jne .DIF
	add   DWORD [ebp+8], 1
        add	DWORD [ebp+12], 1
	mov eax,DWORD [ebp+8]
        movzx	eax, BYTE [eax]
	mov ebx,DWORD [ebp+12]
        movzx	ebx, BYTE [ebx]
	test al,al
	je .DIF
	test bl,bl
	je .DIF
	jmp .L1

.DIF: 
        cmp eax,ebx
        jg .GR
        jl .SM
        je .EQ
      
.EQ:
        mov eax,0
        jmp .END

.GR:    
	mov eax,1
        jmp .END

.SM:    
	mov eax,2
        jmp .END

.END:   mov esp, ebp
        pop ebp
        ret
