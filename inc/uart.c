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

char data_in;

void UART_init(long BaudRate)
{
   
    
    
    U1MODEbits.BRGH=0;
    U1MODEbits.PDSEL=0;
    U1MODEbits.STSEL=0;
    U1MODEbits.ABAUD=0;
    U1BRG=(((float)FCY/BaudRate)/16)-1;
    
    U1STAbits.URXISEL0=0;
    U1STAbits.URXISEL1=0;
    U1STAbits.URXISEL=0;
    
    U1STAbits.UTXEN=1;
    U1MODEbits.UARTEN=1;
    
}

char USART_TransmitChar(char data)
{
    while(U1STAbits.UTXBF== 1);
    U1TXREG=data;
    
}

char USART_ReceiveChar()
{
    
    if(U1STAbits.OERR=1)
    {
        U1STAbits.OERR=0;
        
    }
    if(U1STAbits.URXDA=1)
    {
        return(U1RXREG);
    }
}

void usart_run()
{
     if(U1STAbits.URXDA==1)
        {
           data_in=U1RXREG;
          USART_TransmitChar(data_in);
          
        
        }
     if(data_in=='A')
     {
         LED=1;
     }
     else
     {
         LED=0;
     }
}
