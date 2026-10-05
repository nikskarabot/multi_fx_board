#include "led.h"

#include "main.h"
#include "assert_handler.h"
#include "defines.h"

// TO DO: add doxygen comment
const Led_t leds[] = {
    {LED_FS_1_GPIO_Port, LED_FS_1_Pin},   {LED_FS_7_GPIO_Port, LED_FS_7_Pin},
    {LED_FS_3_GPIO_Port, LED_FS_3_Pin},   {LED_FS_9_GPIO_Port, LED_FS_9_Pin},
    {LED_FS_10_GPIO_Port, LED_FS_10_Pin}, {LED_FS_6_GPIO_Port, LED_FS_6_Pin},
    {LED_FS_2_GPIO_Port, LED_FS_2_Pin},   {LED_FS_8_GPIO_Port, LED_FS_8_Pin},
    {LED_FS_4_GPIO_Port, LED_FS_4_Pin},   {LED_FS_5_GPIO_Port, LED_FS_5_Pin},
};

// TO DO: add doxygen comment
int led_write(int index, IO_State state) {
    // Check if index is within bound
    ASSERT(index >= 0 && index < 10);

    if (state == HIGH) {
        HAL_GPIO_WritePin(leds[index].port, leds[index].pin, GPIO_PIN_SET);
    } else {
        HAL_GPIO_WritePin(leds[index].port, leds[index].pin, GPIO_PIN_RESET);
    }

    return 0;
}

// TO DO: add doxygen comment
int led_toggle(int index) {
    // Check if index is within bound
    ASSERT(index >= 0 && index < 10);

    HAL_GPIO_TogglePin(leds[index].port, leds[index].pin);

    return 0;
}