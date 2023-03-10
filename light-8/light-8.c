#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "../peri.h"

void main() {
    uint16_t light;
    init_peri();

    while (1) {
        light = read_adc(PC4);
        if (light < 350)
            set_led_value(0b000);
        else if (light >= 350 && light < 400)
            set_led_value(0b001);
        else if (light >= 450 && light < 500)
            set_led_value(0b010);
        else if (light >= 500 && light < 550)
            set_led_value(0b011);
        else if (light >= 600 && light < 650)
            set_led_value(0b100);
        else if (light >= 650 && light < 700)
            set_led_value(0b101);
        else if (light >= 700 && light < 750)
            set_led_value(0b110);
        else if (light >= 750 && light < 800)
            set_led_value(0b111);
    }
}