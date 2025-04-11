#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

#include "pico/stdlib.h"

void shift_register_init(uint data_pin, uint clock_pin, uint latch_pin);
void shift_register_write(uint8_t data);

#endif
