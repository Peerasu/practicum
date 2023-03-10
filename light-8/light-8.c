#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "../peri.h"

void main() {
    uint16_t light;
    init_peri();
    int min = 600;
    int max = 1023;

    while (1) {
        light = read_adc(PC4);

        if (light < min) {
            set_led_value(0b000);
            _delay_ms(100);
        }
        else if (light >= min+50 && light < min +100) {
            set_led_value(0b001);
            _delay_ms(100);
        }
        else if (light >= min+100 && light < min+150) {
            set_led_value(0b010);
            _delay_ms(100);
        }
        else if (light >= min+150 && light < min+200) {
            set_led_value(0b011);
            _delay_ms(100);
        }
        else if (light >= min+200 && light < min+250) {
            set_led_value(0b100);
            _delay_ms(100);
        }
        else if (light >= min+250 && light < min+300) {
            set_led_value(0b101);
            _delay_ms(100);
        }
        else if (light >= min+300 && light < min+350) {
            set_led_value(0b110);
            _delay_ms(100);
        }
        else {
            set_led_value(0b111);
            _delay_ms(100);
        }
    }
}