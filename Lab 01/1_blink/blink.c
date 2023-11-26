#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void){

    DDRB = DDRB | (0b00111100);                 //PB2,3,4,5 are output

    while(1){
        PORTB = PORTB | (0b00111100);           //set PB2,3,4,5 to HIGH
        _delay_ms(BLINK_DELAY_MS);              //delay
        PORTB = PORTB &~ (0b00111100);          //set PB2,3,4,5 to LOW
        _delay_ms(BLINK_DELAY_MS);              //delay
    }
}