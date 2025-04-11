#include <stdio.h>
#include "pico/stdlib.h"
#include "shift_register/shift_register.h"

int main() {
    stdio_init_all();
    shift_register_init(4, 2, 3); // DS=4, SH_CP=2, ST_CP=3

    while (1) {
        for (uint8_t i = 0; i < 255; i++) {
            shift_register_write(i);
            sleep_ms(200);
        }
    }
    return 0;
}
