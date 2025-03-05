[org 0x7C00]

; a LOT of code was written following the INCREDIBLY useful tutorial found here:
; https://github.com/gmarino2048/64bit-os-tutorial/tree/master
; therefore, some files are almost, or entierly line for line.
; this will be changed in the future (probably)
; but for now, it works as a bootloader, so it is here.
; below is the license for the bootloader.

; MIT License
;
; Copyright (c) 2020 Guy Marino, Steven Nyeo, Noah Houpt
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in all
; copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
; SOFTWARE.

jmp start_real
kernel_size db 0
start_real:

[bits 16]
mov bp, 0x0500
mov sp, bp

mov byte[boot_drive], dl
mov bx, 0x0002
mov cx, [kernel_size]
add cx, 2
mov dx, 0x7E00

call load_bios
call elevate_bios

bootsector_hold:
    jmp $

%include "src/bootloader/real/print.asm"
%include "src/bootloader/real/print_hex.asm"
%include "src/bootloader/real/load.asm"
%include "src/bootloader/real/gdt.asm"
%include "src/bootloader/real/elevate.asm"

; DATA
boot_drive: db 0x00

; PAD & MAGIC
times 510 - ($ - $$) db 0x00
dw 0xAA55

%include "src/bootloader/boot32.asm"
%include "src/bootloader/boot64.asm"