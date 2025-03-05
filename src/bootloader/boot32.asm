; stolen from https://github.com/gmarino2048/64bit-os-tutorial/blob/master/Chapter%202/2.1%20-%20First%20Kernel/bootloader/boot.asm

bootsector_extended:
begin_protected:

[bits 32]

call clear_protected
call detect_lm_protected

mov esi, protected_alert
call print_protected

call init_pt_protected
call elevate_protected

jmp $

%include "src/bootloader/protected/clear.asm"
%include "src/bootloader/protected/print.asm"
%include "src/bootloader/protected/detect_lm.asm"
%include "src/bootloader/protected/init_pt.asm"
%include "src/bootloader/protected/gdt.asm"
%include "src/bootloader/protected/elevate.asm"

vga_start:                  equ 0x000B8000
vga_extent:                 equ 80 * 25 * 2             ; VGA Memory is 80 chars wide by 25 chars tall (one char is 2 bytes)
style_wb:                   equ 0x0F

; Define messages
protected_alert:                 db `64-bit long mode supported`, 0

; Fill with zeros to the end of the sector
times 512 - ($ - bootsector_extended) db 0x00