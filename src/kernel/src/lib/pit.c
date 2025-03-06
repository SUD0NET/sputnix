#include <types.h>
#include <lib/ports.h>
#include <lib/vga.h>

#define PIT_FREQUENCY 1193182
#define TIMER_FREQUENCY 1000 // 1000Hz

#define PIT_COMMAND_PORT 0x43
#define PIT_CHANNEL_0_PORT 0x40

// func that is called
// oid timer_callback();

volatile u64_t tick_count = 0;

void timer_callback();

void timer_handler() {
    tick_count++;
    timer_callback();
}

// Initialize the PIT
void timer_init() {
    u16_t divisor = (u16_t)(PIT_FREQUENCY / TIMER_FREQUENCY);

    // Send command to PIT
    byte_out(PIT_COMMAND_PORT, 0x36);  // Set mode: Binary, Mode 3 (square wave), Channel 0

    // Send frequency divisor (low byte, then high byte)
    byte_out(PIT_CHANNEL_0_PORT, (u8_t)(divisor & 0xFF));
    byte_out(PIT_CHANNEL_0_PORT, (u8_t)((divisor >> 8) & 0xFF));
}

void timer_callback() {
    puts("Tick tock");
}

/*int main() {
    

    // __asm__ volatile("sti");

    while (1 == 1) {

    }

    return 0;
}*/
