#include<LPC17xx.h>
#include<stdio.h>

unsigned char sevseg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned int row,key,col,flag=0;
unsigned long X,i;
void disp(int key);
void scan(void);

int main()
{
	LPC_PINCON->PINSEL3&=0XFFC03FFF;
	LPC_PINCON->PINSEL4&=0XF00FFFFF;
	LPC_PINCON->PINSEL0&=0X3F0000FF;
	LPC_PINCON->PINSEL1&=0XFFFFFFC0;
	
	LPC_GPIO0->FIODIR|=0X00078FF0;
	LPC_GPIO1->FIODIR|=0X00000000;
	LPC_GPIO2->FIODIR|=0X00003C00;
	
	for(row=0;row<4;row++)
	{
		LPC_GPIO2->FIOPIN=1<<(10+row);
		flag=0;
		scan();
		if(flag==0xff)
		{
			key=4*row+col;
			disp(key);
		}
	}
}

void scan()
{
	X=LPC_GPIO1->FIOPIN&=(0XFF<<23);
	if(X!=0)
	{
		flag=0xff; //means key is pressed
		X=X>>23;
		if(X==1)
		{
			col=0;
		}
		if(X==2)
		{
			col=1;
		}
		if(X==4)
		{
			col=2;
		}
		if(X==8)
		{
			col=3;
		}
	}
}

void disp(int key)
{
	LPC_GPIO0->FIOMASK=0XFFFFF00F;
	LPC_GPIO0->FIOPIN=sevseg[key]<<4;
	for(i=0;i<5000;i++);
}
