#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    bool a;
    bool b;
    bool start;
    bool joystick;

    uint16_t joystick_x;
    uint16_t joystick_y;
} InputState;

void Input_Init(void);
InputState Input_Read(void);