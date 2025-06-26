#include <stdio.h>
#include "pico/stdlib.h"
#include "stepper.h"

/*
 * Inicializa os pinos utilizados pelo driver do motor de passo.
 *
 * Parâmetros:
 *  - en_pin: pino de Enable (ativa o driver em nível lógico baixo)
 *  - step_pin: pino de pulso (passo)
 *  - dir_pin: pino de direção
 */
void motor_init(int en_pin, int step_pin, int dir_pin) {
    // Inicializa e configura o pino de Enable como saída
    gpio_init(en_pin);
    gpio_set_dir(en_pin, GPIO_OUT);
    gpio_put(en_pin, 0); // Ativa o driver colocando em LOW

    // Inicializa e configura o pino de Step como saída
    gpio_init(step_pin);
    gpio_set_dir(step_pin, GPIO_OUT);
    gpio_put(step_pin, 0);

    // Inicializa e configura o pino de Direção como saída
    gpio_init(dir_pin);
    gpio_set_dir(dir_pin, GPIO_OUT);
    gpio_put(dir_pin, 0);
}

/*
 * Executa um número definido de passos no motor, com direção especificada.
 *
 * Parâmetros:
 *  - steps: número de passos a executar
 *  - direction: direção de rotação (true = horário, false = anti-horário)
 *  - step_pin: pino de passo
 *  - dir_pin: pino de direção
 */
void motor_move_steps(int steps, bool direction, int step_pin, int dir_pin) {
    // Define a direção do motor
    gpio_put(dir_pin, direction);

    // Loop para gerar os pulsos de passo
    for (int i = 0; i < steps; i++) {
        gpio_put(step_pin, 1);    // Pulso HIGH
        sleep_us(500);            // Espera 500 microssegundos
        gpio_put(step_pin, 0);    // Pulso LOW
        sleep_us(500);            // Intervalo entre pulsos
    }
}
