#ifndef DECLARATION_H
#define DECLARTION_H

#include <p33fj32mc204.h>

#define PWM_FREQUENCY   2666
#define DUTY_CYCLE1     1333
#define DUTY_CYCLE2     1333
#define DUTY_CYCLE3     1333
#define DEAD_TIME        4
#define M                41
#define f_timer         21000
#define vref            3.30
#define  SAMP_BUFF_SIZE	 8 
#define FCY             40000000
#define  SETLCD_4BITS_2LINE    	0b00101000
#define  DISPLAY_ALL_ON				0b00001111
#define  DISPLAY_ON_D_OFF_CB		0b00001100
#define  DISPLAY_ON_D_ON_C_OFF_B	0b00001110
#define  DISPLAY_ON_D_OFF_C_ON_B	0b00001101
#define	 EMS_INC_S			0b00000110
#define	DISP_MOVE_RIGHT		0b00011100
#define	DISP_MOVE_LEFT		0b00011000
#define	CURSOR_MOVE_RIGHT	0b00010100
#define	CURSOR_MOVE_LEFT	0b00010000
#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54
#define	 RETURN_HOME		0b00000010
#define  CLEAR_DISPLAY   	0b00000001



#endif