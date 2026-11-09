#include <audio.h>
#include "stdlib.h"
#include <pwm.h>
#include <stdint.h>
#define PIEZO_PIN 15

void Audio_Init(void) {
    gpio_set_function(PIEZO_PIN, GPIO_FUNC_PWM);

    uint8_t slice = pwm_gpio_to_slice_num(PIEZO_PIN);
    pwm_set_enabled(slice, false);
}

void Audio_PlayTone(uint8_t frequency) {
    if (frequency == 0) {
        Audio_Stop();
        return;
    }

    uint8_t slice = pwm_gpio_to_slice_num(PIEZO_PIN);

    uint32_t clock = 125000000;
    float divider = 8.0f;

    uint32_t wrap = (clock / (divider * frequency)) - 1;

    pwm_set_clkdiv(slice, divider);
    pwm_set_wrap(slice, wrap);
    pwm_set_gpio_level(PIEZO_PIN, wrap / 2);

    pwm_set_enabled(slice, true);
}

void Audio_Stop(void) {
    uint8_t slice = pwm_gpio_to_slice_num(PIEZO_PIN);

    pwm_set_enabled(slice, false);
    gpio_put(PIEZO_PIN, 0);
}