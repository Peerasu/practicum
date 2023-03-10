#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "../peri.h"

void main() {
    uint16_t light;
    init_peri();

    while (1) {
        light = read_adc(PC4);
        if (light < 350) {
            set_led_value(0b001);
            _delay_ms(100);
        }
        else if (light >= 350 && light < 500) {
            set_led_value(0b010);
            _delay_ms(100);
        }
        else {
            set_led_value(0b100);
            _delay_ms(100);
        }
    }
}