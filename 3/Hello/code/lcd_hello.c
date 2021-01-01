/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : LCD_Hello
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



void main(void)
{

DDRA = 0x00;
PORTA = 0x00;

lcd_init(15);

while (1)
      {
            lcd_gotoxy(4,0);
            lcd_putsf("Hello World");

      }
}
