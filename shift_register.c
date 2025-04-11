#include "shift_register.h"

static uint DATA_PIN, CLOCK_PIN, LATCH_PIN;

void shift_register_init(uint data_pin, uint clock_pin, uint latch_pin) {
    DATA_PIN = data_pin;
    CLOCK_PIN = clock_pin;
    LATCH_PIN = latch_pin;

    gpio_init(DATA_PIN);
    gpio_set_dir(DATA_PIN, GPIO_OUT);
    gpio_init(CLOCK_PIN);
    gpio_set_dir(CLOCK_PIN, GPIO_OUT);
    gpio_init(LATCH_PIN);
    gpio_set_dir(LATCH_PIN, GPIO_OUT);
}

void shift_register_write(uint8_t data) {
    gpio_put(LATCH_PIN, 0);
    for (int i = 7; i >= 0; i--) {
        gpio_put(CLOCK_PIN, 0);
        gpio_put(DATA_PIN, (data >> i) & 1);
        gpio_put(CLOCK_PIN, 1);
    }
    gpio_put(LATCH_PIN, 1);
}
