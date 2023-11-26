#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(void){

    DDRB = DDRB | (0b00111100);                 //PB2,3,4,5 are output

    while(1){

        /*here set bulbs ON and OFF in ascending order*/
        for(int i=2;i<5;i++){                  //i = 2,3,4
            PORTB = PORTB | (1<<i);            //PBi is high
            _delay_ms(BLINK_DELAY_MS);         //delay
            PORTB = PORTB & ~(1<<i);           //PBi is low
        }

        /*here set bulbs ON and OFF in descending order*/
        for(int i=5;i>2;i--){                  //i = 5,4,3
            PORTB = PORTB | (1<<i);            //PBi is high
            _delay_ms(BLINK_DELAY_MS);         //delay
            PORTB = PORTB & ~(1<<i);           //PBi is low
        }
    }
}