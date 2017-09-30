#ifndef __GPIO_H__
#define __GPIO_H__
#include "HW_gpio.h"
#include "SysCtrl.h"


// enum 
typedef enum gpio{
	OK=1,
  FAILED=0,
  OUTPUT=2,
  INPUT=3,
	
}gpio_m;



// initialization PORTB for timer 0.

//channel A PB6 
void GPIO_PortB_TA_Init(gpio_m dir);

//channel B PB7
void GPIO_PortB_TB_Init(gpio_m dir);




	
#endif //__GPIO_H__


