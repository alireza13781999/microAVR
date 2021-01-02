/*******************************************************
Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 6/000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include <stdio.h>
#define ICR1 256 * ICR1H + ICR1L


unsigned int pos_edge, neg_edge, end_edge;
unsigned int period, clock;
char frequency[20];
long freq;



void main(void)
{
    lcd_init(24);

    PORTD = 0x00;
    
    while(1)
    {
        TCCR1A = 0;
        TCNT1=0;
        TIFR = (1<<ICF1);      

        TCCR1B = 0x41;  
        while ((TIFR&(1<<ICF1)) == 0);
        pos_edge = ICR1;         
        TIFR = (1<<ICF1);     
                
        TCCR1B = 0x01;    
        while ((TIFR&(1<<ICF1)) == 0);
        neg_edge = ICR1;          
        TIFR = (1<<ICF1);     
                
        TCCR1B = 0x41;
        while ((TIFR&(1<<ICF1)) == 0);
        end_edge = ICR1; 
        TIFR = (1<<ICF1);

        TCCR1B = 0;
		
		if(pos_edge < end_edge)
		{
			period = neg_edge - pos_edge;   
			freq = 6000000UL/period;
            freq = freq / 6; 
            sprintf(frequency,"Frequency: %d Hz", (int)freq);
			
            lcd_clear();
			lcd_puts(frequency);
		}else lcd_puts("");
        
        delay_ms(100);
	}
}
