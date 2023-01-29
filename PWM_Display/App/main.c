/*
 * PWM_Display.c
 *
 * Created: 12/8/2022 3:47:54 PM
 * Author : ItShop
 */ 
#include "DIO.h"
#include "GLCD.h"
#include "TIMER0.h"
#include "TIMER1.h"
#include "GINT.h"

#include <avr/interrupt.h>
Uint16 freq;
Uint16 Duty=0;
void Drawing_WAVEFORM(Uint8 duty);
int main(void)
{
	Uint8 mode =0,PressCount1=0;
	Uint16 BuiltIN_Freq=0;
	DIO_Init();
	GLCD_Init();
	TIMER0_Init();
	Timer1_Init();
	
	
	
	
	
	
	
	
	while(1){
		while (1)
		{
			GLCD_DisplayString("B1 for input Wave");
			GLCD_GoToNextLine();
			GLCD_DisplayString("B2 For internal Wave");
			GLCD_GoToNextLine();
			GLCD_DisplayString("(Hold Button for 2sec)");
			GLCD_GoToNextLine();
			GLCD_GoToNextLine();
			GLCD_GoToNextLine();
			GLCD_GoToNextLine();
			GLCD_DisplayString("Note:MAX Freq is 65KHz");
			GLCD_DisplayString("Note:MAX Duty in 98%");
			_delay_ms(1000);
			if (DIO_ReadChannel(DIO_ChannelB1)==1 && DIO_ReadChannel(DIO_ChannelB2)==0)
			{
				GLCD_Clear();
				mode=1;
				break;
				}else if(DIO_ReadChannel(DIO_ChannelB1)==0 && DIO_ReadChannel(DIO_ChannelB2)==1){
				GLCD_Clear();
				mode=2;
				break;
			}
			
		}
			
		
		if(mode == 1){
			while (1)
			{
				Timer1_Input_Capture(&freq,&Duty);
				GLCD_DisplayString("Freq:");
				if (freq>65000)
				{
					GLCD_DisplayString("Out of Range!!");
				}else{
					GLCD_DisplayDecimalNumber(freq,5);
					GLCD_DisplayString("Hz");
				}
				
				
				GLCD_GoToLine(1);
				GLCD_DisplayString("Duty:");
				GLCD_DisplayDecimalNumber(Duty,3);
				GLCD_DisplayChar('%');
				Drawing_WAVEFORM(Duty);
				_delay_ms(500);
				
				_delay_ms(500);
				GLCD_Clear();
			}	
		}
		else if(mode ==2) 
		{
			PressCount1=0;
			while(1){
				if (DIO_ReadChannel(DIO_ChannelB4)==1)
				{
					PressCount1++;
					_delay_ms(1000);
				}
				if (DIO_ReadChannel(DIO_ChannelB5) == 1)
				{
					if (Duty>=100)
					{
						Duty=0;
					}
					Duty +=25;
					_delay_ms(700);
					//GLCD_Clear();
				}
				switch(PressCount1){
					case 0 :
					BuiltIN_Freq=61;
					break;
					case  1 :
					BuiltIN_Freq=244;
					break;
					case 2:
					BuiltIN_Freq=976;
					break;
					case 3 :
					BuiltIN_Freq=7812;
					break;
					case 4 :
					BuiltIN_Freq=62500;
					break;
					default:
					BuiltIN_Freq=61;
					break;
				}
				
			    TIMER0_PWM(BuiltIN_Freq,Duty);
				
				GLCD_DisplayString("Freq:");
				if (freq>65000)
				{
					GLCD_DisplayString("Out of Range!!");
					}else{
					GLCD_DisplayDecimalNumber(BuiltIN_Freq,5);
					GLCD_DisplayString("Hz");
				}
				GLCD_GoToLine(1);
				GLCD_DisplayString("Duty:");
				GLCD_DisplayDecimalNumber(Duty,3);
				GLCD_DisplayChar('%');
				
				Drawing_WAVEFORM(Duty);
				_delay_ms(300);
				GLCD_Clear();
			}
			
		
		}
		
		
		
	}
	
}

