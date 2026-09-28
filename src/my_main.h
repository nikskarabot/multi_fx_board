#ifndef MY_MAIN_H
#define MY_MAIN_H

#include <main.h>

int my_main(void);

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} Led_t;

static const Led_t leds[] = {
    {LED_FS_1_GPIO_Port, LED_FS_1_Pin}, {LED_FS_2_GPIO_Port, LED_FS_2_Pin},
    {LED_FS_3_GPIO_Port, LED_FS_3_Pin}, {LED_FS_4_GPIO_Port, LED_FS_4_Pin},
    {LED_FS_5_GPIO_Port, LED_FS_5_Pin}, {LED_FS_6_GPIO_Port, LED_FS_6_Pin},
    {LED_FS_7_GPIO_Port, LED_FS_7_Pin}, {LED_FS_8_GPIO_Port, LED_FS_8_Pin},
    {LED_FS_9_GPIO_Port, LED_FS_9_Pin}, {LED_FS_10_GPIO_Port, LED_FS_10_Pin},
};

#endif
