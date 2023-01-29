/*
 * GLCD.h
 *
 * Created: 12/23/2022 10:07:06 PM
 *  Author: ItShop
 */ 


#ifndef GLCD_H_
#define GLCD_H_
#include "DIO.h"
#include <avr/io.h>

/***************************************************************************************************
                                 GLCD PORT Configuration
 ***************************************************************************************************/
#define M_GlcdDataBus	PORTA_Reg
#define M_GlcdDataBusDirection DDRA_Reg
#define M_GlcdDataBusInput PINA_Reg

#define M_GlcdControlBus PORTC_Reg
#define M_GlcdControlBusDirection DDRC_Reg

#define GLCD_RS 2
#define GLCD_RW 1
#define GLCD_EN 0
#define GLCD_RST 3
#define GLCD_CS1 5
#define GLCD_CS2 4
#define GLCD_D7 7

/***************************************************************************************************
                           Port Direction configurations
 ***************************************************************************************************/
#define C_PinOutput     0x01u
#define C_PinInput      0x00u
#define C_PortOutput    0xffu
#define C_PortInput     0x00u
/**************************************************************************************************/


#define M_GlcdClearBit(x)   ClearBit((M_GlcdControlBus),(x))
#define M_GlcdSetBit(x)     SetBit((M_GlcdControlBus),(x))


#define  util_GetBitMask(bit)          (1<<(bit))
#define  util_BitSet(x,bit)            ((x) |=  util_GetBitMask(bit))
#define  util_BitClear(x,bit)          ((x) &= ~util_GetBitMask(bit))
#define  util_BitToggle(x,bit)         ((x) ^=  util_GetBitMask(bit))
#define  util_UpdateBit(x,bit,val)     ((val)? util_BitSet(x,bit): util_BitClear(x,bit))


#define  util_GetBitStatus(x,bit)      (((x)&(util_GetBitMask(bit)))!=0u)
#define  util_IsBitSet(x,bit)          (((x)&(util_GetBitMask(bit)))!=0u)
#define  util_IsBitCleared(x,bit)      (((x)&(util_GetBitMask(bit)))==0u)


#define  util_AreAllBitsSet(x,BitMask) (((x)&(BitMask))==BitMask)
#define  util_AreAnyBitsSet(x,BitMask) (((x)&(BitMask))!=0x00u)

/***************************************************************************************************
                             Macros to find the mod of a number
 ***************************************************************************************************/
#define util_GetMod8(dividend,divisor)  (Uint8) (dividend - (divisor * (Uint8) (dividend/divisor)))
#define util_GetMod16(dividend,divisor) (Uint16)(dividend - (divisor * (Uint16)(dividend/divisor)))
#define util_GetMod32(dividend,divisor) (unsigned int)(dividend - (divisor * (unsigned int)(dividend/divisor)))
/***************************************************************************************************/

//macro for Decimal to Ascii
#define util_Dec2Ascii(Dec)	 ((Dec)+0x30)
/*


PreCompile configuration to enable or disable the API's.
1.Required interfaces can be enabled/disabled by configuring its respective macros to 1/0.
2. By default all the API's are enabled except for FLOAT display.
3. Displaying of floating number takes huge controller resources and need to be enabled only
if required. This implies for other interfaces as well.
***************************************************************************************************/
#define    Enable_GLCD_DisplayString          1
#define    Enable_GLCD_DisplayDecimalNumber   1
#define    Enable_GLCD_DisplayHexNumber       1
#define    Enable_GLCD_DisplayBinaryNumber    1
#define    Enable_GLCD_DisplayFloatNumber     0
#define    Enable_GLCD_Printf                 1
#define    Enable_GLCD_DisplayLogo            1
/**************************************************************************************************/



/***************************************************************************************************
                             Commonly used LCD macros/Constants
***************************************************************************************************/
#define BlankSpace ' '

#define C_GlcdDisplayDefaultDigits_U8            0xffu // Will display the exact digits in the number
#define C_GlcdMaxDigitsToDisplay_U8              10u   // Max decimal/hexadecimal digits to be displayed
#define C_GlcdNumOfBinDigitsToDisplay_U8         16u   // Max bits of a binary number to be displayed
#define C_GlcdMaxDigitsToDisplayUsingPrintf_U8   C_GlcdDisplayDefaultDigits_U8 /* Max dec/hexadecimal digits to be displayed using printf */


#define C_GlcdFirstLine_U8 0x00u
#define C_GlcdLastLine_U8 0x07u
#define C_FirstLineNumberAddress_U8 0xB8
#define C_LastLineNumberAddress_U8  0xBF


#define C_MaxBarGraphs_U8 0x04
#define C_LookUpOffset_U8 0x20
/**************************************************************************************************/



/***************************************************************************************************
                                 Struct/Enums used
 ***************************************************************************************************/
typedef struct{
	Uint8 PageNum;
	Uint8 LineNum;
	Uint8 CursorPos;
	Uint8 Invertdisplay;
}GLCD_Config;
/**************************************************************************************************/
void ClrScreen(void);



void GLCD_Init();
void GLCD_Clear();
void GLCD_SetCursor(Uint8 pageNumber,Uint8 lineNumber,Uint8 CursorPosition);
void GLCD_GetCursor(Uint8 *page_ptr,Uint8 *line_ptr,uint8_t *cursor_ptr);
void GLCD_GoToPage(Uint8 pageNumber);
void GLCD_GoToLine(Uint8 var_lineNumber_u8);
void GLCD_GoToNextLine();
void GLCD_EnableDisplayInversion();
void GLCD_DisableDisplayInversion();
void GLCD_DisplayChar(Uint8 var_lcdData_u8);
void GLCD_DisplayString(int8 *ptr_stringPointer_u8);
void GLCD_ScrollMessage(Uint8 var_lineNumber_u8, char *ptr_msgPointer_u8);
void GLCD_DisplayDecimalNumber(Uint16 var_DecNumber_u32, Uint8 var_numOfDigitsToDisplay_u8);
void GLCD_DisplayHexNumber(Uint8 var_hexNumber_u32,Uint8 var_numOfDigitsToDisplay_u8);
void GLCD_DisplayBinaryNumber(Uint8 var_binNumber_u32, Uint8 var_numOfBitsToDisplay_u8);
void GLCD_DisplayFloatNumber(double var_floatNum_f32);
void GLCD_Printf(const char *argList, ...);
void GLCD_DisplayLogo();
void GLCD_DisplayVerticalGraph(Uint8 var_barGraphNumber_u8, Uint8 var_percentageValue_u8);
void GLCD_DisplayHorizontalGraph(Uint8 var_barGraphNumber_u8, Uint8 var_percentageValue_u8);



#endif /* GLCD_H_ */