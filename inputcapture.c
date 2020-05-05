#include "declaration.h"
#include "hardware_declaration.h" 
#include "p33fj32mc204.h"
#include "LCD.h"
#include "combined.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


unsigned int times[2] = {0, 0};      // holds IC values
unsigned int iterator = 0;           // array iterator
int period = 0;                      // reading difference for display
char freq_data[20];
float frequency=0;


void init_timer2()
{
    T2CONbits.TON = 0;      // turn timer off to configure
    T2CONbits.TSIDL = 1;    // disable timer in idle mode
    T2CONbits.TGATE = 0;    // disable gating
    T2CONbits.TCKPS = 0b11; // 1:256 prescaler - 69.47us clock
    T2CONbits.T32 = 0;      // 16-bit timer mode
    T2CONbits.TCS = 0;      // FOSC/2
    
    TMR2 = 0;               // start count at 0
    PR2 = 0xffff;           // full count time = 4.55s
    
    T2CONbits.TON = 1;      // turn timer on
}

void icInit()
{
    IC1CONbits.ICM = 0;     // turn IC off to configure
    IC1CONbits.ICSIDL = 1;  // disable in idle mode
    IC1CONbits.ICTMR = 1;   // capture on timer 2
    // IC1CONbits.ICI = 0;     // ignored when detecting all edges
    
    _IC1IP = 1;             // interrupt priority 1
    _IC1IF = 0 ;            // clear IC1 interrupt flag
    _IC1IE = 1;             // enable IC1 interrupt
    
    IC1CONbits.ICM = 1;     // capture on every edge / IC on
}

void _ISR _IC1Interrupt(){
     //LATBbits.LATB15=~ LATBbits.LATB15;
    times[iterator] = IC1BUF;
    iterator++;
    if(iterator == 2)
    {
        iterator = 0;
        if(times[1] > times[0])
            period = times[1] - times[0];
        else
            period = (PR2 - times[0]) + times[1];
        
    }
IFS0bits.IC1IF=0;          // clear interrupt flag;
}

void frequency_display()
{
    frequency=((float)(f_timer)/(float)period*4);
    sprintf(freq_data,"%.2f",frequency);
    strcat(freq_data," Hz");	
    LCD_String_xy(2,1,freq_data);
         

}