void Drawing_WAVEFORM(Uint8 duty){
	Uint8 temp=duty;
	if (temp>=0 && temp<=25)
	{
		if(temp == 0){
			GLCD_SetCursor(0,7,0);
			GLCD_DisplayString("_____________________");
		}
		else
		{
		
		GLCD_GoToLine(4);
		GLCD_DisplayChar('_');
		GLCD_DisplayChar('_');
		GLCD_GoToLine(5);
		GLCD_DisplayString("  |");
		GLCD_GoToLine(6);
		GLCD_DisplayString("  |");
		GLCD_GoToLine(7);
		GLCD_DisplayString("  |");
		GLCD_DisplayChar('_');
		GLCD_DisplayChar('_');
		GLCD_DisplayChar('_');
		GLCD_DisplayChar('_');
		GLCD_DisplayChar('_');
		GLCD_DisplayString("|");
		GLCD_SetCursor(0,6,46);
		GLCD_DisplayString("|");
		GLCD_SetCursor(0,5,46);
		GLCD_DisplayString("|");
		GLCD_SetCursor(0,4,50);
		GLCD_DisplayChar('_');
		GLCD_DisplayChar('_');
		
		GLCD_SetCursor(0,5,60);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(0,6,60);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(0,7,60);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(0,7,64);
		GLCD_DisplayString("_____");
		GLCD_SetCursor(1,7,32);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(1,6,32);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(1,5,32);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(1,4,36);
		GLCD_DisplayString("__");
		GLCD_SetCursor(1,5,46);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(1,6,46);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(1,7,46);
		GLCD_DisplayChar('|');
		GLCD_SetCursor(1,7,50);
		GLCD_DisplayString("__");
		}
	}
	else if (temp>25 && temp<49){
			GLCD_GoToLine(4);
			GLCD_DisplayString("___");
			GLCD_SetCursor(0,5,17);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,6,17);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,7,17);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,7,22);
			GLCD_DisplayString("____");
			GLCD_SetCursor(0,7,45);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,6,45);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,5,45);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,4,49);
			GLCD_DisplayString("___");
			GLCD_SetCursor(1,5,1);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,6,1);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,7,1);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,7,6);
			GLCD_DisplayString("____");
			GLCD_SetCursor(1,7,28);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,6,28);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,5,28);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,4,32);
			GLCD_DisplayString("___");
			GLCD_SetCursor(1,5,48);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,6,48);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,7,48);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,7,53);
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
		}
		else if (temp >=49 && temp<=50 )
		{
			
			GLCD_GoToLine(4);
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_GoToLine(5);
			GLCD_DisplayString("      |");
			GLCD_GoToLine(6);
			GLCD_DisplayString("      |");
			GLCD_GoToLine(7);
			GLCD_DisplayString("      |");
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayString("|");
			GLCD_SetCursor(1,6,2);
			GLCD_DisplayString("|");
			GLCD_SetCursor(1,5,2);
			GLCD_DisplayString("|");
			GLCD_SetCursor(1,4,7);
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_SetCursor(1,5,35);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,6,35);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,7,35);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,7,40);
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			GLCD_DisplayChar('_');
			
		}
		else if (temp >50 && temp<=75){
			GLCD_GoToLine(4);
			GLCD_DisplayString("______");
			GLCD_SetCursor(0,5,32);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,6,32);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,7,32);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,7,36);
			GLCD_DisplayString("___");
			GLCD_SetCursor(0,7,52);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,6,52);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,5,52);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(0,4,56);
			GLCD_DisplayString("______");
			GLCD_SetCursor(1,5,26);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,6,26);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,7,26);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,7,30);
			GLCD_DisplayString("___");
			GLCD_SetCursor(1,7,46);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,6,46);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,5,46);
			GLCD_DisplayChar('|');
			GLCD_SetCursor(1,4,50);
			GLCD_DisplayString("__");
		}
		else if (temp >75 && temp<=100){
			GLCD_GoToLine(4);
			GLCD_DisplayString("_____________________");
		}
}