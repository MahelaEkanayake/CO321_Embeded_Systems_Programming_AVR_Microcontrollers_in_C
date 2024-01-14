#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void){

    int start = 2;
    int end = 5;

    for (int i = start; i <= end;i++){
        DDRB |= (1<<i);
    }

    while(1){
        for (int i = start; i <= end;i++){
            PORTB |= (1<<i);
        }
        _delay_ms(BLINK_DELAY_MS);
        for (int i = start; i <= end; i++){
            PORTB &= ~(1<<i);
        }
        _delay_ms(BLINK_DELAY_MS);
    }

    return 0;
}