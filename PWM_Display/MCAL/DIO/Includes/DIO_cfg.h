/*
 * DIO_cfg.h
 *
 * Created: 9/27/2022 8:32:47 PM
 *  Author: ItShop
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "DIO.h"

typedef struct {
	DIO_DirType PinDir;
	STD_LevelTypes Level;
	}DIO_PinCFG;
	
#define PinCount 32

void DIO_Init(void);

#endif /* DIO_CFG_H_ */