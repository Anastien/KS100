/*
 * Stm32f407xx_RCC.c
 *
 *  Created on: Jun 18, 2024
 *      Author: anast
 */
#include "stm32f407xx_rcc.h"
void RCC_Init(RCC_Handle_t *pRCChandle )
{
	//MCO2
	pRCChandle->pRCC->CFGR |= (0b11<<21);
	if(pRCChandle->CLK_Config.CLKsrc == HSI)
	{
		pRCChandle->pRCC->CR |= (1<<0);

		while(!(pRCChandle->pRCC->CR&(1<<1)));
	}
	if (pRCChandle->CLK_Config.MPLL[5]== 1)
	{
		pRCChandle->pRCC->CR &= ~(1<<25);
		pRCChandle->pRCC->CR &= ~(1<<27);

		//start PLL Config
		pRCChandle->pRCC->PLLCFGR &=~(0b111111<<0);
		pRCChandle->pRCC->PLLCFGR |=(pRCChandle->CLK_Config.MPLL[0]<<0);

		pRCChandle->pRCC->PLLCFGR &=~(0b111111111<<6);
		pRCChandle->pRCC->PLLCFGR |=(pRCChandle->CLK_Config.MPLL[1]<<6);

		pRCChandle->pRCC->PLLCFGR &=~(0b11<<16);
		pRCChandle->pRCC->PLLCFGR |=(pRCChandle->CLK_Config.MPLL[2]<<16);

		pRCChandle->pRCC->PLLCFGR &=~(1<<22);
		pRCChandle->pRCC->PLLCFGR |=(pRCChandle->CLK_Config.MPLL[3]<<22);

		pRCChandle->pRCC->PLLCFGR &=~(0b1111<<24);
		pRCChandle->pRCC->PLLCFGR |=(pRCChandle->CLK_Config.MPLL[4]<<24);

		//AHB
		pRCChandle->pRCC->CFGR &=~(0b1111<<4);
		pRCChandle->pRCC->CFGR|=(pRCChandle->CLK_Config.HPRE<<4);

		//APB1
		pRCChandle->pRCC->CFGR &=~(0b111<<10);
		pRCChandle->pRCC->CFGR|=(pRCChandle->CLK_Config.PPRE1<<10);

		//APB2
		pRCChandle->pRCC->CFGR &=~(0b111<<13);
		pRCChandle->pRCC->CFGR|=(pRCChandle->CLK_Config.PPRE2<<13);


		pRCChandle->pRCC->CR |= (1<<24);
		while (!(pRCChandle->pRCC->CR & (1 << 25)));

	}

}

