# Pico Pan-Tilt Controller

Este projeto implementa o controle de um motor de passo utilizando um Raspberry Pi Pico. A direção do motor alterna automaticamente com base no estado de um pino digital de entrada, simulando um sistema de pan-tilt simples.

## 📁 Estrutura do Projeto

- `Pico_Pan-Tilt_Controller.c`: Código principal que inicializa o motor e monitora o pino de entrada para alternar o sentido do motor.
- `stepper.c` / `stepper.h`: Biblioteca com funções auxiliares para inicializar e movimentar o motor de passo.

## ⚙️ Hardware Utilizado

- **Microcontrolador:** Raspberry Pi Pico
- **Motor:** Motor de passo superior do Pan-Tilt
- **Pinos GPIO:**
  - `EN_PIN` (GPIO 21): Enable do driver do motor
  - `STEP_PIN` (GPIO 20): Pulso de passo
  - `DIR_PIN` (GPIO 19): Direção do motor
  - `H1_O` (GPIO 18): Entrada digital (Sensor de fim de curso)

## 🚀 Como Funciona

1. O sistema inicia e configura os GPIOs do motor.
2. Lê continuamente o estado do pino `H1_O`.
3. Cada vez que `H1_O` estiver em nível alto (`1`), alterna a direção do motor.
4. Executa um movimento de 2000 passos na direção atual.

```c
if (valor_h1 == 1 && sentido == true) {
    sentido = false;
} else if (valor_h1 == 1 && sentido == false) {
    sentido = true;
}
```