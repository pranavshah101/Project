#include "combined.h"
#include "hardware_declaration.h"
#include "declaration.h"
#include <xc.h>
#include <libpic30.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void LCD_Init()

{

    __delay_ms(1);

    TRISC=0x0000;

    TRISCbits.TRISC8=0;

    TRISCbits.TRISC9=0;

    LCD_Command(0x38);

    //LCD_Command(0x01);

    LCD_Command(0x0c);

    LCD_Command(0x06);

}



void LCD_Command(  char cmd)

{

    ldata=cmd;

    RS=0;

    EN=1;

        __delay_ms(1);

    EN=0;

       __delay_ms(3);

    

}

void LCD_Char(char cmd)

{

   ldata=cmd;

   RS=1;

   EN=1;

    __delay_ms(1);

EN=0;

    __delay_ms(3);

}







void LCD_String(const char *msg)

{

	while((*msg)!=0)

	{		

	  LCD_Char(*msg);

	  msg++;	

    }		

}



void LCD_String_xy(char row,char pos,const char *msg)

{

    char location=0;

    if(row<=1)

    {

        location=(0x80) | ((pos) & 0x0f); /*Print message on 1st row and desired location*/

        LCD_Command(location);

    }

    else

    {

        location=(0xC0) | ((pos) & 0x0f); /*Print message on 2nd row and desired location*/

        LCD_Command(location);    

    }  

    LCD_String(msg);

}



void MSDelay(unsigned int val)

{

    int i,j;

    for(i=0;i<val;i++)

        for(j=0;j<81;j++);

}

void lcd_gotoxy(uint8_t row, uint8_t column)
{
	switch (row) {
	case 1:
		LCD_Command(0x80 + column - 1); break;
	case 2:
		LCD_Command(0xC0 + column - 1); break;
        default:
            LCD_Command(0x80);
            
    }
}

void lcd_print(uint8_t row, uint8_t column, int value, uint8_t digits)
{
	char buffer[8],buffer_of_buffer[5];

	lcd_gotoxy(row,column);
	sprintf(buffer_of_buffer,"%%0%ud",digits);
	sprintf(buffer,buffer_of_buffer,value);
	LCD_String(buffer);
}