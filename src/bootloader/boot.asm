[org 0x7c00]               ; Bootloader starts at 0x7c00

; Print boot message
    mov ah, 0x0e           ; BIOS teletype output
    mov si, msg_booting    ; Load boot message pointer
.print:
    lodsb                  ; Load string byte into AL
    or al, al              ; Check for null terminator
    jz .menu               ; If null, jump to menu
    int 0x10               ; Print character
    jmp .print

.menu:
    ; Load kernel
    mov ax, 0x1000         ; load kernel at address 0x1000
    mov es, ax             ; set extra segment to 0x1000
    xor bx, bx             ; offset within the segment
    mov ah, 0x02           ; BIOS read function
    mov al, 1              ; number of sectors to read
    mov ch, 0              ; cylinder 0
    mov dh, 0              ; head 0
    mov cl, 2              ; sector 2 (kernel start)
    int 0x13               ; BIOS interrupt to read disk
    jc .error              ; jump if carry flag is set

    ;mov bx, msg_jumping
	;call puts
    
    ; Jump to kernel
    jmp 0x1000:0x0000      ; segment:Offset of kernel

.error:
    mov si, msg_error      ; Load error message pointer
    call puts              ; Print error message
    hlt                    ; Halt CPU

puts:
    lodsb                  ; Load string byte into AL
    or al, al              ; Check for null terminator
    jz .done               ; If null, return
    mov ah, 0x0e           ; BIOS teletype output
    int 0x10               ; Print character
    jmp puts
.done:
    ret

msg_booting db "Booting kernel...", 0
msg_error   db "Error loading kernel!", 0
msg_jumping db "jumping ", 0

; Bootloader signature
times 510-($-$$) db 0
dw 0xaa55
