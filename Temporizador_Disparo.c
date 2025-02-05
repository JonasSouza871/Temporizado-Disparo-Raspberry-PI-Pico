#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

#define LED_VERMELHO 13
#define LED_VERDE 12
#define LED_AZUL 11   //declara leds conforme pinagem da placa
#define BOTAO 5

bool leds_ligados = false;
int64_t desligar_leds(alarm_id_t id, void *unused);
int64_t desligar_azul(alarm_id_t id, void *unused);
int64_t desligar_vermelho(alarm_id_t id, void *unused);
void tratar_interrupcao_botao(uint gpio, uint32_t eventos);

// Função para desligar todos os LEDs
int64_t desligar_leds(alarm_id_t id, void *unused) {
    sleep_ms(50); // Debouncing
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AZUL, 0); //desligado
    leds_ligados = false;
    return 0;
}

// Temporizadores para desligar LEDs em sequência
int64_t desligar_azul(alarm_id_t id, void *unused) {
    gpio_put(LED_AZUL, 0);
    add_alarm_in_ms(3000, desligar_vermelho, NULL, false);
    return 0;
}

int64_t desligar_vermelho(alarm_id_t id, void *unused) {
    gpio_put(LED_VERMELHO, 0);
    add_alarm_in_ms(3000, desligar_leds, NULL, false);
    return 0;
}
//interrupção
void tratar_interrupcao_botao(uint gpio, uint32_t eventos) {
    if (!leds_ligados) {
        leds_ligados = true;
        gpio_put(LED_VERDE, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_AZUL, 1);
        add_alarm_in_ms(3000, desligar_azul, NULL, false);
    }
}

int main() {
    stdio_init_all();

    // Inicializa LEDs como saída
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    // Configura botão como entrada com pull-up e interrupção
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, tratar_interrupcao_botao);

    while (true) {
        printf("Pressione o botão para iniciar a sequência.\n");
        sleep_ms(1000);
    }
}
