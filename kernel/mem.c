#include <stdbool.h>
#include <stdint.h>
#include "mem.h"
#include "../device_drivers/screen.h"
#include "utilities.h"

// Copies the number of bytes in memory denoted by nbytes from source to dest 
void memory_copy(uint8_t *source, uint8_t *dest, uint32_t nbytes) {
    for (int i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}