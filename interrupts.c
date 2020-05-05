/*
 * File:   interrupts.c
 * Author: PRANAV
 *
 * Created on 1 May 2020, 9:47 AM
 */


#include "p33FJ32MC204.h"
#include "declaration.h"
#include "combined.h"


extern unsigned int times[2];
extern unsigned int iterator;
extern int period;

void _ISR _IC1Interrupt(){
     LATBbits.LATB15=~ LATBbits.LATB15;
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

