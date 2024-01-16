#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

int count = 0;
uint8_t bulbNo = 0;
bool increaseBulbNo = true;

ISR(TIMER0_OVF_vect) {
    count++;
    if (count >= 200) {
        PORTB &= ~(0b1111);
        PORTB |= (1 << bulbNo);

        if(increaseBulbNo){
            bulbNo++;
        } else {
            bulbNo--;
        }

        if(bulbNo >= 3 && increaseBulbNo || bulbNo <= 0 && !increaseBulbNo){
            increaseBulbNo = !increaseBulbNo;
        }
        count = 0;
    }
    TCNT0 = 6;  
}

ISR(TIMER1_OVF_vect) {
    PORTB ^= (1 << 5);
    TCNT1 = 49911;
}

int main(void) {
    DDRB |= 0b101111;

    TCNT0 = 6;
    TCNT1 = 49911;

    TCCR0A = 0X00;
    TCCR0B |= (1 << CS01) | (1 << CS00);  

    TCCR1A = 0X00;
    TCCR1B |= (1 << CS12) | (1 << CS10);  // Correct prescaler setting for 1024

    TIMSK0 |= (1 << TOIE0);  
    TIMSK1 |= (1 << TOIE1);

    sei();

    while (1);

    return 0;
}
