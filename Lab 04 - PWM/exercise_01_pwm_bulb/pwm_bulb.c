#include <avr/io.h>
#include <avr/interrupt.h>

double dutyCycle = 50;

int main(void){

    DDRD |= (1 << 6);

    TCCR0A |= (1 <<COM0A1) | (1 <<WGM00) | (1 << WGM01);
    TCCR0B |= (1 << CS00) | (1 << CS01);

    TIMSK0 |= (1 << TOIE0);

    OCR0A = ((dutyCycle/100.0)*256)-1;

    sei();

    while(1);

    return 0;
}

ISR (TIMER0_OVF_vect){

}