/* 
 *  LCD_lib.c - Source file of LCD library
 *  Written by Ercan Ersoy.
 */

#include <xc.h>
#include "LCD_lib.h"

void lcd_wait(void)
{
    __delay_ms(200);
}

void lcd_send_command(unsigned char command)
{
    RW = 0;
    RS = 0;
    ENABLE = 1;
    LCD_PORT = command & 0XF0;
    ENABLE = 0;
    lcd_wait();
    ENABLE = 1;
    LCD_PORT = (command & 0X0F) << 4;
    ENABLE = 0;
    lcd_wait();
}

void lcd_send_data(unsigned char data)
{
    RW = 0;
    RS = 1;
    ENABLE = 1;
    LCD_PORT = data & 0XF0;
    ENABLE = 0;
    lcd_wait();
    ENABLE = 1;
    LCD_PORT = (data & 0X0F) << 4;
    ENABLE = 0;
    lcd_wait();
}

void lcd_on_off_screen(void)
{
    lcd_send_command(OnOffScreen);
}

void lcd_clear(void)
{
    lcd_send_command(ClearLCD);
}

void lcd_print(const char *s)
{
    lcd_wait();
    while(*s)
    {
        lcd_send_data(*s++);
    }
}

void lcd_goto_xy(unsigned char x, unsigned char y)
{
    if (x == 0)
    {
        lcd_send_command(FirstLine + (y % 16));
    }
    else if(x == 1)
    {
        lcd_send_command(SecondLine + (y % 16));
    }
}

void lcd_prepare()
{
    RS = 0;
    RW = 0;
    ENABLE = 0;
    __delay_ms(15);
    ENABLE = 1;
    lcd_send_command(0X02);
    __delay_ms(2);
    lcd_send_command(DoubleLine);
    lcd_send_command(WriteLeft);
    lcd_send_command(HideCursor);
    lcd_clear();
    lcd_send_command(FirstLine);
}
