#include "p33fj32mc204.h"
#include "declaration.h"
// intializations
extern void gpioInit();
extern void remapInit();

//input capture functions 
extern void init_timer2();
extern void icInit();
extern void frequency_display();

//PWM intialiaztions
extern void PWM_Init();
extern void led_blink();
//ADC functions
extern void ADC_init1();
extern void read_adc();
extern void  init_timer3();

//LCD functions
extern void LCD_Init();
extern void LCD_Command(char );
extern void LCD_Char(char );
extern void LCD_String(const char *);
extern void MSDelay(unsigned int );
extern void LCD_String_xy(char ,char ,const char *);

//UART COMMUNICATIONS
extern char USART_TransmitChar(char);
extern char USART_ReceiveChar();
extern void UART_init(long);

 //extern void receive_character();


// interrupts
extern void _ISR _IC1Interrupt();
extern void __attribute__((interrupt, no_auto_psv)) _ADC1Interrupt(void);