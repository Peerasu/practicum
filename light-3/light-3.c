#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "../peri.h"

void main() {
    uint16_t light;
    init_peri();
    int max_light = 0;
    while (1) {
        light = read_adc(PC4);
        if (light > max_light) max_light = light;
        if (light < 0.4 * max_light) {
            set_led_value(0b001);
            _delay_ms(100);
        }
        else if (light >= 0.4 * max_light && light < 0.7 * max_light) {
            set_led_value(0b010);
            _delay_ms(100);
        }
        else {
            set_led_value(0b100);
            _delay_ms(100);
        }
    }
}