#include <stdio.h>
#include<stdint.h>
#include<stm32f411xe.h>
#include <uart.h>
#include <adc.h>
#include <systick.h>
#define GPIOAEN			(1U<<0)
int main(void)
{
	RCC->AHB1ENR|=(1U<<0);
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);
	uart2_txrx_init();

	while(1)
	{
		write_string(11,"Loading....");
		GPIOA->ODR^=(1U<<5);
		systickDelayMS(1000);


	}
}

