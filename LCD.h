
#ifndef LCD_H
#define	LCD_H

#include <p33fj32mc204.h>

#define RS LATCbits.LATC8
#define EN LATCbits.LATC9
#define ldata LATC

void LCD_Init();
void LCD_Command(char );
void LCD_Char(char );
void LCD_String(const char *);
void MSDelay(unsigned int );
void LCD_String_xy(char ,char ,const char *);

#endif	/* LCD_8BIT_FILE_H */

