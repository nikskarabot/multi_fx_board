#include "my_main.h"
#include <main.h>

void led_sequence(void) {
    static int i = 0;

    Led_t current_led = leds[i];

    HAL_GPIO_WritePin(current_led.port, current_led.pin, GPIO_PIN_SET);
    HAL_Delay(500);
    HAL_GPIO_WritePin(current_led.port, current_led.pin, GPIO_PIN_RESET);

    i++;
    i %= 10;
}

int my_main(void) {

    int i = 0;

    while (1) {
        led_sequence();
    }
    return 0;
}