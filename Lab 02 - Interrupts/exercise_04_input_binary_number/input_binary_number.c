#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t ledNumber = 0;

int main(void) {
    DDRD &= ~(1 << 2);
    DDRD &= ~(1 << 3);

    DDRB |= 0b111111;

    EICRA |= (1 << ISC01);
    EICRA |= (1 << ISC00);

    EICRA |= (1 << ISC11);
    EICRA |= (1 << ISC10);

    sei();

    EIMSK |= (1 << INT0);
    EIMSK |= (1 << INT1);

    while (1);

    return 0;
}

ISR(INT0_vect) {
    if (ledNumber >= 6){
        PORTB = 0;
        ledNumber = 0;
    }
    PORTB |= (1 << ledNumber);
    ledNumber++;
}

ISR(INT1_vect) {
    if (ledNumber >= 6) {
        PORTB = 0;
        ledNumber = 0;
    }
    PORTB &= ~(1 << ledNumber);
    ledNumber++;
}
