#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
    uint8_t a = 10;
    uint16_t b = 500;
    uint32_t c = 100000;

    printf("Values: %u, %u, %lu\n", a, b, (unsigned long)c);

    return 0;
}