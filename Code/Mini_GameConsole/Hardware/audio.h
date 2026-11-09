#pragma once
#include <stdint.h>

void Audio_Init(void);
void Audio_PlayTone(uint8_t frequency);
void Audio_Stop(void);