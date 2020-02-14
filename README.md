# PIC MPLABX HD44780 Library

Copyright (C) 2020 Ercan Ersoy

This LCD library is useful for more LCD applications.

This LCD library licensed by CC0-1.0 Universal License.

## Usage

This library supports only 2 row or 4 row LCDs. But, this library
doesn't support 40x4 dual controller LCDs.

This library supports only 4 byte data connection.

_XTAL_FREQ, RS, RW, ENABLE and LCD_PORT must be defined at "HD44780.h"
header file.

### void lcd_wait(void)

Wait for screen for send command or send data.

### void lcd_send_command(unsigned char command)

Send screen command.

### void lcd_send_data(unsigned char data)

Send screen data.

### void lcd_on_off_screen(void)

On or off screen.

### void lcd_clear(void)

Clear screen and put cursor on home position.

### void lcd_print(const char *s)

Print a string on screen.

### void lcd_goto_xy(unsigned char x, unsigned char y)

Put cursor to specified position.

### void lcd_prepare(void)

Initialize for screen for usage.

## Note

MPLAB is a registered trademark of Microchip Technology Incorporated.

PIC is a registered trademark of Microchip Technology Incorporated.
