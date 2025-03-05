[bits 32]

init_pt_protected:
    pushad
    mov edi, 0x1000
    mov cr3, edi
    xor eax, eax
    mov ecx, 4096
    rep stosd

    mov edi, cr3

    ; https://github.com/gmarino2048/64bit-os-tutorial/blob/master/Chapter%202/2.1%20-%20First%20Kernel/bootloader/protected_mode/init_pt.asm
    ; copy paste job with comments:
    mov dword[edi], 0x2003      ; Set PML4T[0] to address 0x2000 (PDPT) with flags 0x0003
    add edi, 0x1000             ; Go to PDPT[0]
    mov dword[edi], 0x3003      ; Set PDPT[0] to address 0x3000 (PDT) with flags 0x0003
    add edi, 0x1000             ; Go to PDT[0]
    mov dword[edi], 0x4003      ; Set PDT[0] to address 0x4000 (PT) with flags 0x0003

    ; Fill in the final page table
    ; NOTE: edi is at 0x3000
    add edi, 0x1000             ; Go to PT[0]
    mov ebx, 0x00000003         ; EBX has address 0x0000 with flags 0x0003
    mov ecx, 512                ; Do the operation 512 times

    add_page_entry_protected:
        mov dword[edi], ebx
        add ebx, 0x1000
        add edi, 8
        loop add_page_entry_protected

    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    popad
    ret