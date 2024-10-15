		/*
		 * keybrd.c
		 *
		 *  Created on: Aug 5, 2024
		 *      Author: anast
		 */

#include "keybrd.h"
#include "stm32f407xx.h"
#include "stm32f407xx_gpio.h"
//Switch Matricx init.

void keybrdMatrixInit()
{
	GPIO_Handel_t matrix;

	matrix.pGPIOX = GPIOB;
	matrix.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_0;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_1;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_2;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_3;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_4;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_5;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_6;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_7;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_8;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_9;
	GPIO_Init(&matrix);

	matrix.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_11;
	GPIO_Init(&matrix);

	}
