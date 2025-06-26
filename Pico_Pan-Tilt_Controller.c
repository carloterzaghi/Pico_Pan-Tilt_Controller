#include <stdio.h>
#include "pico/stdlib.h"
#include "stepper.h"  // Biblioteca com funções para controle do motor de passo

// Definição dos pinos utilizados
#define EN_PIN     21  // Pino de Enable do driver do motor (ativo em LOW)
#define STEP_PIN   20  // Pino para enviar os pulsos de passo
#define DIR_PIN    19  // Pino de direção do motor
#define H1_O       18  // Pino de entrada digital (ex: botão, fim de curso, sensor óptico)

// Variável que controla o sentido da rotação do motor (true = horário, false = anti-horário)
bool sentido = true;

/*
 * Função principal do programa.
 * Inicializa o sistema, configura os pinos e entra em loop infinito,
 * alternando o sentido do motor de passo com base na leitura de H1_O.
 */
int main() {
    stdio_init_all(); // Inicializa a comunicação padrão (para debug via USB)
    
    // Inicializa os pinos do motor de passo (Enable, Step e Direction)
    motor_init(EN_PIN, STEP_PIN, DIR_PIN);

    // Configura o pino de entrada H1_O como entrada digital
    gpio_init(H1_O);
    gpio_set_dir(H1_O, GPIO_IN);

    // Loop principal do programa
    while (true) {
        // Lê o valor atual do pino de entrada
        bool valor_h1 = gpio_get(H1_O);
        printf("Valor do pino GPIO %d (H1_O): %d\n", H1_O, valor_h1);
        
        /*
         * Se o pino H1_O estiver em nível alto (1),
         * alterna o sentido do motor (de horário para anti-horário e vice-versa).
         * Isso simula uma reação a um evento externo, como o pressionamento de um botão
         * ou a ativação de um sensor.
         */
        if (valor_h1 == 1 && sentido == true){
            sentido = false;
        }
        else if (valor_h1 == 1 && sentido == false){
            sentido = true;
        }

        // Executa o movimento do motor: 2000 passos no sentido atual
        motor_move_steps(2000, sentido, STEP_PIN, DIR_PIN);

        // Pequena pausa entre execuções (pode ser ajustado conforme necessário)
        sleep_ms(0); // Aqui não há atraso, mas pode-se colocar um valor (>0) para espaçar os ciclos
    }
}
