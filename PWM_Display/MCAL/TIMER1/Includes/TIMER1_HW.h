/*
 * TIMER1_HW.h
 *
 * Created: 1/26/2023 3:58:44 PM
 *  Author: ItShop
 */ 


#ifndef TIMER1_HW_H_
#define TIMER1_HW_H_


#define Timer1_TCCR1A_Reg (*(volatile Uint8*)0x4F)
#define Timer1_TCCR1B_Reg (*(volatile Uint8*)0x4E)
#define Timer1_TCNT1L_Reg (*(volatile Uint8*)0x4C)
#define Timer1_TCNT1H_Reg (*(volatile Uint8*)0x4D)

#define Timer1_TCNT1_Reg (*(volatile Uint16*)0x4C)

#define Timer1_OCR1AL_Reg (*(volatile Uint8*)0x4A)
#define Timer1_OCR1AH_Reg (*(volatile Uint8*)0x4B)
#define Timer1_OCR1BL_Reg (*(volatile Uint8*)0x48)
#define Timer1_OCR1BH_Reg (*(volatile Uint8*)0x49)

#define Timer1_ICR1H_Reg  (*(volatile Uint8*)0x47)
#define Timer1_ICR1L_Reg  (*(volatile Uint8*)0x46)
#define Timer1_ICR1_Reg  (*(volatile Uint16*)0x46)

#define Timer1_TIMSK_Reg  (*(volatile Uint8*)0x59)

#define Timer1_TIFR_Reg   (*(volatile Uint8*)0x58)
#endif /* TIMER1_HW_H_ */