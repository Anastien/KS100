/*
 * Stm32f407xx_RCC.h
 *
 *  Created on: Jun 18, 2024
 *      Author: anast
 */

#ifndef INC_STM32F407XX_RCC_H_
#define INC_STM32F407XX_RCC_H_
#include "stm32f407xx.h"


typedef struct {
	uint8_t CLKsrc;
	uint16_t MPLL[6]; // format 0>M, 1>N, 2>P, 3>SRC, 4>Q, 5>PLLONOFF
	uint8_t HPRE; //AHB
	uint8_t PPRE1; //APB1
	uint8_t PPRE2; //APB2


}CLK_Config_t;

typedef struct
{
	RCC_RegDef_t *pRCC ;
	CLK_Config_t CLK_Config;
}RCC_Handle_t;

void RCC_Init(RCC_Handle_t *pRCChandle );


#endif /* INC_STM32F407XX_RCC_H_ */
