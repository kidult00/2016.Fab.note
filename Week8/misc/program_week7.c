//  Week 7

#define F_CPU 12000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//  Output and input
	DDRA |= (1<<DDA2);  // set PA2 to be output
	DDRA |= (1<<DDA3);  // set PA3 to be output
	DDRA |= (1<<DDA7);  // set PA7 to be output
	DDRB &= ~(1 << DDB2); // set PB2 to be input

        // Programme
	while(13)
	{
		if(PINB & (1 << PINB2)) // if button is pushed
        	{
        		PORTA |= (1<<DDA2); // turn on LED1
                        PORTA &= ~(1<<DDA3); // turn off LED2
                        PORTA &= ~(1<<DDA7); // turn off LED3
        	}
                else
                {
                        PORTA &= ~(1<<DDA2); // turn off LED1
                  
                        // flash# 1
        		PORTA |= (1<<DDA3); // turn on LED2
        		_delay_ms(200); // wait
        		
        		PORTA &= ~(1<<DDA3); // turn off LED2
        		_delay_ms(200); // wait
        		
        		// flash# 2
        		PORTA |= (1<<DDA7); // turn on LED3
        		_delay_ms(200); // wait
        		
        		PORTA &= ~(1<<DDA7); // turn off LED3
        		_delay_ms(200); // wait
                }
	}
	return 0; //never reached
}
