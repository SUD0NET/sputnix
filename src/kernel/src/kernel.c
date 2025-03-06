// stolen from https://github.com/gmarino2048/64bit-os-tutorial/blob/master/Chapter%202/2.1%20-%20First%20Kernel/kernel/src/kernel.c

// WILL BE CHANGED
// THIS IS FOR TESTING ONLY

#include <lib/vga.h>

int main() {
    set_cursor_pos(0, 0);
    clearwin(COLOR_BLK, COLOR_WHT);

    const char *first = "IS THAT MINOS PRIME?!";
    putstr(first, COLOR_BLK, COLOR_WHT);

    const char *second = "\nI THINK SO \n";
    putstr(second, COLOR_RED, COLOR_WHT);

    return 0;
}
