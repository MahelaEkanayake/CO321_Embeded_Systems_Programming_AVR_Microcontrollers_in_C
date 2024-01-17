#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

double dutyCycle = 0;
bool increaseDutyCycle = true;

int main(void){

    DDRD |= (1 << 6);

    TCCR0A |= (1 <<COM0A1) | (1 <<WGM00) | (1 << WGM01);
    TCCR0B |= (1 << CS00) | (1 << CS01);

    TIMSK0 |= (1 << TOIE0);

    OCR0A = ((dutyCycle/100.0)*256)-1;

    sei();

    while(1){
        
        if(increaseDutyCycle){
            dutyCycle++;
        }else{
            dutyCycle--;
        }
        
        if(dutyCycle>=100 || dutyCycle<=0){
            increaseDutyCycle = !increaseDutyCycle;
        }
        _delay_ms(10);
    }

    return 0;
}

ISR (TIMER0_OVF_vect){
    OCR0A = ((dutyCycle/100.0)*256)-1;
}