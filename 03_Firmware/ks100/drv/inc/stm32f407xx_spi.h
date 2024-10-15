/*
 * stm32f407xx_spi.h
 *
 *  Created on: Feb 1, 2024
 *      Author: anast
 */

#ifndef INC_STM32F407XX_SPI_H_
#define INC_STM32F407XX_SPI_H_

#include "stm32f407xx.h"

//spi
#define SPI_TXE_FLAG	(1<<1)
#define SPI_RXNE_FLAG	(1<<0)
#define SPI_BUSY_FLAG	(1<<7)
#define SPI_READY		0
#define SPI_BUSY_RX		1
#define SPI_BUSY_TX		2
#define SPI_TX_CMPLT	1
#define SPI_RX_CMPLT	2
#define SPI_OVR			3
//spi config struct

typedef struct
{
	volatile uint8_t SPI_DeviceMode;
	volatile uint8_t SPI_BusConfig;
	volatile uint8_t SPI_SclkSpeed;
	volatile uint8_t SPI_DFF;
	volatile uint8_t SPI_CPOL;
	volatile uint8_t SPI_CPHA;
	volatile uint8_t SPI_SSM;
}SPI_Config_t;

//spi handel
typedef struct
{
	volatile SPI_RegDef_t 	*pSPIX;
	volatile SPI_Config_t 	SPIConfig;
	volatile uint8_t		*pTXBuffer;
	volatile uint8_t		*pRXBuffer;
	volatile uint32_t		TxLen;
	volatile uint32_t		RxLen;
	volatile uint8_t		TxState;
	volatile uint8_t		RxState;
}SPI_Handel_t;


//API prototypes
void SPIx_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t ENorDI);
void SPIx_Init(SPI_Handel_t *pSPIhandel);
void SPIx_DEInit(SPI_RegDef_t *pSPIx);

void SPI_SendData(SPI_RegDef_t *pSPIxH,uint8_t *pTXBuffer, uint32_t Len);
void SPI_receiveData(SPI_RegDef_t *pSPIxH,uint8_t *pRXBuffer, uint32_t Len);

uint8_t SPI_SendDataIT(SPI_Handel_t *pSPIx,uint8_t *pTXBuffer, uint32_t Len);
uint8_t SPI_receiveDataIT(SPI_Handel_t *pSPIx,uint8_t *pRXBuffer, uint32_t Len);


void SPI_IRQITConfig(uint8_t IRQNumber, uint8_t EnorDi );
void SPI_IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority);
void SPI_IRQHandeling(SPI_Handel_t *pHandle);

void SPI_CLR_OVR(SPI_RegDef_t *pSPIx);
void SPI_TX_CLOSE(SPI_Handel_t *pHandle);
void SPI_RX_CLOSE(SPI_Handel_t *pHandle);

void SPI_APP_CALBK(SPI_Handel_t *pHandle,uint8_t SPI_EVENT);


#endif /* INC_STM32F407XX_SPI_H_ */
