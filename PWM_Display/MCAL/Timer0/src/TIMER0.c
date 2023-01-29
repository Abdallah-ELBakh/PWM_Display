/*
 * TIMER0.c
 *
 * Created: 1/22/2023 10:02:50 PM
 *  Author: ItShop
 */ 
#include "TIMER0.h"
 void TIMER0_Init(void){
	 #if (TIMER_Operating_Mode == TIMER0_Mode_Normal ) 
		Timer0_TCCR0_Reg |=TIMER0_Normal;
	 #elif (TIMER_Operating_Mode == TIMER0_Mode_CTC ) 
		Timer0_TCCR0_Reg |=TIMER0_CTC;
	 #elif (TIMER_Operating_Mode == TIMER0_Mode_FAST_PWM ) 
		Timer0_TCCR0_Reg |=TIMER0_FAST_PWM;
	 #elif (TIMER_Operating_Mode == TIMER0_Mode_PWM_PHASE_CORRECT ) 
		Timer0_TCCR0_Reg |=TIMER0_PWM_PHASE_CORRECT;
	 #else
		#error NO MODE ENTERED, GO to TIMER0_cfg.h To choose one

#endif
 }
#if ((TIMER_Operating_Mode == TIMER0_Mode_Normal ) || (TIMER_Operating_Mode == TIMER0_Mode_CTC ))
void TIMER0_Start(Uint8 prescaler)
{
	Timer0_TCCR0_Reg|= prescaler;
	
	
}
void TIMER0_Stop(void)
{
	Timer0_TCCR0_Reg &= 0xF8; // 1111 1000
}
#if (TIMER_Operating_Mode == TIMER0_Mode_Normal )

void TIMER0_SetPreload(Uint8 PreLoadVAlue)
{
	Timer0_TCNT0_Reg = PreLoadVAlue;
}
#endif

Uint8 TIMER0_GetPreload(void)
{
	return Timer0_TCNT0_Reg;
}
void TIMER0_EnableInterrupt(void)
{
	#if (TIMER_Operating_Mode == TIMER0_Mode_Normal )
		SetBit(Timer0_TIMSK_Reg,TIMER0_OverFLow_Interrupt);
	#elif  (TIMER_Operating_Mode == TIMER0_Mode_CTC )
		SetBit(Timer0_TIMSK_Reg,TIMER0_Compare_Match_Interrupt);
#endif
}
void TIMER0_DisableInterrupt(void)
{
	#if (TIMER_Operating_Mode == TIMER0_Mode_Normal )
	ClearBit(Timer0_TIMSK_Reg,TIMER0_OverFLow_Interrupt);
	#elif  (TIMER_Operating_Mode == TIMER0_Mode_CTC )
	ClearBit(Timer0_TIMSK_Reg,TIMER0_Compare_Match_Interrupt);
	#endif
}
#if (TIMER_Operating_Mode == TIMER0_Mode_CTC )

void TIMER0_SetCompareValue(Uint8 Compare_Value)
{
	Timer0_OCR0_Reg = Compare_Value;
}
#endif

#endif

#if ((TIMER_Operating_Mode == TIMER0_Mode_FAST_PWM ) || (TIMER_Operating_Mode == TIMER0_Mode_PWM_PHASE_CORRECT ))
void TIMER0_PWM(Uint16 Frequency , Uint8 DutyCycle)
{
	Timer0_TCCR0_Reg=0x60; /*01100000*/
	Uint16 Result;
	Result =(DutyCycle*TIMER0_MaxValue)/100;
	Timer0_OCR0_Reg = Result;	
	
	
	if(Frequency <=61){
		Timer0_TCCR0_Reg |=TIMER0_1024_Prescaling;
		}
		else if (Frequency >61 && Frequency <=244)
		{
		Timer0_TCCR0_Reg |=TIMER0_256_Prescaling;
		}
		else if (Frequency > 244 && Frequency <= 976)
		{
		Timer0_TCCR0_Reg |=TIMER0_64_Prescaling;
		}
		else if (Frequency >976 && Frequency<=7812)
		{
		Timer0_TCCR0_Reg |=TIMER0_8_Prescaling;
		}
		else if (Frequency >7812 )
		{
		Timer0_TCCR0_Reg |=TIMER0_No_Prescaler;
		}
}
#endif

