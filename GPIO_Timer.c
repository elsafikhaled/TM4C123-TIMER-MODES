#include "GPIO_Timer.h"





//channel A
void GPIO_PortB_TA_Init(gpio_m dir)
{
	//Enable clock for GPIO PIN <PB6> <PB7>.	
   clock_Enable_PORT(Clock_PortB);	
	
	//ckeck lock
	GPIO_PORTB_lock=0x4c4f434b;
	GPIO_PORTB_CR=0x000000C0;
	
	
	//Enable the direction of PORTB pins
if(dir==OUTPUT){	
	GPIO_PORTB_DIR|=(1<<PB6);
}
else if(dir==INPUT){
    GPIO_PORTB_DIR&=~(1<<PB6);
}
	
	//Select alternating Function for PORTB pins as digital
	GPIO_PORTB_AFSEL=0x00;
	
	// Access port functions from control table to timer0.
	GPIO_PORTB_PCTRL=0x00000000;
	
	//Enable digital function for porte pins
	GPIO_PORTB_DEN |=(1<<PB6);
	
	//Turn off Analog function
	GPIO_PORTB_ADCCTRL=0x00;
	

}
//channel B
void GPIO_PortB_TB_Init(gpio_m dir){
	//Enable clock for GPIO PIN <PB6> <PB7>.	
  clock_Enable_PORT(Clock_PortB);	
	
	//ckeck lock
	GPIO_PORTB_lock=0x4c4f434b;
	GPIO_PORTB_CR=0x00000000;
	
	
//Enable the direction of PORTB pins
if(dir==OUTPUT){	
	GPIO_PORTB_DIR|=(1<<PB7);
}
else if(dir==INPUT){
    GPIO_PORTB_DIR&=~(1<<PB7);
}
	
	//Select alternating Function for PORTB pins as digital
	GPIO_PORTB_AFSEL=0x00;
	
	// Access port functions from control table to timer0.
	GPIO_PORTB_PCTRL|=0x00000000;
	
	//Enable digital function for porte pins
	GPIO_PORTB_DEN |=(1<<PB7);
	
	//Turn off Analog function
	GPIO_PORTB_ADCCTRL=0x00;

}

