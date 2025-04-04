#include <lib/util.h>

void memory_copy(char *source, char *dest, int nbytes) {
    int i;
    
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8_t *dest, u8_t val, u32_t len) {
    u8_t *temp = (u8_t *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

void int_to_ascii(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';
}