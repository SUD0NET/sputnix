/*#ifndef IDT_H
#define IDT_H

#include <types.h>

#define KERNEL_CS 0x08

typedef struct {
    u16_t low_offset;
    u16_t sel;
    u8_t always0;
    u8_t flags; 
    u16_t high_offset;
} __attribute__((packed)) idt_gate_t ;

typedef struct {
    u16_t limit;
    u64_t base;
} __attribute__((packed)) idt_register_t;

#define IDT_ENTRIES 256

void set_idt_gate(int n, u32_t handler);
void set_idt();

#endif
*/

#ifndef IDT_H
#define IDT_H

#include <types.h>

#define KERNEL_CS 0x08
#define IDT_ENTRIES 256

typedef struct {
    u16_t low_offset;
    u16_t sel;
    u8_t ist0 : 3;
    u8_t reserved0 : 5;
    u8_t flags;
    u16_t mid_offset;
    u32_t high_offset;
    u32_t reserved1;
} __attribute__((packed)) idt_gate_t;

typedef struct {
    u16_t limit;
    u64_t base;
} __attribute__((packed)) idt_register_t;

extern idt_gate_t idt[IDT_ENTRIES];
extern idt_register_t idt_reg;

void set_idt_gate(int n, u64_t handler); // Corrected to u64_t
void set_idt();

#endif