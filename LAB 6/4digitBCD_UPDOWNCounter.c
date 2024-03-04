#include<LPC17xx.h>
#include<stdio.h>
//switch 7 pe hota hai
unsigned int flag=0x00,count=0,flag2=0x00;
unsigned char sevseg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
unsigned int digit_value[6]={0,0,0,0,0};
unsigned int dig_count;
unsigned int select_segment[6]={0,0<<23,1<<23,2<<23,3<<23};
unsigned long int temp1,temp2,i=0,X;
void disp(void);
void delay(void);
void upcounter(void);
void downcounter(void);
int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0=0;
	LPC_PINCON->PINSEL3=0;
	LPC_PINCON->PINSEL4=0;
	LPC_GPIO2->FIODIR&=0XFFFFFFFE;
	LPC_GPIO0->FIODIR=0X00000FF0;
	LPC_GPIO1->FIODIR=0X07800000;
	
	while(1)
	{
		delay();
		dig_count+=1;
		if(dig_count==0x05)
		{
			dig_count=0x00;
			dig_count++;
		}
		if(flag==0xFF)
		{
			flag=0;
			X=LPC_GPIO2->FIOPIN&1<<0;
			if(X)
			{
				upcounter();
			}
			else
			{
				downcounter();
			}
				
		}
      disp();
	}
}

void disp(void)
{
	LPC_GPIO1->FIOPIN=select_segment[dig_count];
	LPC_GPIO0->FIOPIN=sevseg[digit_value[dig_count]]<<4;
	
	for(i=0;i<500;i++);
	
	LPC_GPIO0->FIOCLR=0X00000FF0;
}


void delay(void)
{
	for(i=0;i<1000;i++);
	if(count==2000)
	{
		flag=0xFF;
		count=0;
	}
	else
	{
		count++;
	}
}

void upcounter(void)
{
	digit_value[1]++;
	if(digit_value[1]>9)
	{
		digit_value[1]=0;
		digit_value[2]++;
		if(digit_value[2]>9)
		{
			digit_value[2]=0;
			digit_value[3]++;
			if(digit_value[3]>9)
		{
			digit_value[3]=0;
			digit_value[4]++;
			if(digit_value[4]>9)
		{
			digit_value[4]=0;
		}
		}
		}
	}
}

void downcounter(void)
{
	digit_value[1]--;
	if(digit_value[1]==-1)
	{
		digit_value[1]=9;
		digit_value[2]--;
		if(digit_value[2]==-1)
		{
			digit_value[2]=9;
			digit_value[3]--;
			if(digit_value[3]==-1)
			{
				digit_value[3]=9;
				digit_value[4]--;
				if(digit_value[4]==-1)
				{
					digit_value[4]=9;
				}
			}
		}
	}
}
