#include<LPC17xx.h>
#define DT_CTRL 0X07800000
#define RS_CTRL 0X08000000
#define EN_CTRL 0X10000000

unsigned long int init_command[]={0x30,0x30,0x30,0x20,0x28,0x0C,0X06,0X01,0X80};
unsigned long int temp1=0,i,temp2=0,X=0,a,row,col,key;
unsigned char flag1=0,flag2=0,flag=0;

void lcd_write(void);
void port_write(void);
void delay_led(unsigned int rl);
void scan(void);


int main()
{
	
	 SystemInit();
	 SystemCoreClockUpdate();
	 LPC_PINCON->PINSEL3&=0XFFC03FFF;
	 LPC_PINCON->PINSEL4&=0XF00FFFFF;
   LPC_PINCON->PINSEL1&=0XFC003FFF;
   LPC_GPIO0->FIODIR|=0X1F800000;
	 LPC_GPIO1->FIODIR=0X00000000;
	 LPC_GPIO2->FIODIR|=0X00003C00;
	 
   flag1=0;
   for(i=0;i<9;i++)
   {
     temp1=init_command[i];
	 lcd_write();
   }
   flag1=1;
   while(1)
   {
      for(row=0;row<4;row++)
	{
		LPC_GPIO2->FIOPIN=1<<(10+row);
		flag=0;
		scan();
		if(flag==0xff)
		{
			key=4*row+col;
			a=key+'0';
			temp1=a;
			lcd_write();
			flag1=0;
		  temp1=0x80;
			lcd_write();
			flag1=1;
		}
	}
   }
}

void lcd_write()
{
  flag2=(flag1==1)?0:((temp1==0x30)||(temp1==0x20))?1:0;
  temp2=temp1&0xF0;
  temp2=temp2<<19;
  port_write();
  if(!flag2)
  {
    temp2=temp1&0x0F;
	  temp2=temp2<<23;
	  port_write();
  }
}

void port_write()
{
  LPC_GPIO0->FIOPIN=temp2;
  if(flag1==0)
  {
    LPC_GPIO0->FIOCLR=RS_CTRL;
  }
  else
	{
		LPC_GPIO0->FIOSET=RS_CTRL;
	}
	LPC_GPIO0->FIOSET=EN_CTRL;
	delay_led(25);
	LPC_GPIO0->FIOCLR=EN_CTRL;
	delay_led(50000);
}

void scan()
{
	X=LPC_GPIO1->FIOPIN&=(0XF<<23);
	if(X!=0)
	{
		flag=0xff;
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
void delay_led(unsigned int rl)
{
	unsigned int r;
	for(r=0;r<rl;r++);
	return;
}
