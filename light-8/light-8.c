#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "../peri.h"

void main() {
    uint16_t light;
    init_peri();
    int max = 0, min = 99999;

    while (1) {
        light = read_adc(PC4);
        if (light > max) max = light;
        if (light < min) min = light;

        if (light < min+0.3*max) {
            set_led_value(0b000);
            _delay_ms(100);
        }
        else if (light >= min+0.3*max && light < min+0.475*max) {
            set_led_value(0b001);
            _delay_ms(100);
        }
        else if (light >= min+0.475*max && light < min+0.550*max) {
            set_led_value(0b010);
            _delay_ms(100);
        }
        else if (light >= min+0.550*max && light < min+0.625*max) {
            set_led_value(0b011);
            _delay_ms(100);
        }
        else if (light >= min+0.625*max && light < min+0.7*max) {
            set_led_value(0b100);
            _delay_ms(100);
        }
        else if (light >= min+0.7*max && light < min+0.775*max) {
            set_led_value(0b101);
            _delay_ms(100);
        }
        else if (light >= min+0.775*max && light < min+0.85*max) {
            set_led_value(0b110);
            _delay_ms(100);
        }
        else {
            set_led_value(0b111);
            _delay_ms(100);
        }
    }
}