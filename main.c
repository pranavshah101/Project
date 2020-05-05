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
#include <stdio.h>
#include  <stdlib.h>
#include <libpic30.h>
#include  "declaration.h"
#include "hardware_declaration.h"


char data_in;



 


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
   
    
  while(1)
  {
   
        
         read_adc();
         frequency_display();
         
        if(U1STAbits.URXDA==1)
        {
           data_in=U1RXREG;
          USART_TransmitChar(data_in);
        
        }
       
        
  }         
    return 0;

}
