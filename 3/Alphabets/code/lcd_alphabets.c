/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : LCD_Alphabets
Version : 
Date    : 01/01/2021
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12/000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>

// Alphanumeric LCD functions
#include <alcd.h>

char alph[40] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int TimerOverFlowCounter;
int x;
int y;
int i;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
      ++ TimerOverFlowCounter;

      if(TimerOverFlowCounter ==1000){
          lcd_putchar('');
          lcd_putchar(alph[i]);
          i++;
          x=x+1;

            if(x == 16){
            x=0;
            y=1;
             }

            lcd_gotoxy(x,y);
            TimerOverFlowCounter=0;

            if(i == 26){
              TCCR0=0x00;
              TIMSK=0x00;
            }

       }

      TCNT0=0x00;

}


void main(void)
{

    DDRA=0x00;
    PORTA=0x00;
    x=0;
    y=0;
    TimerOverFlowCounter=0;
    i = 0;
    TCCR0=0x01;
    TCNT0=0x00;
    OCR0=0x00;
    TIMSK=0x01;
    lcd_init(16);
    #asm("sei");


while (1)
      {

      }
}
