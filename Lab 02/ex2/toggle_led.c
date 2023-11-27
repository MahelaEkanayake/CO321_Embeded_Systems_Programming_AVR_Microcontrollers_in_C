#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int c = 0;

int main() {

	DDRD &= ~(1<<2);
  	
  	DDRB |= (1<<0);
  
  	EICRA |= (1<<ISC01);
  	EICRA |= (1<<ISC00);

  	sei();
  
  	EIMSK |= (1<<INT0);
  
  	while(1){
    }
  
  	return 0;
}

ISR(INT0_vect){
	
  c = ~c;
  if(c==0){
    PORTB &= ~(1<<0);
  }else{
    PORTB |= (1<<0);
  }
  
}