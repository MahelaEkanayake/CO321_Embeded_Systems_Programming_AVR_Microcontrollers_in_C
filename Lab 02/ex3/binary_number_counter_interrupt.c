#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int c = 0;

int main() {

	DDRD &= ~(1<<2);
  	
  	DDRB = 0x3f;
  
  	EICRA |= (1<<ISC01);
  	EICRA |= (1<<ISC00);
  
  	sei();
  
  	EIMSK |= (1<<INT0);
  
  	while(1){
    }
  
  	return 0;
}

ISR(INT0_vect){
	
    c++;
    if(c==64)
        c=0;
    PORTB = c;
}