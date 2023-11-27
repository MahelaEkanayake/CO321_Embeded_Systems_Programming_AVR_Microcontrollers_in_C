#include <avr/io.h>
#include <avr/interrupt.h>

int c = 0;

int main() {

	DDRD &= ~(1<<2 | 1<<3);
  	
  	DDRB |= 0x3f;
  
  	EICRA |= (1<<ISC01); 
  	EICRA |= (1<<ISC00);
  
  	EICRA |= (1<<ISC11);
  	EICRA |= (1<<ISC10);
  
  	sei();
  
  	EIMSK |= (1<<INT0);
  	EIMSK |= (1<<INT1);
  
  	while(1){}
  
  	return 0;
}

ISR(INT0_vect){
  
  PORTB = PORTB & ~(1<<c);
  
  c++;
}

ISR(INT1_vect){
	
  PORTB = PORTB | (1<<c);
  c++;
}