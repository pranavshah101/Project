/*
 * File:   uart.c
 * Author: PRANAV
 *
 * Created on 4 May 2020, 11:54 AM
 */


#include "declaration.h"
#include "hardware_declaration.h"
#include "combined.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "p33fj32mc204.h"

void init_usart_polling(long BaudRate)
{
    U1MODEbits.UARTEN=1;
    U1MODEbits.USIDL=0;
    U1MODEbits.RTSMD=1;
    U1MODEbits.UEN=1;
    U1MODEbits.WAKE=1;
    U1MODEbits.LPBACK=0;
    U1MODEbits.URXINV=0;
    U1MODEbits.BRGH=0;
    U1MODEbits.PDSEL=0;
    U1MODEbits.STSEL=0;
    U1STAbits.UTXINV=0;
    U1STAbits.UTXBRK=0;
    U1STAbits.UTXEN=1;
    U1STAbits.ADDEN=0;
    
    U1BRG=(FCY/(16*(BaudRate)))-1;
    
    
}

void envia_character (unsigned char data)
{
    U1TXREG=data;
    while(U1STAbits.TRMT==0)
    {
        
    }
}
void usart_puts(char *data)
{
    while (*data)
    envia_character(*(data++));
}

void usart_run()
{
    usart_puts("HELLO LABOTEC\r\n");
    MSDelay(100);
}