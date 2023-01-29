/*
 * TIMER0.h
 *
 * Created: 1/22/2023 9:13:13 PM
 *  Author: ItShop
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
 #include "TIMER0_cfg.h"
 #include "Timer0_HW.h"
 #include "DIO.h"
 
 /* TIMER OPerating Modes */
 #define TIMER0_Normal            ((Uint8) 0<<3)
 #define TIMER0_CTC               ((Uint8) 1<<3)
 #define TIMER0_FAST_PWM          ((Uint8) 9<<3)
 #define TIMER0_PWM_PHASE_CORRECT ((Uint8) 8<<3)
 /************************/
 
 /*************Timer PRESCALER*****************/
 #define TIMER0_Disabled			  ((Uint8)0)
 #define TIMER0_No_Prescaler		  ((Uint8)1)
 #define TIMER0_8_Prescaling		  ((Uint8)2)
 #define TIMER0_64_Prescaling		  ((Uint8)3)
 #define TIMER0_256_Prescaling		  ((Uint8)4)
 #define TIMER0_1024_Prescaling		  ((Uint8)5)
 #define TIMER0_External_Falling_Edge ((Uint8)6)
 #define TIMER0_External_Rising_Edge  ((Uint8)7)
 /***********************************************/
 
 /* CTC Mode */
 #define TIMER0_CTC_OC0_DISCONNECTED   ((Uint8) 0<<4)
 #define TIMER0_CTC_OC0_TOGGLE		   ((Uint8) 1<<4)
 #define TIMER0_CTC_OC0_CLEAR_ON_Match ((Uint8) 2<<4)
 #define TIMER0_CTC_OC0_SET_ON_MATCH   ((Uint8) 3<<4)
 /***************************************************/
 
 /* FAST PWM MODE*/
 #define TIMER0_FAST_PWM_OC0_DISCONNECTED ((Uint8)0<<4)
 #define TIMER0_FAST_PWM_OC0_NON_INVERTED ((Uint8)2<<4)
 #define TIMER0_FAST_PWM_OC0_INVERTED     ((Uint8)3<<4)
 /****************************************************/
 
 /* PHASE CORRECT PWM*/
 #define TIMER0_PWM_PHASE_CORRECT_OC0_DISCONNECTED	((Uint8)0<<4)
 #define TIMER0_PWM_PHASE_CORRECT_OC0_NON_INVERTED	((Uint8)2<<4)
 #define TIMER0_PWM_PHASE_CORRECT_OC0_INVERTED		((Uint8)3<<4)
 /***************************************************************/
 
 /* INTERRUPTS */
 #define TIMER0_OverFLow_Interrupt      (0)
 #define TIMER0_Compare_Match_Interrupt (1)
 
 /* TIMER MAX Value*/
 #define TIMER0_MaxValue (255u)
 
 
 
 /* FUNCTIONS USED */
 void TIMER0_Init(void);
 void TIMER0_Start(Uint8 prescaler);
 void TIMER0_Stop(void);
 void TIMER0_SetPreload(Uint8 PreLoadVAlue);
 Uint8 TIMER0_GetPreload(void);
 void TIMER0_SetCompareValue(Uint8 Compare_Value);
 void TIMER0_EnableInterrupt(void);
 void TIMER0_DisableInterrupt(void);
 void TIMER0_PWM(Uint16 Frequency , Uint8 DutyCycle);
#endif /* TIMER0_H_ */