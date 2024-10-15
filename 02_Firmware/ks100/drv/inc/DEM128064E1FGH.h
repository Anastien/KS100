/*
 * DEM128064E1FGH.h
 *
 *  Created on: Jun 15, 2024
 *      Author: anast
 */

#ifndef INC_DEM128064E1FGH_H_
#define INC_DEM128064E1FGH_H_
#include <stdint.h>
/*
 * DEM128064E1FGH.c
 *
 *  Created on: Jun 15, 2024
 *      Author: anast
 */


void LCD_Config();

void LCD_Onoff(uint8_t ENorDI);

void LCD_StrtLineAddr(uint8_t Addr);

void LCD_PageAddr(uint8_t Addr);

void LCD_ClmnAddr(uint8_t Addr, uint8_t MS);

void LCD_DataWrite(uint8_t Data);

void LCD_ADC(uint8_t EnorDi);

void LCD_Orint(uint8_t EnorDi);


void LCD_DisplayAllPnts(uint8_t ENorDI);



void LCD_Bias();

void LCD_KlmnIncrmnt();

void LCD_End();

void LCD_Rst();

void LCD_PwrConfig();

void LCD_RbRa();

void LCD_SttkIndkt(uint8_t EnorDi);

void LCD_BstMult();
void LCD_Evol();





#endif /* INC_DEM128064E1FGH_H_ */
