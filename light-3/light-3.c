#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "peri.h"

void main() {
    unit16_t light;
    init_peri();

    while (true) {
        light = read_adc(PC4);
        if (light < 200)
            set_led_value(0b001);
        else if (light < 500)
            set_led_value(0b010);
        else
            set_led_value(0b100);
    }
}