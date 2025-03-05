begin_long_mode:

[bits 64]

mov rdi, style_blue
call clear_long

mov rdi, style_blue
mov rsi, long_mode_note
call print_long

call kernel_start

jmp $

%include "src/bootloader/long/clear.asm"
%include "src/bootloader/long/print.asm"

kernel_start:                   equ 0x8200              ; Kernel is at 1MB
long_mode_note:                 db `Longshot achieved.`, 0
style_blue:                     equ 0x1F

times 512 - ($ - begin_long_mode) db 0x00