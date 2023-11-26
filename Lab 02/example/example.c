#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#define BLINK_DELAY_MS 1000

int main(){

    DDRD &= ~(1<<2);                    //PD2 (INT0) is input
    DDRB |= (1<<0);                     //PB0 is output

    EICRA |= (1<<ISC01);                //set for rising edge detection
    EICRA |= (1<<ISC00);                //set for rising edge detection

    sei();                              //enable global interrupt

    EIMSK |= (1<<INT0);                 //enable external interrupt for int0

    while(1){

    }
}

ISR(INT0_vect){
    PORTB &= ~(1<<0);                   //PB0 is off
    _delay_ms(BLINK_DELAY_MS);          //delay
    PORTB |= (1<<0);                    //PB0 is on
}