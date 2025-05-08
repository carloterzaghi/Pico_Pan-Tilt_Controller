#ifndef STEPPER_H
#define STEPPER_H

#include <stdbool.h>
#include "pico/stdlib.h"

// Protótipos das funções
void motor_init(int en_pin, int step_pin, int dir_pin);
void motor_move_steps(int steps, bool direction, int step_pin, int dir_pin);

#endif // STEPPER_H