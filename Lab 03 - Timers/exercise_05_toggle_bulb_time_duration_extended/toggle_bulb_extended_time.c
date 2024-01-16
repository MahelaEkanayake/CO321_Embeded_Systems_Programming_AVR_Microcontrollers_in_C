#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t count = 0;

ISR(TIMER0_OVF_vect) {

    count++;

    if(count>=25){
        PORTB ^= (1<<5);
        count = 0;
    }

    TCNT0 = 6;
}

int main(void) {

    DDRB |= (1<<5);    

    TCNT0 = 6; 

    TCCR0A |= 0x00;
    TCCR0B |= (1 << CS02);

    TIMSK0 |= (1 << TOIE0);

    sei();

    while (1) {
    }

    return 0;
}
