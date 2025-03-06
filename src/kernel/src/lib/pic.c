#include <types.h>
#include <lib/ports.h>
#include <lib/pic.h>

// PIC ports
#define PIC1_CTRL 0x20 // Master PIC control port
#define PIC1_DATA 0x21 // Master PIC data port
#define PIC2_CTRL 0xA0 // Slave PIC control port
#define PIC2_DATA 0xA1 // Slave PIC data port

// Assuming your I/O functions are defined elsewhere
extern u8_t byte_in(u16_t port);
extern void byte_out(u16_t port, u8_t data);

// Function to add a small delay
static void io_wait() {
    byte_out(0x80, 0); // Short delay via port 0x80
    byte_out(0x80, 0);
    byte_out(0x80, 0);
    byte_out(0x80, 0);
}

// Remap the PICs
void pic_remap() {
    u8_t a1, a2;

    // Save masks
    a1 = byte_in(PIC1_DATA);
    a2 = byte_in(PIC2_DATA);

    // Start initialization sequence (ICW1)
    byte_out(PIC1_CTRL, 0x11); // ICW1: IC4=1 (ICW4 needed), single mode
    io_wait();
    byte_out(PIC2_CTRL, 0x11);
    io_wait();

    // ICW2: Master PIC vector offset (0x20)
    byte_out(PIC1_DATA, 0x20); // Master PIC vector offset = 32 (0x20)
    io_wait();

    // ICW2: Slave PIC vector offset (0x28)
    byte_out(PIC2_DATA, 0x28); // Slave PIC vector offset = 40 (0x28)
    io_wait();

    // ICW3: Master PIC IRQ2 -> Slave PIC
    byte_out(PIC1_DATA, 0x04); // Slave PIC at IRQ2
    io_wait();

    // ICW3: Slave PIC identity
    byte_out(PIC2_DATA, 0x02); // Slave PIC cascade identity
    io_wait();

    // ICW4: Environment info
    byte_out(PIC1_DATA, 0x01); // ICW4: x86 mode
    io_wait();
    byte_out(PIC2_DATA, 0x01);
    io_wait();

    // Restore saved masks
    byte_out(PIC1_DATA, a1);
    byte_out(PIC2_DATA, a2);
}

// Mask all IRQs, can be used for debugging, or as a starting point.
void pic_mask_all() {
    byte_out(PIC1_DATA, 0xFF);
    byte_out(PIC2_DATA, 0xFF);
}

// Mask a specific IRQ.
void pic_mask_irq(u8_t irq) {
  u16_t mask = 0xFFFF;

  if (irq < 8) {
    mask &= ~(1 << irq);
    byte_out(PIC1_DATA, mask & 0xFF);
  } else if (irq < 16) {
    mask &= ~(1 << (irq - 8));
    byte_out(PIC2_DATA, (mask >> 8) & 0xFF);
  }
}

// Unmask a specific IRQ.
void pic_unmask_irq(u8_t irq) {
  u16_t mask = 0xFFFF;

  if (irq < 8) {
    mask = byte_in(PIC1_DATA) | (1 << irq);
    byte_out(PIC1_DATA, mask);
  } else if (irq < 16) {
    mask = byte_in(PIC2_DATA) | (1 << (irq-8));
    byte_out(PIC2_DATA, mask);
  }
}

// Send EOI (End of Interrupt)
void pic_send_eoi(u8_t irq) {
    if (irq >= 8) {
        byte_out(PIC2_CTRL, 0x20); // Slave PIC
    }
    byte_out(PIC1_CTRL, 0x20); // Master PIC
}