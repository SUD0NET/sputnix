#ifndef __DRIVER_VGA_TEXT
#define __DRIVER_VGA_TEXT

#include <types.h>

#define VGA_START 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_EXTENT 80 * 25

#define COLOR_BLK 0     // black
#define COLOR_BLU 1     // blue
#define COLOR_GRN 2     // green
#define COLOR_CYN 3     // cyan
#define COLOR_RED 4     // red
#define COLOR_PRP 5     // purple
#define COLOR_BRN 6     // brown
#define COLOR_GRY 7     // gray
#define COLOR_DGY 8     // dark gray
#define COLOR_LBU 9     // light blue
#define COLOR_LGR 10    // light green
#define COLOR_LCY 11    // light cyan
#define COLOR_LRD 12    // light red
#define COLOR_LPP 13    // light purple
#define COLOR_YEL 14    // yellow
#define COLOR_WHT 15    // white

#define CURSOR_PORT_COMMAND     (u16_t) 0x3D4
#define CURSOR_PORT_DATA        (u16_t) 0x3D5

#define STYLE_WB 0x0F

typedef struct __attribute__((packed)) {
    char character;
    char style;
} vga_char;

u8_t vga_color(const u8_t fg_color, const u8_t bg_color);

u16_t get_cursor_pos();
void show_cursor();
void hide_cursor();
void advance_cursor();
void reverse_cursor();
void set_cursor_pos(u8_t x, u8_t y);
void scroll_line();

void clearwin(const u8_t fg_color, const u8_t bg_color);
void putchar(const char character, const u8_t fg_color, const u8_t bg_color);
void putstr(const char *string, const u8_t fg_color, const u8_t bg_color);
void puts(const char *string);

#endif