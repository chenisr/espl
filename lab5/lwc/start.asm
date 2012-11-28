section .text
	
global _start
global read
global write
global open
global close
global strlen

extern main
_start:
        mov ecx,esp
	add ecx,4
	push ecx
        push [esp+4]
	call	main
        mov     ebx,eax
	mov	eax,1
	int 0x80

read: 
       mov eax,3
       mov ebx, DWORD [esp+4]
       mov ecx, DWORD [esp+8]
       mov edx, DWORD [esp+12]
       int 0x80
       ret

write:
       mov eax,4
       mov ebx, DWORD [esp+4]
       mov ecx, DWORD [esp+8]
       mov edx, DWORD [esp+12]
       int 0x80
       ret

open:
       mov eax,5
       mov ebx, DWORD [esp+4]
       mov ecx, DWORD [esp+8]
       mov edx, DWORD [esp+12]
       int 0x80
       ret

close:
       mov eax,6
       mov ebx, DWORD [esp+4]
       int 0x80
       ret


strlen:
       mov eax,DWORD [esp+4]
       movzx	eax, BYTE [eax]
       mov [esp-4],0
       sub esp. 4

.TEST: test al,al
       je .END
       add DWORD [esp+4],1
       add DWORD [esp-4],1
       mov eax,DWORD [esp+4]
       movzx	eax, BYTE [eax]
       jmp .TEST

.END:  mov eax, DWORD [esp-4]
       add esp,4
       ret
