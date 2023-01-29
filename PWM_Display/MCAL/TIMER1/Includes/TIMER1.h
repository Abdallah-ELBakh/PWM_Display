/*
 * TIMER1.h
 *
 * Created: 1/26/2023 4:09:50 PM
 *  Author: ItShop
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "DIO.h"
#include "TIMER1_HW.h"


void Timer1_Init(void);
void Timer1_Input_Capture(Uint16 *Frequency, Uint16 *DutyCycle);





#define ICF1 5

/*TIMER1 TCCR1B */
#define ICES1 6
#define CS10  0
#define CS11  1
#define CS12  2


#endif /* TIMER1_H_ */