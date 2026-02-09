/*
 * stm32f103.h
 *
 *  Created on: Feb 9, 2026
 *      Author: HP
 */

#ifndef STM32F103_H_
#define STM32F103_H_

#include <stdint.h>

/* ===== RCC ===== */
#define RCC_BASE        0x40021000
#define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))
#define RCC_APB1ENR     (*(volatile uint32_t *)(RCC_BASE + 0x1C))

/* ===== GPIO ===== */
#define GPIOA_BASE      0x40010800
#define GPIOB_BASE      0x40010C00
#define GPIOC_BASE      0x40011000

#define GPIO_CRL_OFFSET 0x00
#define GPIO_CRH_OFFSET 0x04
#define GPIO_IDR_OFFSET 0x08
#define GPIO_ODR_OFFSET 0x0C
#define GPIO_BSRR_OFFSET 0x10
#define GPIO_BRR_OFFSET  0x14

#define GPIOA_CRL   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_CRL_OFFSET))
#define GPIOA_CRH   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_CRH_OFFSET))
#define GPIOA_IDR   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_IDR_OFFSET))
#define GPIOA_ODR   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_ODR_OFFSET))
#define GPIOA_BSRR  (*(volatile uint32_t *)(GPIOA_BASE + GPIO_BSRR_OFFSET))
#define GPIOA_BRR   (*(volatile uint32_t *)(GPIOA_BASE + GPIO_BRR_OFFSET))

#define GPIOB_CRL   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_CRL_OFFSET))
#define GPIOB_CRH   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_CRH_OFFSET))
#define GPIOB_IDR   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_IDR_OFFSET))
#define GPIOB_ODR   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_ODR_OFFSET))
#define GPIOB_BSRR  (*(volatile uint32_t *)(GPIOB_BASE + GPIO_BSRR_OFFSET))
#define GPIOB_BRR   (*(volatile uint32_t *)(GPIOB_BASE + GPIO_BRR_OFFSET))

#define GPIOC_CRH   (*(volatile uint32_t *)(GPIOC_BASE + GPIO_CRH_OFFSET))
#define GPIOC_ODR   (*(volatile uint32_t *)(GPIOC_BASE + GPIO_ODR_OFFSET))
#define GPIOC_BSRR  (*(volatile uint32_t *)(GPIOC_BASE + GPIO_BSRR_OFFSET))
#define GPIOC_BRR   (*(volatile uint32_t *)(GPIOC_BASE + GPIO_BRR_OFFSET))

/* ===== TIM2 ===== */
#define TIM2_BASE   0x40000000
#define TIM2_CR1    (*(volatile uint32_t *)(TIM2_BASE + 0x00))
#define TIM2_DIER   (*(volatile uint32_t *)(TIM2_BASE + 0x0C))
#define TIM2_SR     (*(volatile uint32_t *)(TIM2_BASE + 0x10))
#define TIM2_CNT    (*(volatile uint32_t *)(TIM2_BASE + 0x24))
#define TIM2_PSC    (*(volatile uint32_t *)(TIM2_BASE + 0x28))
#define TIM2_ARR    (*(volatile uint32_t *)(TIM2_BASE + 0x2C))






#endif /* STM32F103_H_ */
