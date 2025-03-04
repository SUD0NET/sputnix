[bits 32]
[extern kernel_main]

section .text
global start

start:
    cli                     ; no interrupts
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    call kernel_main        ; call the C kernel's main function (this does not seem to work :( )

hang:
    hlt
    jmp hang
