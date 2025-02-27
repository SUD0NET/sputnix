[org 0x7c00]

; USSR Bootloader
; Features: Menu system, keyboard input, memory map display

    mov ah, 0x0e           ; BIOS teletype output
    mov bx, msg_booting    ; Load boot message
    call puts              ; Print message

menu_loop:
    mov bx, menu_text      ; Print menu
    call puts
    call get_key           ; Get user input
    cmp al, '1'            ; Option 1: Boot UKERN
    je boot_ukern
    cmp al, '2'            ; Option 2: Display memory map
    je show_mem_map
    jmp menu_loop          ; Loop for invalid input

boot_ukern:
    mov bx, msg_ukern      ; Print booting UKERN
    call puts
    jmp $

show_mem_map:
    mov bx, msg_mem_map    ; Print memory map header
    call puts
    int 0x15               ; Get memory map (BIOS interrupt)
    jmp menu_loop

puts:
    mov al, [bx]           ; Load character
    cmp al, 0              ; Check for null terminator
    je return
    int 0x10               ; Print character
    inc bx
    jmp puts
return:
    ret

get_key:
    mov ah, 0x00           ; BIOS keyboard input
    int 0x16               ; Get keystroke
    ret

msg_booting: db "USSR Bootloader v1.0", 0
menu_text:   db "\n1. Boot UKERN\n2. Show Memory Map\nSelect: ", 0
msg_ukern:   db "\nBooting UKERN...", 0
msg_mem_map: db "\nMemory Map:\n", 0

times 510-($-$$) db 0
    db 0x55, 0xaa
