#include <avr/io.h>

int counter = 0;

int main(void) {
    
    DDRD &= ~(1 << 2);

    PORTD |= (1 << 2);

    DDRB |= (0b00111111);
    PORTB = 0b00000000;

    int access_count = 1;

    while (1) {
        if (PIND & (1 << 2)){
            if(access_count==1){
                counter++;
                if(counter==64)
                    counter = 0;
                access_count = 0;
            }
        }else{

            if(access_count==0){
                PORTB = 0b00000000;
                PORTB = counter;
                access_count = 1;
            }

            
        }   
    }

    return 0;
}


