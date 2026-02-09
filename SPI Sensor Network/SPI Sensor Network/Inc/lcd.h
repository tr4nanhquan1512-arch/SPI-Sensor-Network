/*
 * lcd.h
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */

#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>

#define LCD_ADDR  0x27   // phổ biến, có thể là 0x3F

void LCD_Init(void);
void LCD_Clear(void);
void LCD_SetCursor(uint8_t row, uint8_t col);
void LCD_Print(char *str);
void LCD_PrintNum(int num);

#endif /* LCD_H_ */
