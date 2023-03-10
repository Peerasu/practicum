#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "../peri.h"

void main() {
    uint8_t count = 0;
    init_peri();
    set_led_value(0);

    while(1) {
        if (SWITCH_PRESSED()) {
            count++;
        }
        count = count%8;

        set_led_value(count);
        _delay_ms(100);
    }
}