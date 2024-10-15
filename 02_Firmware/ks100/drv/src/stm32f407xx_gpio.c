/*
 * stm32f407xx_gpio.c
 *
 *  Created on: Jan 23, 2024
 *      Author: anast
 */

#include "stm32f407xx_gpio.h"




void GPIO_Init(GPIO_Handel_t *pGPIOhandel)

{
	GPIO_PeriClockControl(pGPIOhandel->pGPIOX, ENABLE);
	//mode
	if ( (pGPIOhandel->GPIO_PinConfig.GPIO_PinMode) <= GPIO_MODE_ANALOG)// non-interupt mode
	{
		pGPIOhandel->pGPIOX->MODER &= ~((0x3) << (pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber *2));
		pGPIOhandel->pGPIOX->MODER |= ((pGPIOhandel->GPIO_PinConfig.GPIO_PinMode) << (pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber *2));
	}
	else //Interrupt modes
	{
		if ( (pGPIOhandel->GPIO_PinConfig.GPIO_PinMode) == GPIO_MODE_IT_FT)
		{
			EXTI->FTSR |=(1<<pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber );
			EXTI->RTSR &=~(1<<pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber );
		}
		else if ( (pGPIOhandel->GPIO_PinConfig.GPIO_PinMode) == GPIO_MODE_IT_RT)
		{
			EXTI->RTSR |=(1<<pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber );
			EXTI->FTSR &=~(1<<pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber );
		}
		else if ( (pGPIOhandel->GPIO_PinConfig.GPIO_PinMode) <= GPIO_MODE_IT_RfT)
		{
			EXTI->FTSR |=(1<<pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber );
			EXTI->FTSR |=(1<<pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber );
		}
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber/4] &= ~(0)<<(4*pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber%4);
		SYSCFG->EXTICR[pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber/4] |= (PORTCODE(pGPIOhandel->pGPIOX))<<(4*pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber%4);
		EXTI->IMR |= (1<<pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber );
	}
	//speed
	pGPIOhandel->pGPIOX->OPEEDR &= ~((0x3) << (pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber *2));
	(pGPIOhandel->pGPIOX->OPEEDR) |= ((pGPIOhandel->GPIO_PinConfig.GPIO_PinSpeed)<<((pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber *2)));

	//PUPD
	pGPIOhandel->pGPIOX->PUPDR &= ~((0x3) << (pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber *2));
	pGPIOhandel->pGPIOX->PUPDR |=(pGPIOhandel->GPIO_PinConfig.GPIO_PiPuPdControl)<<((pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber *2));
	//out type
	pGPIOhandel->pGPIOX->OTYPER &= ~((0x1) << (pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber *1));
	pGPIOhandel->pGPIOX->OTYPER |=(pGPIOhandel->GPIO_PinConfig.GPIO_PinOPType)<<((pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber *1));
	// ALT FN
	if ( pGPIOhandel->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		switch(pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber/8)
		{
		case 0:
			//AFR LOW
			pGPIOhandel->pGPIOX->AFR[0] &= ~((0xf) << (4 * pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber));
			pGPIOhandel->pGPIOX->AFR[0] |= ((pGPIOhandel->GPIO_PinConfig.GPIO_PinAltFunMode) << (4 * pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber));

		case 1:
			//AFR High
			pGPIOhandel->pGPIOX->AFR[1] &= ~((0xf) << (4 * (pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber-8)));
			pGPIOhandel->pGPIOX->AFR[1] |= ((pGPIOhandel->GPIO_PinConfig.GPIO_PinAltFunMode) << (4 * (pGPIOhandel->GPIO_PinConfig.GPIO_PinNumber-8)));


		}
	}






}

void GPIO_DEInit(GPIO_RegDef_t *pGPIOx)
{
	if ( pGPIOx == GPIOA)
	{
		GPIOA_RST();
	}
	if ( pGPIOx == GPIOB)
	{
		GPIOB_RST();
	}
	if ( pGPIOx == GPIOC)
	{
		GPIOC_RST();
	}
	if ( pGPIOx == GPIOD)
	{
		GPIOD_RST();
	}
	if ( pGPIOx == GPIOE)
	{
		GPIOE_RST();
	}
	if ( pGPIOx == GPIOF)
	{
		GPIOF_RST();
	}
	if ( pGPIOx== GPIOG)
	{
		GPIOG_RST();
	}
	if ( pGPIOx == GPIOH)
	{
		GPIOH_RST();
	}
	if ( pGPIOx == GPIOI)
	{
		GPIOI_RST();
	}

}





void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI)
{
	if (ENorDI == 1)
	{
		if ( pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		if ( pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		if ( pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		if ( pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		if ( pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		if ( pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		if ( pGPIOx== GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		if ( pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		if ( pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}

	}
	else
	{
		if ( pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		if ( pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		if ( pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		if ( pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		if ( pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		if ( pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		if ( pGPIOx== GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		if ( pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
		if ( pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DI();
		}

	}
}



uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	return (uint8_t)(pGPIOx->IDR >> PinNumber)&0x00000001;
}



uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	return (uint16_t)(pGPIOx->IDR);
}


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,uint8_t Value)
{
	if (Value == 1)
	{
		pGPIOx -> ODR |= (1<<PinNumber);
	}
	else
	{
		pGPIOx -> ODR &=~ (1<<PinNumber);
	}

}


void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx -> ODR = (uint32_t)(Value);
}


void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx -> ODR ^=  (1<<PinNumber);
}


void GPIO_IRQITConfig(uint8_t IRQNumber, uint8_t EnorDi )
{
	if (EnorDi == ENABLE)
	{// enable IRQ
		if (IRQNumber <= 31)
		{
			*NVIC_ISER0 |= (1 << IRQNumber);
		}
		else if (IRQNumber > 31 && IRQNumber < 64)
		{
			*NVIC_ISER1 |= (1 << IRQNumber%32);
		}
		else if (IRQNumber >= 64 && IRQNumber < 96)
		{
			*NVIC_ISER2 |= (1 << IRQNumber%32);
		}
	}
	else
	{// disable IRQ
		if (IRQNumber <= 31)
		{
			*NVIC_ICER0 &= ~(1 << IRQNumber);
		}
		else if (IRQNumber > 31 && IRQNumber < 64)
		{
			*NVIC_ICER1 &= ~(1 << IRQNumber%32);
		}
		else if (IRQNumber >= 64 && IRQNumber < 96)
		{
			*NVIC_ICER2 &= ~(1 << IRQNumber%32);
		}
	}
}
void GPIO_IRQHandeling(uint8_t PinNumber)
{
	if (EXTI->PR & (1 << PinNumber ))
	{
		EXTI->PR |= ( 1 << PinNumber);
	}
}

void IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority)
{
	(pNVIC_PR)[IRQNumber/4]&= ~(0xFF<<8*IRQNumber%4);
	(pNVIC_PR)[IRQNumber/4]|= (IRQPriority<<(8*IRQNumber%4+8-NO_PR_BIS));
}
