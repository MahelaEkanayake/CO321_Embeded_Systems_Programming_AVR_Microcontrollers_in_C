#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t pressCount = 0;

int main(void){

    DDRD &= ~(1<<2);

    DDRB |= 0b111111;
    PORTB = 0;

    EICRA |= (1<<ISC01);
    EICRA |= (1<<ISC00);

    sei();

    EIMSK |= (1<<INT0);

    while(1);

    return 0;
}

ISR(INT0_vect){
    pressCount++;
    if(pressCount>=64){
        pressCount = 0;
    }
    PORTB = pressCount;
}