#include "my_main.h"

#include "main.h"
#include "led.h"
#include "defines.h"
#include "assert_handler.h"

// TO DO: Move to test file
static void test_assert(void) {
    ASSERT(0);
}

void led_sequence(void) {

    static int i = 0;

    led_write(i, HIGH);
    HAL_Delay(500);
    led_write(i, LOW);

    i++;
    i %= 10;
}

int my_main(void) {
    while (1) {
        led_sequence();
    }
    return 0;
}