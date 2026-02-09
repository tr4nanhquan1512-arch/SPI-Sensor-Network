#include "stm32f103.h"
#include "LED.h"

#define LED_PIN 13

void LED_Init(void)
{
    /* Enable clock GPIOC (bit 4 APB2ENR) */
    RCC_APB2ENR |= (1 << 4);

    /*
     * PC13 → CRH, bits [23:20]
     * MODE = 01 (Output 10 MHz)
     * CNF  = 00 (Push-pull)
     * => 0b0001
     */

    GPIOC_CRH &= ~(0xF << 20);   // Clear
    GPIOC_CRH |=  (0x1 << 20);   // Output PP 10MHz
}

void LED_On(void)
{
    /* PC13 active LOW on Blue Pill */
    GPIOC_BRR = (1 << LED_PIN);
}

void LED_Off(void)
{
    GPIOC_BSRR = (1 << LED_PIN);
}

void LED_Toggle(void)
{
    GPIOC_ODR ^= (1 << LED_PIN);
}
