#include <lib/vga.h>
#include <lib/util.h>
#include <lib/isr.h>
#include <lib/idt.h>
#include <lib/pic.h>
#include <lib/ports.h>
// #include <lib/pit.h>

void program() {
    while (1==1) {
        // volatile int xyz = 0;
    }
}

//char waitkey() { 
   // char k;
    // while ((k=byte_in(0x60))<128);
    // while (byte_in(0x60)>128);
//}

int main() {
    //timer_init();

    set_cursor_pos(0, 0);
    clearwin(COLOR_BLK, COLOR_WHT);

    puts("+-------------------------------------+\n");

    puts("|\tRemapping PIC... ");
    pic_remap();
    puts("done \t\t|\n");

    puts("|\tInstalling ISR... ");
    isr_install();
    puts("done\t\t|\n");

    puts("|\tMasking Interrupts... ");
    pic_mask_all(); // mask the error, pretending it is not there
    puts("done \t|\n");
    // only unmask required interrupts, remask when done

    // __asm__ volatile("sti");

    puts("+-------------------------------------+\n");
    const char *first = "IS THAT MINOS PRIME?!\n";
    putstr(first, COLOR_BLK, COLOR_WHT);

    //waitkey();
    //puts("ok.\n");

    //const char *second = "\nI THINK SO \n";
    //putstr(second, COLOR_RED, COLOR_WHT);

    /*__asm__ volatile("int $0");
    __asm__ volatile("int $1");
    __asm__ volatile("int $2");
    __asm__ volatile("int $3");
    __asm__ volatile("int $4");
    __asm__ volatile("int $5");
    __asm__ volatile("int $6");
    __asm__ volatile("int $7");
    __asm__ volatile("int $8");*/
    //__asm__ volatile("int $13");
    // __asm__ volatile("int $10");
    puts("Entering MainLOOP...\n");
    program();
    // 


    return 0;
}


/*#include <lib/vga.h>
#include <lib/util.h>
#include <lib/isr.h>
#include <lib/idt.h>

void dump_idt() { // Function to dump IDT
    puts("IDT Dump:\n");
    for (int i = 0; i < IDT_ENTRIES; i++) {
        idt_gate_t gate = idt[i];
        char s[20];
        int_to_ascii(gate.low_offset, s);
        puts("Gate ");
        int_to_ascii(i, s);
        puts(s);
        puts(": Low=");
        int_to_ascii(gate.low_offset, s);
        puts(s);
        puts(", Mid=");
        int_to_ascii(gate.mid_offset, s);
        puts(s);
        puts(", High=");
        int_to_ascii(gate.high_offset, s);
        puts("\n");
    }
}

extern void isr2();
extern void isr3();

int main() {
    isr_install();
    set_cursor_pos(0, 0);
    clearwin(COLOR_BLK, COLOR_WHT);

    const char *first = "IS THAT MINOS PRIME?!";
    putstr(first, COLOR_BLK, COLOR_WHT);

    const char *second = "\nI THINK SO \n";
    putstr(second, COLOR_RED, COLOR_WHT);

    puts("hi\n");

    // Debugging: Print addresses of ISRs
    char s[20];
    puts("ISR2 addr: ");
    int_to_ascii((u64_t)isr2, s);
    puts(s);
    puts("\nISR3 addr: ");
    int_to_ascii((u64_t)isr3, s);
    puts(s);
    puts("\n");

    dump_idt(); // Dump the IDT

    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");

    while (1 == 1) {
    }

    return 0;
}*/