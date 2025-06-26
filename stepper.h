#ifndef STEPPER_H
#define STEPPER_H

#include <stdbool.h>
#include "pico/stdlib.h"

/*
 * Inicializa os pinos necessários para o controle do motor de passo.
 *
 * Parâmetros:
 *  - en_pin: pino Enable do driver (ativa o motor)
 *  - step_pin: pino de passo
 *  - dir_pin: pino de direção
 */
void motor_init(int en_pin, int step_pin, int dir_pin);

/*
 * Move o motor de passo uma quantidade de passos definida.
 *
 * Parâmetros:
 *  - steps: número de passos a executar
 *  - direction: direção de rotação (true = horário, false = anti-horário)
 *  - step_pin: pino de passo
 *  - dir_pin: pino de direção
 */
void motor_move_steps(int steps, bool direction, int step_pin, int dir_pin);

#endif // STEPPER_H
