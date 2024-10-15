/*
 * stm32f407xx_TIM.h
 *
 *  Created on: Jun 26, 2024
 *      Author: anast
 */

#ifndef INC_STM32F407XX_TIM_H_
#define INC_STM32F407XX_TIM_H_
#include "stm32f407xx.h"

typedef struct
{
	uint32_t Prescaler;
	uint32_t CounterMode;
	uint32_t Period;
	uint32_t ClockDivision;
	uint32_t RepetitionCounter;


}TIM_Base_Config_t;

typedef struct
{
	TIMX_RegDef_t *pTIMX;
	TIM_Base_Config_t TimxTB;//base time unit config
}TIM_Handel_t;

uint8_t delay(TIMX_RegDef_t *pTIMX, uint16_t delay);
void TIM_init(TIM_Handel_t* TIMX_H);

#endif /* INC_STM32F407XX_TIM_H_ */
