/*#include <lib/idt.h>
#include <lib/util.h>

idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, u32_t handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; 
    idt[n].high_offset = high_16(handler);
}

void set_idt() {
    idt_reg.base = (u64_t) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    // Don't make the mistake of loading &idt -- always load &idt_reg 
    __asm__ __volatile__("lidtq (%0)" : : "r" (&idt_reg));
}*/


#include <lib/idt.h>
#include <lib/util.h>

idt_gate_t idt[IDT_ENTRIES];
idt_register_t idt_reg;

void set_idt_gate(int n, u64_t handler) { // handler is now u64_t
    idt[n].low_offset = handler & 0xFFFF;
    idt[n].sel = KERNEL_CS;
    idt[n].ist0 = 0; // Interrupt Stack Table
    idt[n].reserved0 = 0;
    idt[n].flags = 0x8E; // Present, Ring 0, Interrupt Gate
    idt[n].mid_offset = (handler >> 16) & 0xFFFF;
    idt[n].high_offset = (handler >> 32) & 0xFFFFFFFF;
    idt[n].reserved1 = 0;
}

void set_idt() {
    idt_reg.base = (u64_t) &idt;
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;
    __asm__ __volatile__("lidtq (%0)" : : "r" (&idt_reg));
}