#include <avr/io.h>
#include <util/delay.h>

#define BULB_LIGHT_TIME_MS 200

int main(void){

    int start = 2;
    int end = 5;

    for (int i = start; i<= end; i++){
        DDRB |= (1<<i);
    }

    PORTB |= 0;

    while(1){
        for (int i = start; i < end;i++){
            PORTB |= (1<<i);
            _delay_ms(BULB_LIGHT_TIME_MS);
            PORTB &= ~(1<<i);
        }
        for (int i = end; i > start; i--){
            PORTB |= (1<<i);
            _delay_ms(BULB_LIGHT_TIME_MS);
            PORTB &= ~(1<<i); 
        }
    }

        return 0;
}