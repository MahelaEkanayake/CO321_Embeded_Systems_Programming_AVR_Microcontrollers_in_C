#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){

  	DDRB = 0x3f;
  	DDRD &= ~(1<<2);
  
  	PORTB |= 0x00;
  
  	int counter = 0;
  
  	int count_enable = 1;
  
  	while(1){
    
    	if(PIND & (1<<2)){
          
      		_delay_ms(DELAY);
          
          	if(count_enable==1){
            	counter++;
          		if(counter == 64)
              		counter = 0;
              	count_enable = 0;
            }
      		
          	if(count_enable == 0)      		
      			PORTB = counter;
        }else{
        	count_enable = 1;
        }
    }
  }
