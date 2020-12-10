/*******************************************************
Project : Project-1
Date    : 10/12/2020
Author  : Alireza Nemati

Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12/000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <delay.h>

#define led1 PORTB.0
#define led2 PORTB.1
#define led3 PORTB.2
#define led4 PORTB.3
#define led5 PORTB.4
#define led6 PORTB.5
#define led7 PORTB.6
#define led8 PORTB.7

static unsigned int time_count;

//interrupt for blinking 0.5 sec
interrupt [TIM0_OVF] void timer0_ovf_isr(void) 
{
    TCNT0 = 31; 
    ++time_count; 
    if (time_count == 3333)
  {
        PORTC.0 = (PORTC.0 ^ 1); 
        time_count = 0; 
     }
}

void main(void)
{
    //for 0.5 sec
    DDRC = 0x01;
    TCCR0=0x02;
    TCNT0=31;
    TIMSK=0x01; 
    
    // for 8 LED
    DDRA = 0x00;   
    PINA = 0x00;  
    DDRB = 0xff;  
    PORTB = 0x00;
    
    #asm("sei");
    
    while (1)
        {
          
            if (PINA == 0x01)
            {
                led1 = 1;
                delay_ms(100); 
                led1 = 0;
                
                led2 = 1;
                delay_ms(100); 
                led2 = 0; 
                
                led3 = 1;
                delay_ms(100); 
                led3 = 0;  
                
                led4 = 1;
                delay_ms(100); 
                led4 = 0; 
                
                led4 = 1;
                delay_ms(100); 
                led4 = 0;
                
                led5 = 1;
                delay_ms(100); 
                led5 = 0;
                
                led6 = 1;
                delay_ms(100); 
                led6 = 0;
                
                led7 = 1;
                delay_ms(100); 
                led7 = 0;
                
                led8 = 1;
                delay_ms(100); 
                led8 = 0;
                   
                
                led7 = 1;
                delay_ms(100); 
                led7 = 0;
                
                led6 = 1;
                delay_ms(100); 
                led6 = 0;
                
                led5 = 1;
                delay_ms(100); 
                led5 = 0;
                
                led4 = 1;
                delay_ms(100); 
                led4 = 0;
                
                led3 = 1;
                delay_ms(100); 
                led3 = 0;
                    
                led2 = 1;
                delay_ms(100); 
                led2 = 0; 
                
                led1 = 1;
                delay_ms(100); 
                led1 = 0;
            }

        }
}
