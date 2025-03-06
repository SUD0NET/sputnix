#ifndef __CPU_PORTS
#define __CPU_PORTS

#include <types.h>

u8_t byte_in(u16_t port);
void byte_out(u16_t port, u8_t data);

unsigned char port_byte_in (unsigned short port);
void port_byte_out (unsigned short port, unsigned char data);
unsigned short port_word_in (unsigned short port);
void port_word_out (unsigned short port, unsigned short data);

#endif