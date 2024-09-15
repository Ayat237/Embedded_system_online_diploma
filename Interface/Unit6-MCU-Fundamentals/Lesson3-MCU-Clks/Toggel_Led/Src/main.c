/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ayat Mohamed
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE    0x40021000

/*
	Bit 2 IOPAEN: IO port A clock enable
	Set and cleared by software.
	0: IO port A clock disabled
	1: IO port A clock enabled
*/
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)


/*
 Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control the division factor of the APB high-speed clock
(PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
 */

/*
 Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
Set and cleared by software to control the division factor of the APB low-speed clock
(PCLK1).
Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16*/
#define RCC_CFGR  *(volatile uint32_t *)(RCC_BASE + 0x04)

#define RCC_CR  *(volatile uint32_t *)(RCC_BASE + 0x00)
int main(void)
{


	RCC_CFGR |=(0b101 << 11); //101: HCLK divided by 4
	RCC_CFGR |=(0b100 << 8); //100: HCLK divided by 2

	//Bits 21:18 PLLMUL: PLL multiplication factor
	RCC_CFGR |=(0b0110 << 18);   //0110: PLL input clock x 8

	//Bits 1:0 SW: System clock switch
	RCC_CFGR |=(0b10 << 0); 	 //10: PLL selected as system clock

	// Bit 24 PLLON: PLL enable
	RCC_CR |=(1<<24);

	//>> Init clock GPIOA <<
	RCC_APB2ENR |= (1 << 2);

	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
