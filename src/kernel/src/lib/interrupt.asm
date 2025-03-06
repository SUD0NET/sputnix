; 64-bit Compatible ISR Code

extern isr_handler

; Common ISR code (64-bit)
isr_common_stub:
    ; 1. Save CPU state (64-bit)
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi
    push rbp
    push r8
    push r9
    push r10
    push r11
    push r12
    push r13
    push r14
    push r15

    mov rax, ds ; Save data segment
    push rax

    mov rax, 0x10 ; Kernel data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; 2. Call C handler
    call isr_handler

    ; 3. Restore state
    pop rax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    pop r15
    pop r14
    pop r13
    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rbp
    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax

    add rsp, 16 ; Clean up pushed ISR number and error code (if any)

    iretq ; 64-bit return from interrupt

; ISRs (64-bit)
global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

isr0:
    cli
    push 0
    push 0
    jmp isr_common_stub

isr1:
    cli
    push 1
    push 0
    jmp isr_common_stub

isr2:
    cli
    push 2
    push 0
    jmp isr_common_stub

isr3:
    cli
    push 3
    push 0
    jmp isr_common_stub

isr4:
    cli
    push 4
    push 0
    jmp isr_common_stub

isr5:
    cli
    push 5
    push 0
    jmp isr_common_stub

isr6:
    cli
    push 6
    push 0
    jmp isr_common_stub

isr7:
    cli
    push 7
    push 0
    jmp isr_common_stub

isr8:
    cli
    push 8
    jmp isr_common_stub

isr9:
    cli
    push 9
    push 0
    jmp isr_common_stub

isr10:
    cli
    push 10
    jmp isr_common_stub

isr11:
    cli
    push 11
    jmp isr_common_stub

isr12:
    cli
    push 12
    jmp isr_common_stub

isr13:
    cli
    push 13
    jmp isr_common_stub

isr14:
    cli
    push 14
    jmp isr_common_stub

isr15:
    cli
    push 15
    push 0
    jmp isr_common_stub

isr16:
    cli
    push 16
    push 0
    jmp isr_common_stub

isr17:
    cli
    push 17
    push 0
    jmp isr_common_stub

isr18:
    cli
    push 18
    push 0
    jmp isr_common_stub

isr19:
    cli
    push 19
    push 0
    jmp isr_common_stub

isr20:
    cli
    push 20
    push 0
    jmp isr_common_stub

isr21:
    cli
    push 21
    push 0
    jmp isr_common_stub

isr22:
    cli
    push 22
    push 0
    jmp isr_common_stub

isr23:
    cli
    push 23
    push 0
    jmp isr_common_stub

isr24:
    cli
    push 24
    push 0
    jmp isr_common_stub

isr25:
    cli
    push 25
    push 0
    jmp isr_common_stub

isr26:
    cli
    push 26
    push 0
    jmp isr_common_stub

isr27:
    cli
    push 27
    push 0
    jmp isr_common_stub

isr28:
    cli
    push 28
    push 0
    jmp isr_common_stub

isr29:
    cli
    push 29
    push 0
    jmp isr_common_stub

isr30:
    cli
    push 30
    push 0
    jmp isr_common_stub

isr31:
    cli
    push 31
    push 0
    jmp isr_common_stub