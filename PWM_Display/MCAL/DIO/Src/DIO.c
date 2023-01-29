/*
 * DIO.c
 *
 * Created: 9/26/2022 9:17:15 PM
 *  Author: ItShop
 */ 
#include "DIO.h"


void DIO_WriteChannel(DIO_ChannelType ChannelId,STD_LevelTypes Level){
	DIO_PortType PORTx = ChannelId/8;
	DIO_ChannelType BitNo = ChannelId%8;
	switch(PORTx){
		case DIO_PORTA:
			if(Level == High){
				SetBit(PORTA_Reg,BitNo);
			}else{
				ClearBit(PORTA_Reg,BitNo);
			}
		
		break;
		
		case DIO_PORTB:
		if(Level == High){
			SetBit(PORTB_Reg,BitNo);
			}else{
			ClearBit(PORTB_Reg,BitNo);
		}
		
		break;
		
		case DIO_PORTC:
		if(Level == High){
			SetBit(PORTC_Reg,BitNo);
			}else{
			ClearBit(PORTC_Reg,BitNo);
		}
		
		break;
		
		case DIO_PORTD:
		if(Level == High){
			SetBit(PORTD_Reg,BitNo);
			}else{
			ClearBit(PORTD_Reg,BitNo);
		}
		break;
	}
}
STD_LevelTypes DIO_ReadChannel(DIO_ChannelType ChannelId){
	DIO_PortType PORTx = ChannelId/8;
	DIO_ChannelType BitNo = ChannelId%8;
	STD_LevelTypes BitValue = Low;
	switch(PORTx){
		case DIO_PORTA :
			BitValue =GetBit(PINA_Reg,BitNo);
		break;
		
		case DIO_PORTB :
		BitValue =GetBit(PINB_Reg,BitNo);
		break;
		
		case DIO_PORTC :
		BitValue =GetBit(PINC_Reg,BitNo);
		break;
		
		case DIO_PORTD :
		BitValue =GetBit(PIND_Reg,BitNo);
		break;
	}
	return BitValue;
}

Uint8 DIO_ReadPort(DIO_PortType PortId){
	Uint8 ID = 0;
	switch(PortId){
		
		case DIO_PORTA :
		ID = PORTA_Reg;
		break ;
		
		case DIO_PORTB :
		ID = PORTB_Reg;
		break ;
		
		case DIO_PORTC :
		ID = PORTC_Reg;
		break ;
		
		case DIO_PORTD :
		ID = PORTD_Reg;
		break ;
	}
	return ID ;
}

void DIO_WritePort (DIO_PortType PortID,Uint8 data){
	switch (PortID){
		case DIO_PORTA :
		PORTA_Reg = data ; 
		break;
		case DIO_PORTB:
		PORTB_Reg= data ;
		break;
		case DIO_PORTC:
		PORTC_Reg = data ;
		break;
		case DIO_PORTD:
		PORTD_Reg = data ;
		break;
	}
}

void DIO_ConfigureChannel(DIO_ChannelType ChannelId,DIO_DirType Direction){
	DIO_PortType Portx = ChannelId/8;
	DIO_ChannelType BitNo = ChannelId%8;
	switch (Portx)
	{
		case DIO_PORTA:
		if (Direction == Output)
		{
			SetBit(DDRA_Reg,BitNo);
		}
		else{
			ClearBit(DDRA_Reg,BitNo);
		}
		break;
		case DIO_PORTB:
		if (Direction == Output)
		{
			SetBit(DDRB_Reg,BitNo);
		}
		else{
			ClearBit(DDRB_Reg,BitNo);
		}
		break;
		case DIO_PORTC:
		if (Direction == Output)
		{
			SetBit(DDRC_Reg,BitNo);
		}
		else{
			ClearBit(DDRC_Reg,BitNo);
		}
		break;
		case DIO_PORTD:
		if (Direction == Output)
		{
			SetBit(DDRD_Reg,BitNo);
		}
		else{
			ClearBit(DDRD_Reg,BitNo);
		}
		break;
	}
}