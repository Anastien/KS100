/*
 * lcd.h
 *
 *  Created on: Mar 20, 2024
 *      Author: anast
 */

#ifndef INC_LCDHAL_H_
#define INC_LCDHAL_H_

#include "stm32f407xx.h"
typedef struct
{
	uint32_t  L1[20];
	uint32_t  L2[20];

}LCD_matrix_t;

void UpdateLCD();


void LCD_Init();


void LCD_Config();
void LCD_Onoff(uint8_t ENorDI);
void LCD_DisplayAllPnts(uint8_t ENorDI);
#endif /* INC_LCDHAL_H_ */
