#ifndef UTIL_H
#define UTIL_H

#include <types.h>

void memory_copy(char *source, char *dest, int nbytes);
void memory_set(u8_t *dest, u8_t val, u32_t len);
void int_to_ascii(int n, char str[]);

#endif