#include<LPC17XX.h>

int main()
{
	unsigned long X=0X10;
	unsigned int i;
	LPC_PINCON->PINSEL0&=0XFF0000FF;
	LPC_GPIO0->FIODIR|=0X00000FF0;
	while(1)
	{
		LPC_GPIO0->FIOSET=0X00000FF0;
		for(i=0;i<1000;i++);
		LPC_GPIO0->FIOCLR=0X00000FF0;
		for(i=0;i<1000;i++);
	}
}
