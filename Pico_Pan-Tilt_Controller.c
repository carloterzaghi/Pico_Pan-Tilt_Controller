#include <stdio.h>
#include "pico/stdlib.h"
#include "stepper.h"  

#define EN_PIN     21
#define STEP_PIN   20
#define DIR_PIN    19
#define H1_O       18

bool sentido = true; 

int main() {
    stdio_init_all();
    motor_init(EN_PIN, STEP_PIN, DIR_PIN);

    gpio_init(H1_O);
    gpio_set_dir(H1_O, GPIO_IN);

    while (true) {
        bool valor_h1 = gpio_get(H1_O);
        printf("Valor do pino GPIO %d (H1_O): %d\n", H1_O, valor_h1);
        
        if (valor_h1 == 1 && sentido == true){
            sentido = false;
        }
        else if (valor_h1 == 1 && sentido == false){
            sentido = true;

        }

        motor_move_steps(2000, sentido, STEP_PIN, DIR_PIN);
        sleep_ms(0);
    }
}