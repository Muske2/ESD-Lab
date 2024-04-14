#include<LPC17xx.h>

#define DT_CTRL 0X07800000
#define RS_CTRL 0X08000000
#define EN_CTRL 0X10000000

unsigned long int init_command[]={0x30,0x30,0x30,0x20,0x28,0x0C,0X06,0X01,0X80};
unsigned long int temp1=0,i,temp2=0;
unsigned char flag1=0,flag2=0,Y=0,Z=0,T=0,X=0,K=0;

void LCD_init();
void lcd_write(void);
void port_write(void);
void delay_led(unsigned int rl);

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
   LPC_PINCON->PINSEL1&=0XFC003FFF;
   LPC_GPIO0->FIODIR|=0X1F800000;
	LPC_PINCON->PINSEL3=0XF<<28;
	LPC_ADC->ADCR=1<<4|1<<5|1<<16|1<<21;
	LPC_ADC->ADINTEN=1<<4|1<<5;
	NVIC_EnableIRQ(ADC_IRQn);
	LCD_init();
	while(1); //wait till interrupt is generated
}

void ADC_IRQHandler(void)
{
	Y=LPC_ADC->ADSTAT&03<<4;
	Y=Y>>4;
	if(Y==1|Y==3)
	{
		X=LPC_ADC->ADDR4&0XFFF<<4;
		X=X>>4;
	}
	else if(Y==2|Y==3)
	{
		Z=LPC_ADC->ADDR5&0XFFF<<4;
		Z=Z>>4;
	}
	T=X-Z;
	temp1=T+'0';
	lcd_write();
	flag1=0;
		  temp1=0x80;
			lcd_write();
			flag1=1;
	K=LPC_ADC->ADGDR&0XFFF<<4;
}
void LCD_init()
{
	flag1=0;
   for(i=0;i<9;i++)
   {
     temp1=init_command[i];
	 lcd_write();
   }
   flag1=1;
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

void delay_led(unsigned int rl)
{
	unsigned int r;
	for(r=0;r<rl;r++);
	return;
}