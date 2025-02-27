[org 0x7c00]

; example usage of proc "puts"
mov ah,0x0e
mov bx,stxt

puts:
	mov al,[bx]
	cmp al,0
	je end
	int 0x10 ; print to screen intrpt
	inc bx
	jmp puts
	
end:
	; just loop bc why not
	jmp $

stxt:
	db "BOOTING (UKERN)", 0 ; 0 terminates string

times 510-($-$$) db 0
db 0x55, 0xaa
