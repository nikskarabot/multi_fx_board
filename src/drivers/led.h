#ifndef LED_H

#include "defines.h"
#include "main.h"

// Simple driver for controlling GPIOs with LEDs connected to them

// TO DO: add doxygen comment
typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} Led_t;

extern const Led_t leds[];

int led_write(int index, IO_State state);
int led_toggle(int index);

#endif // LED_H