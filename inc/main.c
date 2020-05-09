/*
 * File:   main.c
 * Author: PRANAV
 *
 * Created on 1 May 2020, 9:12 AM
 */

#include "config.h"
#include "combined.h"
#include "p33fj32mc204.h"
#include <string.h>
#include  <xc.h>
#include <stdio.h>
#include  <stdlib.h>
#include <libpic30.h>
#include  "declaration.h"
#include "hardware_declaration.h"

  char k=0;
  int data25;

int main(void)
{
    
    OSC_Init();
    LCD_Init();
    gpioInit();
    remapInit();
    init_timer2();
    icInit();
    ADC_init1();
    init_timer3();
    PWM_Init();
UART_init(9600);
keypad_init();

  
while(1)
{
        
    k=keypad_getc();
    data25=k-48;
          read_adc();
          	//__delay_ms(1);
        frequency_display();
        //	__delay_ms(1);
         
         USART_TransmitChar('2');
         if(k!=0 && k!='B' && k!='C' && k!='D' && k!='*' && k!='#')
         {
            // LCD_Command(0x01);
             //lcd_gotoxy(1,1);
             lcd_print(2,1,data25,1);
             
         }
         	
       
}
      
        
          //USART_TransmitChar('2');
      
  
    return 0;


}
