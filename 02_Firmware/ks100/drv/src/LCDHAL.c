/*
 * lcd.c
 *
 *  Created on: Mar 20, 2024
 *      Author: anast
 */
/* HW Interface
 * RESET , Active Low	-> PC1
 * SPI
 * CS					-> PB12
 * SCL					-> PB10
 * SI					-> PC3
 */





#include <LCDHAL.h>
#include "stm32f407xx.h"
#include "stm32f407xx_gpio.h"
#include "stm32f407xx_spi.h"
#include "DEM128064E1FGH.h"

// LCD Init
void LCD_Init()
{
	//Control GPIO

	GPIO_Handel_t LCD_Pin;
	//RST
	LCD_Pin.pGPIOX = GPIOC;
	LCD_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_1;
	LCD_Pin.GPIO_PinConfig.GPIO_PinOPType= GPIO_TYPE_PP;
	LCD_Pin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_Init(&LCD_Pin);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_1, 1);

	//A0
	LCD_Pin.pGPIOX = GPIOC;
	LCD_Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_13;
	GPIO_Init(&LCD_Pin);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);

	//SPI_GPIO
	GPIO_Handel_t SPI2_PIN;
	SPI2_PIN.pGPIOX = GPIOC;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinAltFunMode=5;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinOPType= GPIO_TYPE_PP;

	//spi2 MOSI
	SPI2_PIN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_3;
	GPIO_Init(&SPI2_PIN);

	//spi2 SCL
	SPI2_PIN.pGPIOX = GPIOB;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinAltFunMode=5;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinOPType= GPIO_TYPE_PP;
	//SPI2_PIN.GPIO_PinConfig.GPIO_PiPuPdControl = GPIO_PIN_PU;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_10;
	GPIO_Init(&SPI2_PIN);

	//CS
	SPI2_PIN.pGPIOX = GPIOB;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinAltFunMode=5;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinOPType= GPIO_TYPE_PP;
	SPI2_PIN.GPIO_PinConfig.GPIO_PinNumber = GPIO_PI_NO_12;
	GPIO_Init(&SPI2_PIN);


	//SPI2
	SPI_Handel_t SPI2_h;
	SPI2_h.pSPIX = SPI2;
	SPI2_h.SPIConfig.SPI_BusConfig = SPI_S_TX;
	SPI2_h.SPIConfig.SPI_DeviceMode = SPI_MODE_MASTER;
	SPI2_h.SPIConfig.SPI_SclkSpeed = PCLK_D32;//781kHz
	SPI2_h.SPIConfig.SPI_DFF = SPI_DFF_8BITS;
	SPI2_h.SPIConfig.SPI_SSM = SPI_SSM_DI;
	SPI2_h.SPIConfig.SPI_CPHA = SPI_CPHA_SECOND_EDGE;
	SPI2_h.SPIConfig.SPI_CPOL = SPI_CPOL_HIGH;
	SPI2_h.SPIConfig.SPI_FF = SPI_MSB;
	SPIx_Init(&SPI2_h);




	//LCD Commands
	LCD_RST();
	LCD_Bias();
	LCD_ADC(ENABLE);
	LCD_ComMode();
	//LCD_StrtLineAddr(0x40);
	LCD_RbRa();
	delay(TIM6, 5);
	LCD_Evol();
	LCD_PwrConfig();
	LCD_BstMult();
	delay(TIM6, 5);
	LCD_Onoff(ENABLE);
	LCD_Normal(DISABLE);


}


