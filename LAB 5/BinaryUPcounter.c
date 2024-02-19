#include<LPC17XX.h>

int main()
{
	unsigned int i;
	unsigned long X=0;
	LPC_PINCON->PINSEL2&=0X0003FFFF;
	LPC_PINCON->PINSEL3&=0XFFFFFFFC;
	LPC_GPIO1->FIODIR|=0X0001FE00;
	while(1)
	{
		LPC_GPIO1->FIOPIN=X<<9;
		for(i=0;i<100000;i++);
		X=X+1;
		if(X==255)
		{
			X=0;
		}
	}
}
