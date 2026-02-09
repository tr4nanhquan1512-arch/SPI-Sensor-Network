/*
 * delay.c
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */


#include "delay.h"

#include "delay.h"

/*
 * Delay microsecond
 * 72MHz → 1 us ≈ 72 cycles
 * 1 vòng for ~ 9 cycles (xấp xỉ)
 */
void delay_us(uint32_t us)
{
    while (us--)
    {
        for (volatile uint32_t i = 0; i < 8; i++)
        {
            __asm volatile ("nop");
        }
    }
}

/*
 * Delay millisecond
 */
void delay_ms(uint32_t ms)
{
    while (ms--)
    {
        delay_us(1000);
    }
}
