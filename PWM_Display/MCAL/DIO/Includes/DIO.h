/*
 * DIO.h
 *
 * Created: 9/26/2022 8:41:10 PM
 *  Author: ItShop
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_cfg.h"
#include "Clock.h"

void DIO_WriteChannel(DIO_ChannelType ChannelId,STD_LevelTypes Level);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelType ChannelId);
Uint8 DIO_ReadPort(DIO_PortType PortId);
void DIO_WritePort (DIO_PortType PortID,Uint8 data);
void DIO_ConfigureChannel(DIO_ChannelType ChannelId,DIO_DirType Direction);

#endif /* DIO_H_ */