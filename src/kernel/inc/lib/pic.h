#ifndef PIC_H
#define PIC_H

#include <types.h>

// PIC ports
#define PIC1_CTRL 0x20 // Master PIC control port
#define PIC1_DATA 0x21 // Master PIC data port
#define PIC2_CTRL 0xA0 // Slave PIC control port
#define PIC2_DATA 0xA1 // Slave PIC data port

void pic_remap();
void pic_mask_all();
void pic_mask_irq(u8_t irq);
void pic_unmask_irq(u8_t irq);
void pic_send_eoi(u8_t irq);

#endif // PIC_H