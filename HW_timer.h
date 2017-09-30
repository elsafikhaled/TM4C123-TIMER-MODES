#ifndef __HW_TIMER_H__
#define __HW_TIMER_H__
#include"data_types.h"


/* **************************************************************************************************** 

Note :: TM4C123G6HPM " ARM CORTEX TM "

The SIZE field in the GPTM Peripheral Properties (GPTMPP) register identifies whether a module
has a 16/32-bit or 32/64-bit wide timer.
Note that the GP Timer module clock must be enabled before the registers can be programmed
(see page 336 or page 355). There must be a delay of 3 system clocks after the Timer module clock
is enabled before any Timer module registers are accessed.



* ****************************************************************************************************/

#define TIMER0_16_32_BASE             0x40030000
#define TIMER1_16_32_BASE             0x40031000
#define TIMER2_16_32_BASE             0x40032000
#define TIMER3_16_32_BASE             0x40033000
#define TIMER4_16_32_BASE             0x40034000
#define TIMER5_16_32_BASE             0x40035000


#define TIMER0_WIDE_32_64_BASE        0x40036000
#define TIMER1_WIDE_32_64_BASE        0x40037000
#define TIMER2_WIDE_32_64_BASE        0x4004C000
#define TIMER3_WIDE_32_64_BASE        0x4004D000
#define TIMER4_WIDE_32_64_BASE        0x4004E000
#define TIMER5_WIDE_32_64_BASE        0x4004F000

//Timer_0 16/32bit registers.

#define TIMER0_16_32_GPTMCFG           *((volatile U32_t*)0x40030000)
#define TIMER0_16_32_GPTMTAMR          *((volatile U32_t*)0x40030004)
#define TIMER0_16_32_GPTMTBMR          *((volatile U32_t*)0x40030008)
#define TIMER0_16_32_GPTMCTL           *((volatile U32_t*)0x4003000c)
#define TIMER0_16_32_GPTMSYNC          *((volatile U32_t*)0x40030010)
#define TIMER0_16_32_GPTMIMR           *((volatile U32_t*)0x40030018)
#define TIMER0_16_32_GPTMRIS           *((volatile U32_t*)0x4003001c)
#define TIMER0_16_32_GPTMMIS           *((volatile U32_t*)0x40030020)
#define TIMER0_16_32_GPTMICR           *((volatile U32_t*)0x40030024)
#define TIMER0_16_32_GPTMTAILR         *((volatile U32_t*)0x40030028)
#define TIMER0_16_32_GPTMTBILR         *((volatile U32_t*)0x4003002c)
#define TIMER0_16_32_GPTMTAMATCHR      *((volatile U32_t*)0x40030030)
#define TIMER0_16_32_GPTMTBMATCHR      *((volatile U32_t*)0x40030034)
#define TIMER0_16_32_GPTMTAPR          *((volatile U32_t*)0x40030038)
#define TIMER0_16_32_GPTMTBPR          *((volatile U32_t*)0x4003003c)
#define TIMER0_16_32_GPTMTAPMR         *((volatile U32_t*)0x40030040)
#define TIMER0_16_32_GPTMTBPMR         *((volatile U32_t*)0x40030044)
#define TIMER0_16_32_GPTMTAR           *((volatile U32_t*)0x40030048)
#define TIMER0_16_32_GPTMTBR           *((volatile U32_t*)0x4003004c)
#define TIMER0_16_32_GPTMTAV           *((volatile U32_t*)0x40030050)
#define TIMER0_16_32_GPTMTBV           *((volatile U32_t*)0x40030054)
#define TIMER0_16_32_GPTMRTCPD         *((volatile U32_t*)0x40030058)
#define TIMER0_16_32_GPTMTAPS          *((volatile U32_t*)0x4003005c)
#define TIMER0_16_32_GPTMTBPS          *((volatile U32_t*)0x40030060)
#define TIMER0_16_32_GPTMTAPV          *((volatile U32_t*)0x40030064)
#define TIMER0_16_32_GPTMTBPV          *((volatile U32_t*)0x40030068)
#define TIMER0_16_32_GPTMPP            *((volatile U32_t*)0x40030fc0)

//! interrupt NVIC register for interrupt request from  0 to 31 

#define TIMER0A_16_32_NVIC            *((volatile U32_t*)0xE000E100)













#endif //__HW_TIMER_H__



