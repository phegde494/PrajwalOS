#include <stdint.h>

// Read byte from specified port
unsigned char port_byte_in(uint16_t port) {
    unsigned char result;

     // '"=a" (result)'; set '=' the C variable '(result)' to the value of register e'a'x
     // "d" (port)': map the C variable '(port)' into e'd'x register
     // Inputs and outputs separated by colons
    asm("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

// Output data from specified port
void port_byte_out(uint16_t port, uint8_t data) {
    asm("out %%al, %%dx" : : "a" (data), "d" (port));
}
