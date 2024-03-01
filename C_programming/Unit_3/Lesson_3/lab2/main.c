/*
 ******************************************************************************
 * @file           : main.c
 * @author         : ayat mohamed
 * @brief          : Main program body
 ******************************************************************************
 */

#include<stdint.h>

typedef volatile unsigned int vuint32_t;

//register addersses
#define RCC_BASE    0x40021000
#define PORTA_BASE  0x40010800

#define RCC_APP2NR  *((volatile uint32_t *)(RCC_BASE   + 0x18))
#define GPIO_CRH    *((volatile uint32_t *)(PORTA_BASE + 0x04))
#define GPIO_ODR    *((volatile uint32_t *)(PORTA_BASE + 0x0C))

typedef union
{
	vuint32_t all_bits;
	struct
    {
	vuint32_t reserved:13;//from 0->12
	vuint32_t pin13:1;

	}pin;

}R_ODR_T;

volatile R_ODR_T *R_ODR = (volatile R_ODR_T *)(PORTA_BASE + 0x0C);
unsigned char g_var[3] = {1,2,3};   //for data section 
unsigned char const const_var[3] = {1,2,3}; //for row data section
unsigned char bss_var[3] ; 

int main(void)
{
	RCC_APP2NR |= (1<<2);
	GPIO_CRH   &= 0xFF0FFFFF;
	GPIO_CRH   |= 0x00200000;
	while(1)
	{
		R_ODR->pin.pin13 = 1;
		for(int i = 0 ; i<50000 ; i++);
		R_ODR->pin.pin13 = 0;
		for(int i = 0 ; i<50000 ; i++);
	}
	return 0;
}
