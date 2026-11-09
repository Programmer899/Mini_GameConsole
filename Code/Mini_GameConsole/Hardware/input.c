#include "input.h"
#include "pico/stdlib.h"
#include "Hardware/adc.h"

// Example GPIO assignments
#define PIN_A       2
#define PIN_B       3
#define PIN_START   4
#define PIN_JOY_BTN 6

#define PIN_JOY_X 26
#define PIN_JOY_Y 27

void Input_Init(void) {
    uint buttons[] = {
        PIN_A, PIN_B, PIN_START, PIN_JOY_BTN
    };

    for (int i = 0; i < 5; i++) {
        gpio_init(buttons[i]);
        gpio_set_dir(buttons[i], GPIO_IN);
        gpio_pull_up(buttons[i]);
    }

    adc_init();
    adc_gpio_init(PIN_JOY_X);
    adc_gpio_init(PIN_JOY_Y);
}

InputState Input_Read(void) {
    InputState state;

    state.a = !gpio_get(PIN_A);
    state.b = !gpio_get(PIN_B);
    state.start = !gpio_get(PIN_START);
    state.joystick = !gpio_get(PIN_JOY_BTN);

    adc_select_input(0);
    state.joystick_x = adc_read();

    adc_select_input(1);
    state.joystick_y = adc_read();

    return state;
}