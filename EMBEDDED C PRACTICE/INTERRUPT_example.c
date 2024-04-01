#include<LPC17xx.h>

unsigned int X=0;
void Timer0_IRQHandler(void)
void timer_init();

void main()
{
	LPC_PINCON->PINSEL0=0;
	LPC_PINCON->PINSEL1=0;
	LPC_GPIO0->FIODIR=1<<5|0<<8|0XFF<<15;
	timer_init();
	while(1)
	{
		X=LPC_GPIO0->FIOPIN&1<<8;
		if(X)
		{
			LPC_GPIO0->FIOPIN=0XFF<<15;
		}
		else
		{
			LPC_GPIO0->FIOPIN=0<<15;
		}
	}
}

void Timer0_IRQHandler(void)
{
	LPC_GPIO0->FIOMASK=0XFFFFFFDF;
	LPC_GPIO0->FIOPIN=~(LPC_GPIO0->FIOPIN);
	LPC_GPIO0->FIOMASK=1<<5;
	LPC_TIM0->IR=1<<0;
}
void timer_init()
{
	LPC_TIM0->TCR=2;
	LPC_TIM0->CTCR=0;
	LPC_TIM0->MR0=499999;
	LPC_TIM0->PR=2;
	LPC_TIM0->MCR=1<<0|1<<1;
	NVIC_EnableIRQ(Timer0_IRQn);
	LPC_TIM0->TCR=1;
}