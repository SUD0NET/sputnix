// stolen from https://github.com/gmarino2048/64bit-os-tutorial/blob/master/Chapter%202/2.1%20-%20First%20Kernel/kernel/src/kernel.c

// WILL BE CHANGED
// THIS IS FOR TESTING ONLY

#define VGA_START 0xB8000
#define VGA_EXTENT 80 * 25
#define STYLE_WB 0x0F

typedef struct __attribute__((packed)) {
    char character;
    char style;
} vga_char;

volatile vga_char *TEXT_AREA = (vga_char*) VGA_START;

void clearwin(){
    vga_char clear_char = {
        .character=' ',
        .style=STYLE_WB
    };

    for(unsigned int i = 0; i < VGA_EXTENT; i++){
        TEXT_AREA[i] = clear_char;
    }
}

void putstr(const char *str){
    for(unsigned int i = 0; str[i] != '\0'; i++){
        if (i >= VGA_EXTENT)
            break;

        vga_char temp = {
            .character=str[i],
            .style=STYLE_WB
        };

        TEXT_AREA[i] = temp;
    }
}

int main(){
    clearwin();
    const char *welcome_msg = "IS THAT MINOS PRIME?!";
    putstr(welcome_msg);

    return 0;
}
