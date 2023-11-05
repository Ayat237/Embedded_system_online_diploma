/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ayat mohamed
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>

typedef volatile unsigned int vuint32_t;

#define RCC_BASE      0x40021000
#define GPIO_PORTA    0x40010800

#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIO_CRH     *(volatile uint32_t *)(GPIO_PORTA + 0x04)
#define GPIO_ODR     *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

typedef union
{
	vuint32_t All_Port;
	struct
	{
		vuint32_t reserved :13;
		vuint32_t pin13 :1;
	}pin;
}ODR_t;

volatile ODR_t *ODR = (volatile ODR_t *)(GPIO_PORTA + 0x0C);

int main(void)
{
	RCC_APB2ENR |= (1<<2); // enable GPIO register
	GPIO_CRH    &= 0xff0fffff; // mask bits from 20 to 23;
	GPIO_CRH    |= 0x00200000;
    while(1)
    {
    	ODR->pin.pin13 = 1;
    	for(int i = 0 ; i <5000 ; i++); //delay
    	ODR->pin.pin13 = 0;
    	for(int i = 0 ; i <5000 ; i++); //delay
    }
}
