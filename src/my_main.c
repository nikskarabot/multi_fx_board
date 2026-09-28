#include "my_main.h"
#include <main.h>

int my_main(void) {

    int i = 0;

    while (1) {
        Led_t current_led = leds[i];

        HAL_GPIO_WritePin(current_led.port, current_led.pin, GPIO_PIN_SET);
        HAL_Delay(500);
        HAL_GPIO_WritePin(current_led.port, current_led.pin, GPIO_PIN_RESET);
        HAL_Delay(500);

        i++;
        i %= 10;
    }
    return 0;
}