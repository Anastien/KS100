/*
 * stm32f407xx_TIM.c
 *
 *  Created on: Jun 26, 2024
 *      Author: anast
 */
#include "Stm32f407xx_tim.h"



uint8_t delay(TIMX_RegDef_t *pTIMX, uint16_t delay)
{
	// delay in mS.
	//pTIMX->CR[0] |= (1<<3); // One-Pulse Mode
	pTIMX->ARR = (delay); // setting the delay
	pTIMX->CR[0] |= (1<<7);
	pTIMX->CR[0] |= (1<<0);// Counter Enable, start timer.
	while( !(pTIMX->SR & 1<<0)); // check for update event (counter target reached )
	pTIMX->CR[0] &=~ (1<<0);// Counter dISABLE
	pTIMX->SR &=~ (1<<0);// status dISABLE
	return 1;

}


void TIM_init(TIM_Handel_t* TIMX_H)
{
	//Clock EN
	if(TIMX_H->pTIMX == TIM6)
	{
		RCC->APB1ENR |= (1<<4);
	}

	//init
	TIMX_H->pTIMX->PSC |= (uint16_t)TIMX_H->TimxTB.Prescaler;
	TIMX_H->pTIMX->ARR |= (uint16_t)TIMX_H->TimxTB.Period;

}
