#include "stdlib.h"

#include "Hardware/input.h"
#include "Hardware/audio.h"
#include "Hardware/display.h"

int main() {
    stdio_init_all();

    Input_Init();
    Audio_Init();
    Display_Init();

    Display_Clear(COLOR_BLACK);

    while (true) {
        InputState input = Input_Read();

        if (input.a) {
            Audio_PlayTone(440);
        }
        else {
            Audio_Stop();
        }

        // Example joystick-controlled drawing
        int x = input.joystick_x * 128 / 4096;
        int y = input.joystick_y * 160 / 4096;

        Display_Clear(COLOR_BLACK);
        Display_DrawPixel(x, y, COLOR_GREEN);

        sleep_ms(16);
    }
}