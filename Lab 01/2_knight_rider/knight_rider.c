#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(void){

    DDRB = DDRB | (0b00111100);

    while(1){

        for(int i=2;i<5;i++){
            PORTB = PORTB | (1<<i);
            _delay_ms(BLINK_DELAY_MS);
            PORTB = PORTB & ~(1<<i);
        }
        for(int i=5;i>2;i--){
            PORTB = PORTB | (1<<i);
            _delay_ms(BLINK_DELAY_MS);
            PORTB = PORTB & ~(1<<i);
        }
    }
}