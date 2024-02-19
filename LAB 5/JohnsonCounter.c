#include<LPC17XX.h>

int main()
{
	unsigned int i,j;
	unsigned long X=0X00000010;
	LPC_PINCON->PINSEL0&=0XFF0000FF;
	LPC_GPIO0->FIODIR|=0X00000FF0;
	for(j=0;j<8;j++)
	{
		LPC_GPIO0->FIOSET|=X;
		for(i=0;i<1000;i++);
		X=X<<1;
	}
	X=0X00000010;
	for(j=0;j<8;j++)
	{
		LPC_GPIO0->FIOCLR|=X;
		for(i=0;i<1000;i++);
		X=X<<1;
	}
}
