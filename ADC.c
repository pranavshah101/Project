/*
 * File:   ADC.c
 * Author: PRANAV
 *
 * Created on 4 May 2020, 9:51 AM
 */


#include "declaration.h"
#include "hardware_declaration.h"
#include "p33fj32mc204.h"
#include "LCD.h"
#include "combined.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int var=0,var1=0,var3=0,var4=0,var5=0,var6=0;
unsigned long data[20], data1[20],data2[20],data3[20],data4[20],data5[20];
float voltage=0,voltage1=0,voltage3=0,voltage4=0,voltage5=0,voltage6=0;
int ain0Buff[SAMP_BUFF_SIZE];
int  ain1Buff[SAMP_BUFF_SIZE];
int ain2Buff[SAMP_BUFF_SIZE];
int  ain3Buff[SAMP_BUFF_SIZE];
int ain4Buff[SAMP_BUFF_SIZE];
int ain5Buff[SAMP_BUFF_SIZE];
int ain6Buff[SAMP_BUFF_SIZE];
int ain7Buff[SAMP_BUFF_SIZE];
int ain8Buff[SAMP_BUFF_SIZE];
int sampleCounter=0;
int scanCounter=0;

void ADC_init1()
 {
    AD1CON1bits.FORM=0;
     AD1CON2bits.VCFG=0;
     AD1CON1bits.SSRC=3;
     AD1CON1bits.ASAM=1;
     AD1CON1bits.AD12B=1;
     AD1CON2bits.ALTS=0;
     AD1CON2bits.CSCNA=1;//1
     AD1CON2bits.CHPS=0;
     AD1CON3bits.ADRC=0;
     AD1CON3bits.ADCS=63;//63
     AD1CON3bits.SAMC=0;  //0
     AD1CON1bits.SIMSAM=0;
     AD1CON2bits.SMPI=0;
    AD1CHS0bits.CH0SA=3;
     AD1CHS0bits.CH0NA=0;
     AD1CHS123bits.CH123SA=0;
     AD1CHS123bits.CH123NA=0;
     AD1CSSLbits.CSS0=1;
    AD1CSSLbits.CSS1=1;
     AD1CSSLbits.CSS2=1;
     AD1CSSLbits.CSS3=1;     //AD1CSSLbits.CSS2=1;
     AD1CSSLbits.CSS4=1;
     AD1CSSLbits.CSS5=1;
     //AD1CSSLbits.CSS6=1;
    // AD1CSSLbits.CSS7=1;
  //   AD1CSSLbits.CSS8=1;
     //AD1CSSLbits.CSS4=1;
     //AD1CSSLbits.CSS5=1;
    // AD1CSSLbits.CSS3=1;
    //AD1CSSLbits.CSS4=1;
    
     AD1PCFGL=0xFFFF;
     AD1PCFGLbits.PCFG0=0;
     AD1PCFGLbits.PCFG1=0;
     AD1PCFGLbits.PCFG2=0;
     AD1PCFGLbits.PCFG3=0;
     AD1PCFGLbits.PCFG4=0;
     AD1PCFGLbits.PCFG5=0;
    // AD1PCFGLbits.PCFG6=0;
     //AD1PCFGLbits.PCFG7=0;
     //AD1PCFGLbits.PCFG8=0;
    // AD1PCFGLbits.PCFG4=0;
     //AD1PCFGLbits.PCFG5=0;
     IFS0bits.AD1IF=0;
     IEC0bits.AD1IE=1;
     AD1CON1bits.ADON=1;
    
    
     
 }


 void init_timer3()
 {
     TMR3=0x0000;
     PR3=4999;
     IFS0bits.T3IF=0;
     IEC0bits.T3IE=0;
     T3CONbits.TON=1;
     
 }
 
void read_adc()
{
    
    var=(ain0Buff[sampleCounter]);
      voltage=var*((float)vref/(float)4095); 
      if(voltage >=1.65)
      {
          ADC4=1;
      }
       else
       {
          ADC4=0;
       }
       
      var1=(ain1Buff[sampleCounter]);
      voltage1=var1*((float)vref/(float)4095); 
      if(voltage1 >=1.65)
       {
          ADC5=1;
       }
      else
       {
          ADC5=0;
       }
        var3=(ain2Buff[sampleCounter]);
        voltage3=var3*((float)vref/(float)4095); 
        if  (voltage3>=1.65)
        {
            ADC6=1;
        }
        else
        {
            ADC6=0;
        }
        var4=(ain3Buff[sampleCounter]);
        voltage4=var4*((float)vref/(float)4095); 
        sprintf(data3,"%.2f",voltage4);
        strcat(data3," V");	
        LCD_String_xy(2,8,data3);
        
        var5=(ain4Buff[sampleCounter]);
        voltage5=var5*((float)vref/(float)4095); 
        sprintf(data4,"%.2f",voltage5);
        strcat(data4," V");	
        LCD_String_xy(1,1,data4);
         
        var6=(ain5Buff[sampleCounter]);
        voltage6=var6*((float)vref/(float)4095);
        sprintf(data5,"%.2f",voltage6);
        strcat(data5," V");	
        LCD_String_xy(1,8,data5);
}


void __attribute__((interrupt, no_auto_psv)) _ADC1Interrupt(void)
{
    switch(scanCounter)
    {
        case 0:
            ain0Buff[sampleCounter]=ADC1BUF0;
            break;
        case 1:
            ain1Buff[sampleCounter]=ADC1BUF0;
            break;
        case 2:
            ain2Buff[sampleCounter]=ADC1BUF0;
            break;
        case 3:
            ain3Buff[sampleCounter]=ADC1BUF0;
            break;
        case 4:
            ain4Buff[sampleCounter]=ADC1BUF0;
            break;
        case 5:
            ain5Buff[sampleCounter]=ADC1BUF0;
            break;
            
        default:
            break;
    }
    scanCounter=scanCounter+1;
   if(scanCounter==6)
    {
        scanCounter=0;
        sampleCounter=sampleCounter+1;
       
    }
  if(sampleCounter==SAMP_BUFF_SIZE)
    {
		sampleCounter=0;
}
  
   
    
    IFS0bits.AD1IF = 0;	
}

