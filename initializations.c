/*
 * File:   configBits.c
 * Author: PRANAV
 *
 * Created on 1 May 2020, 9:42 AM
 */


#include "p33FJ32MC204.h"
#include "combined.h"
#include "declaration.h"

void gpioInit()
{
       TRISBbits.TRISB7=1;
       _CN23PUE = 1;                      // enable pull up resistor on input
       TRISAbits.TRISA10=0;
       TRISAbits.TRISA9=0;
       TRISAbits.TRISA8=0;
       
}



void remapInit(){
    RPINR7bits.IC1R = 7;              // map IC1 to RP7/RB7
    RPINR18bits.U1RXR=5;
    RPOR3bits.RP6R=3;
  
    
    
}



void PWM_Init()
{
    TRISBbits.TRISB9=0;
    TRISBbits.TRISB10=0;
    TRISBbits.TRISB11=0;
    TRISBbits.TRISB12=0;
    TRISBbits.TRISB13=0;
    TRISBbits.TRISB14=0;
    TRISBbits.TRISB15=0;
  PTCONbits.PTOPS = 1; // PWM timer post-scale
  PTCONbits.PTCKPS = 0; // PWM timer pre-scale
  PTCONbits.PTMOD = 0b11; // PWM operates in Up-down Mode continuously
  P1TMR = 0; // PWM counter value, start at 0
  PTPER =PWM_FREQUENCY; // PWM Timebase per
  PWMCON1bits.PMOD3 = 0; // PWM in complimentary mode
  PWMCON1bits.PMOD2 = 0; // PWM in complimentary mode
  PWMCON1bits.PMOD1 = 0; // PWM in complimentary mode
  PWMCON1bits.PEN3H = 1; // PWM High pin is enabled
  PWMCON1bits.PEN2H = 1; // PWM High pin is enable
  PWMCON1bits.PEN1H = 1; // PWM High pin is enabled
  PWMCON1bits.PEN3L = 1; // PWM Low pin enabled (direction control later?)
  PWMCON1bits.PEN2L =1; // PWM Low pin enabled (direction control later?)
  PWMCON1bits.PEN1L =1; // PWM Low pin enabled (direction control later?)
  DTCON1bits.DTAPS = 0;  //DeadTime pre-scaler
  DTCON1bits.DTA =DEAD_TIME;   //DeadTime value for 4 us. 
  PDC1 = DUTY_CYCLE1; // PWM#1 Duty Cycle register (11-bit)
  PDC2 = DUTY_CYCLE2; // PWM#2 Duty Cycle register (11-bit)
  PDC3 = DUTY_CYCLE3; // PWM#3 Duty Cycle register (11-bit)
  
  PTCONbits.PTEN = 1; // Enable PWM Timerbase!
}

void OSC_Init()
{
    PLLFBD=M; 				/* M = PLLFBD + 2 */
	  CLKDIVbits.PLLPOST=0;   /* N1 = 2 */
	   CLKDIVbits.PLLPRE=0;    /* N2 = 2 */
        __builtin_write_OSCCONH(0x01);  //  001 = Fast RC oscillator (FRC) with PLL
        __builtin_write_OSCCONL(0x01);  //  Request oscillator switch to selection

        while(OSCCONbits.COSC != 0b001);	                   //  specified by NOSC<2:0> bits
        while(!OSCCONbits.LOCK); 
}


 
