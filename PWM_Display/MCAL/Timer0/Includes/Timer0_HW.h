/*
 * Timer0_HW.h
 *
 * Created: 1/22/2023 5:16:09 PM
 *  Author: ItShop
 */ 


#ifndef TIMER0_HW_H_
#define TIMER0_HW_H_

#define Timer0_OCR0_Reg (*(volatile Uint8*)0x5C)
#define Timer0_TIMSK_Reg (*(volatile Uint8*)0x59)
#define Timer0_TIFR_Reg (*(volatile Uint8*)0x58)
#define Timer0_TCCR0_Reg (*(volatile Uint8*)0x53)
#define Timer0_TCNT0_Reg (*(volatile Uint8*)0x52)

#define TIMER0_No_Mode				  (0)
#define TIMER0_Mode_Normal			  (1)
#define TIMER0_Mode_CTC				  (2)
#define TIMER0_Mode_FAST_PWM		  (3)
#define TIMER0_Mode_PWM_PHASE_CORRECT (4)



#endif /* TIMER0_HW_H_ */