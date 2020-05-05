#include "p33fj32mc204.h"
#include "declaration.h"
// functions
extern void gpioInit();
extern void remapInit();
extern void init_timer2();
extern void icInit();
extern void PWM_Init();
extern void led_blink();
extern void ADC_init1();
extern void read_adc();
extern void  init_timer3();
extern void LCD_Init();
extern void LCD_Command(char );
extern void LCD_Char(char );
extern void LCD_String(const char *);
extern void MSDelay(unsigned int );
extern void LCD_String_xy(char ,char ,const char *);
extern void frequency_display();
 extern void init_usart_polling(long);
 extern void envia_character (unsigned char);
 extern void usart_puts(char *);
 extern void usart_run();


// interrupts
extern void _ISR _IC1Interrupt();
extern void __attribute__((interrupt, no_auto_psv)) _ADC1Interrupt(void);