#ifndef __TIMER0_H__
#define __TIMER0_H__
#include"data_types.h"


              /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~   timer    16/32 bit modes   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//Configuration enum.
typedef enum config{
	//need a trigger to start counting.
	Trig_ON=0,
	Trig_OFF=1,
	//Interrupt mode.
	In_En_match=2,
	In_Dis_match=3,
	In_En_TimeOut=14,
	In_Dis_TimeOut=15,
	//Counter direction.
	Up=4,
	Down=5,
	//Modes
	OneShot=6,
	Periodic=7,
	Counter=17,
	Timer=20,
	//Channels
	A_CH=8,
	B_CH=9,
	ALL_CH=10,
	//error
    error=55,	
}Config_m;

                                          //Timer0 modes//

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ over shot and periodic  modes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//initialization function for overshot and periodic .
void Timer0_OvSh_Per_init(U32_t load,Config_m interrupt,Config_m channel,Config_m mode);
/*
Note::
Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
the status flags are cleared by writing a 1 to the appropriate bit of the GPTM Interrupt Clear
Register (GPTMICR).

*/

//initialization function for input capture edges count or time.
void Timer0_EdgeCap_CT_init(U32_t load,Config_m interrupt,Config_m channel,Config_m mode);


void timer0A(void);

//Read counter value.
U32_t Timer0_Count(Config_m channel);


///////////////////////////////////////////////////////// END  ////////////////////////////////////////////






#endif //__TIMER_H__

