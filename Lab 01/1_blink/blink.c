#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void){

    DDRB = DDRB | (0b00111100);

    while(1){
        PORTB = PORTB | (0b00111100);
        _delay_ms(BLINK_DELAY_MS);
        PORTB = PORTB &~ (0b00111100);
        _delay_ms(BLINK_DELAY_MS);
    }
}