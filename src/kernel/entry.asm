[bits 64]
[extern main]

section .text
global _start


; call main, loop when ret
_start:
    call main
    jmp $
