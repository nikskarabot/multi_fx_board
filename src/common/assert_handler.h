#ifndef ASSERT_HANDLER_H

// Assert implementation suitable for microcontroller
void assert_handler(void) __attribute__((noreturn));

#define ASSERT(expression)                                                     \
    do {                                                                       \
        if (!(expression)) {                                                   \
            assert_handler();                                                  \
        }                                                                      \
    } while (0)

#endif // ASSERT_HANDLER_H