#include"Timer0.h"
#include"SysCtrl.h"
#include"GPIO_Timer.h"
#include"HW_timer.h"



void timer0A(void){
		
//Enable the clock to Timer 0.
Clock_Enable_Timer(Timer0);

//! Timer 0 registers setup.

//pass 0 to configure register.	
TIMER0_16_32_GPTMCFG=0x4;	
//Initialize the GPIO PORT.	
GPIO_PortB_TA_Init(OUTPUT);	
//disable the A channel.
TIMER0_16_32_GPTMCTL&=~(1<<0);	
TIMER0_16_32_GPTMTAMR|=0x2;	
//The timer counts up. When counting up, the timer starts from a value 0x00.
TIMER0_16_32_GPTMTAMR|=(1<<4);
//interrupt config	
TIMER0_16_32_GPTMIMR|=(1<<0);
TIMER0_16_32_GPTMICR|=(1<<0);
//enable NVIC interrupt for A_CH.
TIMER0A_16_32_NVIC|=(1<<19);
//loading value that timer will count until reach it.
TIMER0_16_32_GPTMTAILR=0x0000ffff;

//match register.
TIMER0_16_32_GPTMTAMATCHR=0x00;

//Timer capacity 16bit.
TIMER0_16_32_GPTMPP=0x00;

//Timer 0 A_CH enable.
TIMER0_16_32_GPTMCTL|=(1<<0);
}

