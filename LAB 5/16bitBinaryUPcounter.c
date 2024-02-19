#include<LPC17XX.h>

int main()
{
	unsigned int i;
	unsigned long X=0;
	LPC_PINCON->PINSEL4&=0X0003FFFF;
	LPC_PINCON->PINSEL5&=0XFFFC0000;
	LPC_GPIO2->FIODIR|=0X01FFFE00;
	while(1)
	{
		LPC_GPIO2->FIOPIN=X<<9;
		for(i=0;i<1000;i++);
		X=X+1;
		if(X==65535)
		{
			X=0;
		}
	}
}
