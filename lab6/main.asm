section .text 
      global main
      extern strcpy
      extern fopen
      extern sprintf
      extern fwrite
      extern memset
      extern fread
      extern printf
 
main:   push	ebp
	mov	ebp, esp
	sub esp,16            ;4 local vars
        mov DWORD[ebp-4],1        ;outputstartname                  
	mov ebx, DWORD[ebp+12]
	mov ebx,DWORD[ebx+4]
	push ebx
	push name
	call strcpy  
	push romode
        push name
	call fopen
	mov DWORD[ebp-8], eax                     ;ebp-8 === File read pointer
	jmp READ

WRITE: 
       push DWORD[ebp-4]
       push name
       push helper
       push oname
       call sprintf
       push wmode
       push oname
       call fopen
       mov DWORD[ebp-12],eax                    ;ebp-12 === File Write pointer
       push DWORD[ebp-12]
       push DWORD [ebp-16]
       push DWORD 1
       push DWORD buffer
       call fwrite
       add DWORD[ebp-4],1
       push DWORD 100
       push DWORD 0
       push buffer
       call memset

READ:   push DWORD [ebp-8]   
	push DWORD [maxbytes]
	push DWORD 1
	push buffer
	call fread
	mov DWORD[ebp-16],eax        ; ebp-16   === Num of bytes Read
	cmp eax, 0
	jne WRITE

END:    mov eax,0
	mov esp,ebp
	pop ebp
	ret




section .data

     romode db 'r',0
     wmode db 'w',0
     maxbytes dd 32
     helper db "%s.%d", 0

section .bss 
	 buffer resb 32
     name resb 50
     oname resb 50
