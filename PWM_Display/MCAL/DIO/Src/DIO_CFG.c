/*
 * DIO_CFG.c
 *
 * Created: 9/27/2022 8:40:05 PM
 *  Author: ItShop
 */ 
#include "DIO_cfg.h"

DIO_PinCFG PinCfg[] = {
	//portA
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	//PORTB
	{Output,Low},
	{Input,High},
	{Input,High},
	{Output,High},
	{Input,High},
	{Output,High},
	{Output,High},
	{Output,High},
	//PORTC
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	//PORTD
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Output,High},
	{Input,High},
	{Output,High},	
	};
	
void DIO_Init(void){
	DIO_ChannelType count=DIO_ChannelA0;
	DIO_PortType Portx;
	DIO_ChannelType BitNo ;
	for (count = DIO_ChannelA0 ; count < PinCount; count ++ ){
		Portx = count/8;
		BitNo = count%8;
		switch (Portx){
			
			case DIO_PORTA:
			
			if(PinCfg[count].PinDir == Output){
				
				SetBit(DDRA_Reg,BitNo);
			
			}
			else {
				
				ClearBit(DDRA_Reg,BitNo);
			
			}
			break;
			
			case DIO_PORTB:
			
			if(PinCfg[count].PinDir == Output){
				
				SetBit(DDRB_Reg,BitNo);
				
				}else {
				
				ClearBit(DDRB_Reg,BitNo);
			}
			break;
			
			case DIO_PORTC:
			
			if(PinCfg[count].PinDir == Output){
				
				SetBit(DDRC_Reg,BitNo);
				
				}
				else {
					
				ClearBit(DDRC_Reg,BitNo);
			}
			break;
			
			case DIO_PORTD:
			
			if(PinCfg[count].PinDir == Output){
				
				SetBit(DDRD_Reg,BitNo);
				
				}
				else {
				
				ClearBit(DDRD_Reg,BitNo);
			
			}
			break;
		}
	}
}