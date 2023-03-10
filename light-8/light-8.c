#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "../peri.h"

void main() {
    uint16_t light;
    init_peri();

    while (1) {
        light = read_adc(PC4);
        if (light < 200) {
            set_led_value(0b000);
            _delay_ms(100);
        }
        else if (light >= 200 && light < 275) {
            set_led_value(0b001);
            _delay_ms(100);
        }
        else if (light >= 275 && light < 350) {
            set_led_value(0b010);
            _delay_ms(100);
        }
        else if (light >= 350 && light < 425) {
            set_led_value(0b011);
            _delay_ms(100);
        }
        else if (light >= 425 && light < 500) {
            set_led_value(0b100);
            _delay_ms(100);
        }
        else if (light >= 500 && light < 575) {
            set_led_value(0b101);
            _delay_ms(100);
        }
        else if (light >= 575 && light < 650) {
            set_led_value(0b110);
            _delay_ms(100);
        }
        else {
            set_led_value(0b111);
            _delay_ms(100);
        }
    }
}