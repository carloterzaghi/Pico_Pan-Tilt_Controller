#include <stdio.h>
#include "pico/stdlib.h"
#include "stepper.h"

void motor_init(int en_pin, int step_pin, int dir_pin) {
    gpio_init(en_pin);
    gpio_set_dir(en_pin, GPIO_OUT);
    gpio_put(en_pin, 0); // Habilita o driver (LOW)

    gpio_init(step_pin);
    gpio_set_dir(step_pin, GPIO_OUT);
    gpio_put(step_pin, 0);

    gpio_init(dir_pin);
    gpio_set_dir(dir_pin, GPIO_OUT);
    gpio_put(dir_pin, 0);
}

void motor_move_steps(int steps, bool direction, int step_pin, int dir_pin) {
    gpio_put(dir_pin, direction);

    for (int i = 0; i < steps; i++) {
        gpio_put(step_pin, 1);
        sleep_us(500); 
        gpio_put(step_pin, 0);
        sleep_us(500);
    }
}