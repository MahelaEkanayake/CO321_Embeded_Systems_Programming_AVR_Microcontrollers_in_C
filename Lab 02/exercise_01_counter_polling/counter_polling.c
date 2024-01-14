#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>

uint8_t pressCount = 0;
bool buttonPressed = false;
bool numberToBeAssigned = false;

int main(void){

    DDRD &= ~(1<<2);

    DDRB |= 0b111111;
    PORTB = 0;

    while(1){
        if((PIND & (1<<2)) && !buttonPressed){
            buttonPressed = true;
            numberToBeAssigned = true;
            pressCount++;
            if(pressCount >= 64){
                pressCount = 0;
            }
        } else if (!(PIND & (1<<2))) {
            buttonPressed = false;
        }

        if(numberToBeAssigned){
            PORTB = pressCount;
            numberToBeAssigned = false;
        }

    }

    return 0;
}
