#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t count = 0;

ISR(TIMER0_OVF_vect) {

    count++;

    if(count>=50){
        PORTB ^= (1<<0);
        count = 0;
    }

    TCNT0 = 6;
}

ISR(TIMER1_OVF_vect) {

    PORTB ^= (1<<1);
    TCNT1 = 34286;
}


int main(void){

    DDRB |= (1<<0) | (1<<1);

    TCNT0 = 6;
    TCNT1 = 34286;

    TCCR0A = 0X00;
    TCCR0B = (1 << CS01) | (1 << CS00);

    TCCR1A = 0X00;
    TCCR1B = (1 << CS12);

    TIMSK0 |= (1<<TOIE0);
    TIMSK1 |= (1<<TOIE1);

    sei();

    while(1);

    return 0;
}