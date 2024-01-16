#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


ISR(TIMER0_OVF_vect) {

    PORTB ^= (1 << 5);
    TCNT0 = 131;
}

int main(void) {

    DDRB |= 0b11111;    

    TCNT0 = 131; 

    TCCR0A |= 0x00;
    TCCR0B |= (1 << CS02);

    TIMSK0 |= (1 << TOIE0);

    sei();

    while (1) {
    }

    return 0;
}
