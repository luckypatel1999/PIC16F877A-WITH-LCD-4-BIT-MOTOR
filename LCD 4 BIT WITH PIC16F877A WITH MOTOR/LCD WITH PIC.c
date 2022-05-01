/*
 * File:   LCD WITH PIC.c
 * Author: LEO
 *
 * Created on May 1, 2022, 10:35 AM
 */

#define _XTAL_FREQ 1000000
#include <xc.h>

#include<pic16f877a.h>

void Lcd_cmd(char c)
{
	PORTD=c&0xf0;
	PORTD&=~0x01;
	PORTD&=~0x02;
	PORTD|=0x04;
	__delay_ms(5);
	PORTD&=~0x04;
	__delay_ms(5);

	PORTD=c<<4;          //d4 se d7
	PORTD&=~0x01;
	PORTD&=~0x02;
	PORTD|=0x04;
	__delay_ms(5);
	PORTD&=~0x04;
	__delay_ms(5);

}
void Lcd_data(char d)
{
	PORTD=d&0xf0;
	PORTD|=0x01;
	PORTD&=~0x02;
	PORTD|=0x04;
	__delay_ms(5);
	PORTD&=~0x04;
	__delay_ms(5);

	PORTD=d<<4;
	PORTD|=0x01;
	PORTD&=~0x02;
	PORTD|=0x04;
	__delay_ms(5);
	PORTD&=~0x04;
	__delay_ms(5);


}
void Lcd_initial()
{
	Lcd_cmd(0x02);
	Lcd_cmd(0x28);
	Lcd_cmd(0x0c);
	Lcd_cmd(0x06);
	Lcd_cmd(0x01);
	Lcd_cmd(0x80);
}
void Lcd_string(char*ptr)
{
	while (*ptr!='\0')
	{
		Lcd_data(*ptr++);
	}
}

int main(void)

{
    int  i=0;;
    TRISD=0x00;
    TRISC=0x00;
    TRISB=0xFF;
     Lcd_initial();
    Lcd_data('a');
    

while(1)
{
    if((PORTB & 0X08)==0X08)
    {
        i++;
        while((PORTB & 0x08)==0x08);
    }  
        if (i==1)
        {
            PORTC=0X05;
            Lcd_cmd(0x80);
            Lcd_string("press 1 forward");
        }
        if (i==2)
            
        {
            PORTC=0X0a;
            Lcd_cmd(0x01);
            Lcd_cmd(0x80);
            Lcd_string ("press 2 Reverse");
               
        }
        if (i==3)
            
        {
            PORTC=0X09;
            Lcd_cmd(0x01);
            Lcd_cmd(0x80);
            Lcd_string ("press 3 Reverse");
               
        }
        if (i==4)
            
        {
            PORTC=0X06;
            Lcd_cmd(0x01);
            Lcd_cmd(0x80);
            Lcd_string ("press 4 first Reverse 2 nd ");
               
        }
        if (i==5)
            
        {
            PORTC=0X00;
            Lcd_cmd(0x01);
            Lcd_cmd(0x80);
            Lcd_string ("press 8 stop");
               
            i=0;
            
        }
    }
}