void Timer0_OvSh_Per_init(U32_t load,Config_m interrupt,Config_m channel,Config_m mode){//start the function.

//Enable clock for GPIO PIN <PB6> <PB7>.	
clock_Enable_PORT(Clock_PortB);		
	
//Enable the clock to Timer 0.
Clock_Enable_Timer(Timer0);

//Timer 0 registers setup.

//pass 0 to configure register.	
TIMER0_16_32_GPTMCFG =0x00;

if(channel==A_CH){
//Initialize the GPIO PORT.	
GPIO_PortB_TA_Init(OUTPUT);	
//disable the A channel.
TIMER0_16_32_GPTMCTL&=~(1<<0);	

//mode select.
	if(mode==OneShot){
		TIMER0_16_32_GPTMTAMR|=0x1;
	}
	else if(mode==Periodic){
		TIMER0_16_32_GPTMTAMR|=0x2;
	}
//The timer counts up. When counting up, the timer starts from a value 0x00.
TIMER0_16_32_GPTMTAMR|=(1<<4);	
//interrupt mode select.
    if(interrupt==In_En_match){
		TIMER0_16_32_GPTMTAMR|=(1<<5);
		TIMER0_16_32_GPTMIMR|=(1<<4);
		TIMER0_16_32_GPTMICR|=(1<<4);
		//enable NVIC interrupt for A_CH.
		TIMER0A_16_32_NVIC|=(1<<19);
	} 
    else if(interrupt==In_En_TimeOut){
		TIMER0_16_32_GPTMIMR|=(1<<0);
		TIMER0_16_32_GPTMICR|=(1<<0);
		//enable NVIC interrupt for A_CH.
		TIMER0A_16_32_NVIC|=(1<<19);
	}
//loading value that timer will count until reach it.
TIMER0_16_32_GPTMTAILR=load;

//match register.
TIMER0_16_32_GPTMTAMATCHR=0x00;

//Timer capacity 16bit.
TIMER0_16_32_GPTMPP=0x00;

//Timer 0 A_CH enable.
TIMER0_16_32_GPTMCTL|=(1<<0);
	
}//End of if-Channel A.	


else if(channel==B_CH){
//initialize GPIO B.	
GPIO_PortB_TB_Init(OUTPUT);	
//disable the B channel.
TIMER0_16_32_GPTMCTL&=~(1<<8);	

//mode select.
	if(mode==OneShot){
		TIMER0_16_32_GPTMTBMR|=0x1;
	}
	else if(mode==Periodic){
		TIMER0_16_32_GPTMTBMR|=0x2;
	}
//The timer counts up. When counting up, the timer starts from a value 0x00.
TIMER0_16_32_GPTMTBMR|=(1<<4);	
//interrupt mode select.
    if(interrupt==In_En_match){
		TIMER0_16_32_GPTMTBMR|=(1<<5);
		TIMER0_16_32_GPTMIMR|=(1<<4);
		TIMER0_16_32_GPTMICR|=(1<<11);
		//enable NVIC interrupt for B_CH.
		TIMER0A_16_32_NVIC|=(1<<20);
	} 
    else if(interrupt==In_En_TimeOut){
		TIMER0_16_32_GPTMIMR|=(1<<0);
		TIMER0_16_32_GPTMICR|=(1<<8);
		//enable NVIC interrupt for B_CH.
		TIMER0A_16_32_NVIC|=(1<<20);
		
	}
//loading value that timer will count until reach it.
TIMER0_16_32_GPTMTBILR=load;

//match register.
TIMER0_16_32_GPTMTBMATCHR=0x00;

//Timer capacity 16bit.
TIMER0_16_32_GPTMPP=0x00;

//Timer 0 B_CH enable.
TIMER0_16_32_GPTMCTL|=(1<<8);	

}//End of else if-Channel B.	
	
}//End of init function.


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ edge capture functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Timer0_EdgeCap_CT_init(U32_t load,Config_m interrupt,Config_m channel,Config_m mode){

//Enable clock for GPIO PIN <PB6> <PB7>.	
clock_Enable_PORT(Clock_PortB);		

//Enable the clock to Timer 0.
Clock_Enable_Timer(Timer0);

//Timer 0 registers setup.

//pass 0 to configure register.	
TIMER0_16_32_GPTMCFG =0x4;

if(channel==A_CH){
//Initialize the GPIO PORT.	
GPIO_PortB_TA_Init(INPUT);	
//disable the A channel.
TIMER0_16_32_GPTMCTL&=~(1<<0);	

//mode select capture.
TIMER0_16_32_GPTMTAMR|=(1<<0)|(1<<1);

	if(mode==Counter){
		TIMER0_16_32_GPTMTAMR&=~(1<<2);
	}
	else if(mode==Timer){
		TIMER0_16_32_GPTMTAMR|=(1<<2);
	}
//The timer counts up. When counting up, the timer starts from a value 0x00.
TIMER0_16_32_GPTMTAMR|=(1<<4);	
//interrupt mode select.
    if(interrupt==In_En_match){
		TIMER0_16_32_GPTMTAMR|=(1<<5);
		TIMER0_16_32_GPTMIMR|=(1<<4);
		//enable NVIC interrupt for A_CH.
		TIMER0A_16_32_NVIC|=(1<<19);
	} 
    else if(interrupt==In_En_TimeOut){
		TIMER0_16_32_GPTMIMR|=(1<<0);
		//enable NVIC interrupt for A_CH.
		TIMER0A_16_32_NVIC|=(1<<19);
	}
//loading value that timer will count until reach it.
TIMER0_16_32_GPTMTAILR=load;

//match register.
TIMER0_16_32_GPTMTAMATCHR=0x00;

//Timer capacity 16bit.
TIMER0_16_32_GPTMPP=0x00;

//Timer 0 A_CH enable.
TIMER0_16_32_GPTMCTL|=(1<<0);
	
}//End of if-Channel A.	


else if(channel==B_CH){
//initialize GPIO
GPIO_PortB_TB_Init(INPUT);	
//disable the B channel.
TIMER0_16_32_GPTMCTL&=~(1<<8);	

//mode select.
//mode select capture.
TIMER0_16_32_GPTMTBMR|=(1<<0)|(1<<1);

	if(mode==Counter){
		TIMER0_16_32_GPTMTBMR&=~(1<<2);
	}
	else if(mode==Timer){
		TIMER0_16_32_GPTMTBMR|=(1<<2);
	}
//The timer counts up. When counting up, the timer starts from a value 0x00.
TIMER0_16_32_GPTMTBMR|=(1<<4);	
//interrupt mode select.
    if(interrupt==In_En_match){
		TIMER0_16_32_GPTMTBMR|=(1<<5);
		TIMER0_16_32_GPTMIMR|=(1<<4);
		//enable NVIC interrupt for B_CH.
		TIMER0A_16_32_NVIC|=(1<<20);
	} 
    else if(interrupt==In_En_TimeOut){
		TIMER0_16_32_GPTMIMR|=(1<<0);
		//enable NVIC interrupt for B_CH.
		TIMER0A_16_32_NVIC|=(1<<20);
	}
//loading value that timer will count until reach it.
TIMER0_16_32_GPTMTBILR=load;

//match register.
TIMER0_16_32_GPTMTBMATCHR=0x00;

//Timer capacity 16bit.
TIMER0_16_32_GPTMPP=0x00;

//Timer 0 B_CH enable.
TIMER0_16_32_GPTMCTL|=(1<<8);	

}//End of else if-Channel B.	
	
	
	
	
	
	
	
}//End of function of edge capture.

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Read counter functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
//channel A & B.
U32_t Timer0_Count(Config_m channel){
//Fill function here.
if(channel==A_CH){	
    return TIMER0_16_32_GPTMTAR;	
}

else if(channel==B_CH){
    return TIMER0_16_32_GPTMTBR;	
}	
	
else{
	return error; 
}	
}//End of function.	




