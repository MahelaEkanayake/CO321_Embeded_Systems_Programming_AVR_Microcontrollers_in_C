#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

double dutyCycle = 0;
int frequencyNo = 2;

int main(void){

    DDRD |= (1 << 6);
    DDRB |= 0b11110;
    PORTB |= (1 << 1);

    TCCR0A |= (1 <<COM0A1) | (1 <<WGM00) | (1 << WGM01);
    TCCR0B = frequencyNo;

    TIMSK0 |= (1 << TOIE0);

    OCR0A = ((dutyCycle/100.0)*256)-1;

    sei();

    while(1){

        dutyCycle++;

        if(dutyCycle>=100){
            dutyCycle = 0;
            frequencyNo++;
            
            if(frequencyNo >=6){
                frequencyNo = 2;
            }
            PORTB = 0;
            PORTB |= (1 << (frequencyNo-1));
        }
        _delay_ms(100);
    }

    return 0;
}

ISR (TIMER0_OVF_vect){
    OCR0A = ((dutyCycle/100.0)*256)-1;
    TCCR0B = frequencyNo;
}