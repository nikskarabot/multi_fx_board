#include "assert_handler.h"

#include "main.h"
#include "led.h"

/*
    cmsis_compiler.h selects the compiler-specific implementation,
    such as cmsis_gcc.h, so you don’t need to include main.h or
    a GCC-specific header.
*/
#include <cmsis_compiler.h>

void assert_handler(void) {
    // TODO: Turn off CS4270 output ("safe state")
    // TODO: Trace to console
    // Trigger breakpoint
    __BKPT();
    // TODO: Blink LED indefinitely
    while (1) {
        // Custom LED functions are not used since they include
        // ASSERT handler in themselves so recursive calling would occur
        HAL_GPIO_TogglePin(leds[0].port, leds[0].pin);
    }
}