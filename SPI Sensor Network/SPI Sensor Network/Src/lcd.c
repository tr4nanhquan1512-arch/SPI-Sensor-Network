/*
 * lcd.c
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */

#include "lcd.h"
#include "I2C.h"
#include "delay.h"

#define LCD_BACKLIGHT 0x08
#define LCD_ENABLE    0x04
#define LCD_RS        0x01

static void LCD_WriteNibble(uint8_t nibble, uint8_t rs)
{
	 uint8_t data = (nibble << 4) | LCD_BACKLIGHT;
	    if (rs) data |= LCD_RS;

	    I2C_Start();
	    I2C_Send_Addr(LCD_ADDR, 0);

	    I2C_Send_Data(data | LCD_ENABLE);
	    delay_us(1);                     // ✅ quan trọng
	    I2C_Send_Data(data & ~LCD_ENABLE);

	    I2C_Stop();
}

static void LCD_WriteByte(uint8_t byte, uint8_t rs)
{
    LCD_WriteNibble(byte >> 4, rs);
    LCD_WriteNibble(byte & 0x0F, rs);
}

void LCD_Init(void)
{
    delay_ms(50);

    LCD_WriteNibble(0x03, 0);
    delay_ms(5);
    LCD_WriteNibble(0x03, 0);
    delay_ms(1);
    LCD_WriteNibble(0x03, 0);
    LCD_WriteNibble(0x02, 0);

    LCD_WriteByte(0x28, 0); // 4bit, 2 line
    LCD_WriteByte(0x0C, 0); // display ON
    LCD_WriteByte(0x06, 0); // entry mode
    LCD_Clear();
}

void LCD_Clear(void)
{
    LCD_WriteByte(0x01, 0);
    delay_ms(2);
}

void LCD_SetCursor(uint8_t row, uint8_t col)
{
    uint8_t addr = (row == 0) ? 0x80 : 0xC0;
    LCD_WriteByte(addr + col, 0);
}

void LCD_Print(char *str)
{
    while (*str)
        LCD_WriteByte(*str++, 1);
}

void LCD_PrintNum(int num)
{
    char buf[10];
    int i = 0;

    if (num == 0)
    {
        LCD_WriteByte('0', 1);
        return;
    }

    if (num < 0)
    {
        LCD_WriteByte('-', 1);
        num = -num;
    }

    while (num)
    {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i--)
        LCD_WriteByte(buf[i], 1);
}

