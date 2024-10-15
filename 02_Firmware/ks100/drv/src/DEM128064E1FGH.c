/*
 * DEM128064E1FGH.c
 *
 *  Created on: Jun 15, 2024
 *      Author: anast
 */

#include "DEM128064E1FGH.h"
#include "stm32f407xx.h"
#include "Stm32f407xx_tim.h"


void LCD_RST()
{
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_1, 0);
	delay(TIM6, 500);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_1, 1);



}
//LCD OnOff Control
void LCD_Onoff(uint8_t ENorDI)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);

	//SPI
	uint8_t TXBuffer;
	if (ENorDI == ENABLE){
		TXBuffer = 0xAF;
	}
	else{

		TXBuffer = 0xAE;
	}

	SPI_SendData(SPI2, &TXBuffer, 1);
}

void LCD_StrtLineAddr(uint8_t Addr)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);

	//SPI
	uint8_t TXBuffer;
	TXBuffer |= (1<<6);

	SPI_SendData(SPI2, &TXBuffer, 1);

	}
void LCD_PageAddr(uint8_t Addr)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);

	//SPI

	Addr |= (0b10110000);

	SPI_SendData(SPI2, &Addr, 1);
	}
void LCD_ClmnAddr(uint8_t Addr, uint8_t MS)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);

	if (MS == 1)
	{
		Addr |= (1<<4);

	}
	SPI_SendData(SPI2, &Addr, 1);

}

void LCD_DataWrite(uint8_t Data)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 1);
	SPI_SendData(SPI2, &Data, 1);
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);



	}
void LCD_ADC(uint8_t EnorDi)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);

	//SPI
	uint8_t TXBuffer;
	if (EnorDi == ENABLE){
		TXBuffer = 0b10100000;
	}
	else{

		TXBuffer = 0b10100001;
	}

	SPI_SendData(SPI2, &TXBuffer, 1);
	}
void LCD_Orint(uint8_t EnorDi)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);

	//SPI
	uint8_t TXBuffer;
	if (EnorDi == ENABLE){
		TXBuffer = 0b10100110;
	}
	else{

		TXBuffer = 0b10100111;
	}

	SPI_SendData(SPI2, &TXBuffer, 1);


	}

void LCD_DisplayAllPnts(uint8_t ENorDI)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	if (ENorDI == ENABLE){
		TXBuffer = 0b10100101;
	}
	else{

		TXBuffer = 0b10100100;
	}

	SPI_SendData(SPI2, &TXBuffer, 1);
}

void LCD_Bias()
{
	//LCD bias set 1/9
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	TXBuffer = 0xA2;
	SPI_SendData(SPI2, &TXBuffer, 1);
	}
void LCD_KlmnIncrmnt()
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	TXBuffer = 0b11100000;
	SPI_SendData(SPI2, &TXBuffer, 1);
	}
void LCD_End()
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	TXBuffer = 0b11101110;
	SPI_SendData(SPI2, &TXBuffer, 1);
	}
void LCD_Rst()
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	TXBuffer = 0b11100010;
	SPI_SendData(SPI2, &TXBuffer, 1);
	}
void LCD_PwrConfig()
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;

	TXBuffer = 0b00101100;
	SPI_SendData(SPI2, &TXBuffer, 1);
	delay(TIM6, 10);

	TXBuffer = 0b00101110;
	SPI_SendData(SPI2, &TXBuffer, 1);
	delay(TIM6, 10);

	TXBuffer = 0b00101111;
	SPI_SendData(SPI2, &TXBuffer, 1);
	delay(TIM6, 10);

	}
void LCD_RbRa()
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	TXBuffer = 0x20;
	SPI_SendData(SPI2, &TXBuffer, 1);

	}
void LCD_SttkIndkt(uint8_t EnorDi)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);

	//SPI
	uint8_t TXBuffer;
	if (EnorDi == ENABLE){
		TXBuffer = 0b10101100;
	}
	else{

		TXBuffer = 0b10101101;
	}

	SPI_SendData(SPI2, &TXBuffer, 1);


	}


void LCD_BstMult()
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	TXBuffer = 0b11111000;
	SPI_SendData(SPI2, &TXBuffer, 1);
	TXBuffer = 0b00000001;
	SPI_SendData(SPI2, &TXBuffer, 1);
}

void LCD_Evol()
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	TXBuffer = 0b10000001;
	SPI_SendData(SPI2, &TXBuffer, 1);
	TXBuffer = 0b00111111;
	SPI_SendData(SPI2, &TXBuffer, 1);
}

void LCD_ComMode()
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	TXBuffer = 0b11000000;
	SPI_SendData(SPI2, &TXBuffer, 1);

}

void LCD_Normal(uint8_t ENorDI)
{
	//A10
	GPIO_WriteToOutputPin(GPIOC, GPIO_PI_NO_13, 0);
	//SPI
	uint8_t TXBuffer;
	if (ENorDI == ENABLE)
	{
		TXBuffer = 0b10100000;
	}
	else{

		TXBuffer = 0b10100001;
	}

	SPI_SendData(SPI2, &TXBuffer, 1);


}

