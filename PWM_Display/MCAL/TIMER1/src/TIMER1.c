/*
 * TIMER1.c
 *
 * Created: 1/26/2023 4:11:14 PM
 *  Author: ItShop
 */ 
#include "TIMER1.h"
#include "GLCD.h"

void Timer1_Init(void){
	Timer1_TCCR1A_Reg=0;
	Timer1_TCNT1L_Reg=0;
	Timer1_TCNT1H_Reg=0;
	SetBit(Timer1_TIMSK_Reg,5);  /*Enabling Input Capture INT*/
 	SetBit(Timer1_TIMSK_Reg,2); /*Enabling OVF INT*/
	
}

void Timer1_Input_Capture(Uint16 *Frequency, Uint16 *DutyCycle){
	Uint16 a,b,c,High,Periodic_Time;
	SetBit(Timer1_TIFR_Reg,ICF1);
	Timer1_TCCR1B_Reg = 0x41; /* 01000001 */ /*Rising Edge NO prescaler*/
	while( GetBit(Timer1_TIFR_Reg,ICF1) == 0 ){
		/* Do nothing*/
	}
	a=Timer1_ICR1_Reg;
	
	SetBit(Timer1_TIFR_Reg,ICF1);
	
	Timer1_TCCR1B_Reg=0x01;
	while( GetBit(Timer1_TIFR_Reg,ICF1) == 0 ){
		/* Do nothing*/
	}
	b=Timer1_ICR1_Reg;
	
	SetBit(Timer1_TIFR_Reg,ICF1);
	
	Timer1_TCCR1B_Reg = 0x41; 
	while( GetBit(Timer1_TIFR_Reg,ICF1) == 0 )
	{
		
	}
	c=Timer1_ICR1_Reg;
	
	SetBit(Timer1_TIFR_Reg,ICF1);
	
	Timer1_TCCR1B_Reg =0; /*Stopping Timer*/
	
	
	if(a<b && b<c){
		High = b-a;
		Periodic_Time=c-a;	
		if (Periodic_Time>=246)
		{
			*Frequency = 2*(F_CPU/Periodic_Time) ;
			
			*DutyCycle=((float)High /((float)Periodic_Time))*100;
		}else{
			*Frequency = 65500;
			*DutyCycle=0;
		}
		
		
		
	}	
}