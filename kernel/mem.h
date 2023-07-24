#pragma once

#include <stdint.h>
#include <stddef.h>

#define NULL_POINTER ((void*)0)

void memory_copy(uint8_t *source, uint8_t *dest, uint32_t nbytes);
