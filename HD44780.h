/* 
 *  HD44780.h - Header file of LCD library
 *  Written by Ercan Ersoy.
 */

#ifndef HD44780_H
#define	HD44780_H

#define _XTAL_FREQ 0

#ifndef _XTAL_FREQ
#error _XTAL_FREQ must be defined.
#endif

#define RS 0
#define RW 0
#define ENABLE 0
#define LCD_PORT 0

#ifndef RS
#error RS must be defined.
#endif

#ifndef RW
#error RW must be defined.
#endif

#ifndef ENABLE
#error ENABLE must be defined.
#endif

#ifndef LCD_PORT
#error LCD_PORT must be defined.
#endif

#define ClearLCD 1
#define BackToBegin 2
#define WriteLeft 4
#define WriteRight 6
#define HideCursor 12
#define SkipCursor 14
#define BlinkCursor 16
#define ShiftRight 24
#define ShiftLeft 28
#define OnOffScreen 8
#define FirstLine 128
#define SecondLine 192
#define GenerateCharacterAddress 64
#define DoubleLine 40
#define SingleLine 32

void lcd_wait(void);
void lcd_send_command(unsigned char command);
void lcd_send_data(unsigned char data);
void lcd_on_off_screen(void);
void lcd_clear(void);
void lcd_print(const char *s);
void lcd_goto_xy(unsigned char x, unsigned char y);
void lcd_prepare(void);

#endif

