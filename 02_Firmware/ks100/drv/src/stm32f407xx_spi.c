/*
 * stm32f407xx_spi.c
 *
 *  Created on: Feb 1, 2024
 *      Author: anast
 */

#include "stm32f407xx_spi.h"

void spi_tx_it_handle(SPI_Handel_t *pHandle);
void spi_rx_it_handle(SPI_Handel_t *pHandle);
void spi_OVR_it_handle(SPI_Handel_t *pHandle);

uint8_t SPI_GetFlag(SPI_RegDef_t *pSPIx,uint32_t flag)
{
	if (pSPIx->SR & flag)
	{
		return HIGH;
	}
	else
	{
		return LOW;
	}



}

void SPIx_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t ENorDI)
{
	if (ENorDI == 1)
	{
		if ( pSPIx == SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if ( pSPIx == SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if ( pSPIx == SPI3)
		{
			SPI3_PCLK_EN();
		}
	}
	else if (ENorDI == 0)
	{
		if ( pSPIx == SPI1)
		{
			SPI1_PCLK_DI();
		}
		else if ( pSPIx == SPI2)
		{
			SPI2_PCLK_DI();
		}
		else if ( pSPIx == SPI3)
		{
			SPI3_PCLK_DI();
		}

	}

}



void SPIx_Init(SPI_Handel_t *pSPIhandel)
{
	SPIx_PeriClockControl(pSPIhandel->pSPIX, ENABLE);
	//1- Device mode
	if (pSPIhandel->SPIConfig.SPI_DeviceMode == SPI_MODE_MASTER)
	{
	pSPIhandel->pSPIX->CR[0] |= (1<<2);
	pSPIhandel->pSPIX->CR[1] |= (1<<2);


	}
	else
	{
		pSPIhandel->pSPIX->CR[0] &= ~(1<<2);
	}
	//2- BUS Config mode
	if (pSPIhandel->SPIConfig.SPI_BusConfig == SPI_FD)
	{
		pSPIhandel->pSPIX->CR[0] &= ~(1<<15);
	}
	else if (pSPIhandel->SPIConfig.SPI_BusConfig == SPI_HD)
	{
		pSPIhandel->pSPIX->CR[0] |= (1<<15);
	}
	else if (pSPIhandel->SPIConfig.SPI_BusConfig == SPI_S_RX)
	{
		pSPIhandel->pSPIX->CR[0] |= (1<<15);
		pSPIhandel->pSPIX->CR[0]|= (1<<10);
	}
	else if (pSPIhandel->SPIConfig.SPI_BusConfig == SPI_S_TX)
		{
			pSPIhandel->pSPIX->CR[0] &= ~(1<<15);
			pSPIhandel->pSPIX->CR[0] &= ~(1<<10);
		}

	//3. CPHA
	if (pSPIhandel->SPIConfig.SPI_CPHA == SPI_CPHA_FIRST_EDGE)
	{
		pSPIhandel->pSPIX->CR[0] &= ~(1<<0);
	}
	else
	{
		pSPIhandel->pSPIX->CR[0] |= (1<<0);
	}
	//4.CPOL
	if (pSPIhandel->SPIConfig.SPI_CPOL == SPI_CPOL_HIGH)
	{
		pSPIhandel->pSPIX->CR[0] |= (1<<1);
	}
	else
	{
		pSPIhandel->pSPIX->CR[0] &= ~(1<<1);
	}
	//5.DFF
	if (pSPIhandel->SPIConfig.SPI_DFF == SPI_DFF_8BITS)
	{
		pSPIhandel->pSPIX->CR[0] &= ~(1<<11);
	}
	else
	{
		pSPIhandel->pSPIX->CR[0] |= (1<<11);
	}

	//8. SSM- software slave management
	if (pSPIhandel->SPIConfig.SPI_SSM == SPI_SSM_DI)
	{
		pSPIhandel->pSPIX->CR[0] &= ~(1<<9);
	}
	else
	{
		pSPIhandel->pSPIX->CR[0] |= (1<<9);
	}
	//8. Device Mode
	pSPIhandel->pSPIX->CR[0] &= ~(7<<3);
	switch (pSPIhandel->SPIConfig.SPI_SclkSpeed)
	{
	case PCLK_D2:
		pSPIhandel->pSPIX->CR[0] |=(PCLK_D2<<3);
		break;
	case PCLK_D4:
		pSPIhandel->pSPIX->CR[0] |=(PCLK_D4<<3);
		break;
	case PCLK_D8:
		pSPIhandel->pSPIX->CR[0] |=(PCLK_D8<<3);
		break;
	case PCLK_D16:
		pSPIhandel->pSPIX->CR[0] |=(PCLK_D16<<3);
		break;
	case PCLK_D32:
		pSPIhandel->pSPIX->CR[0] |=(PCLK_D32<<3);
		break;
	case PCLK_D64:
		pSPIhandel->pSPIX->CR[0] |=(PCLK_D64<<3);
		break;
	case PCLK_D256:
		pSPIhandel->pSPIX->CR[0] |=(PCLK_D256<<3);
		break;
		//MSB LSB
	if (pSPIhandel->SPIConfig.SPI_FF == SPI_MSB)
		{
			pSPIhandel->pSPIX->CR[0] &= ~(1<<7);
		}
		else
		{
			pSPIhandel->pSPIX->CR[0] |= (1<<7);
		}

	}

}


void SPIx_DEInit(SPI_RegDef_t *pSPIx)
{
	if (pSPIx == SPI1)
	{
		SPI1_RST();
	}
	else if (pSPIx == SPI2)
	{
		SPI2_RST();
	}
	else if (pSPIx == SPI3)
	{
		SPI3_RST();
	}
}



void SPI_SendData(SPI_RegDef_t *pSPIx,uint8_t *pTXBuffer, uint32_t Len)
{
	//Enable SPI
	pSPIx->CR[0]|= (1<<6);
	//blocking
	while (Len > 0)
		{


		while (SPI_GetFlag(pSPIx, SPI_TXE_FLAG) == LOW); // wait

		if (pSPIx->CR[0]&(1<<11)) //16bit mode.
		{
			pSPIx->DR = *((uint16_t*)pTXBuffer);
			Len--;
			Len--;
			(uint16_t*)pTXBuffer++;
		}
		else //8bits
		{
			pSPIx->DR = *(pTXBuffer);
			Len--;
			pTXBuffer++;
		}
		}

	//Disable SPI
	pSPIx->CR[0]&=~(1<<6);

}



void SPI_receiveData(SPI_RegDef_t *pSPIx,uint8_t *pRXBuffer, uint32_t Len)
{
	//blocking
	while (Len > 0)
		{

		while (SPI_GetFlag(pSPIx, SPI_RXNE_FLAG) == LOW); // wait

		if (pSPIx->CR[0]&(1<<11)) //16bit mode.
		{
			*((uint16_t*)pRXBuffer) = pSPIx->DR;
			Len--;
			Len--;
			(uint16_t*)pRXBuffer++;
		}
		else //8bits
		{
			*(pRXBuffer)= pSPIx->DR;
			Len--;
			pRXBuffer++;
		}
		}
}



void SPI_IRQITConfig(uint8_t IRQNumber, uint8_t EnorDi )
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




void SPI_IRQHandeling(SPI_Handel_t *pHandle)
{
	uint8_t SPIx_TXIT_FLG = pHandle ->pSPIX->SR & (1 << 1);
	uint8_t SPIx_TXIT = pHandle ->pSPIX->CR[1] & (1 << 7);
	if (SPIx_TXIT_FLG && SPIx_TXIT )
	{
		// handle TX
		spi_tx_it_handle(pHandle);
	}
	uint8_t SPIx_RXIT_FLG = pHandle ->pSPIX->SR & (1 << 0);
	uint8_t SPIx_RXIT = pHandle ->pSPIX->CR[1] & (1 << 6);
	if (SPIx_RXIT_FLG && SPIx_RXIT )
	{
		// handle RX
		spi_rx_it_handle(pHandle);
	}
	uint8_t SPIx_OVR_FLG = pHandle ->pSPIX->SR & (1 << 6);
	uint8_t SPIx_OVR = pHandle ->pSPIX->CR[1] & (1 << 6);
	if (SPIx_OVR_FLG && SPIx_OVR )
	{
		// handle OVR error
		spi_OVR_it_handle(pHandle);
	}
}

void spi_tx_it_handle(SPI_Handel_t *pHandle)
{


		if (pHandle->pSPIX->CR[0]&(1<<11)) //16bit mode.
		{
			pHandle->pSPIX->DR = *((uint16_t*)pHandle->pTXBuffer);
			pHandle->TxLen--;
			pHandle->TxLen--;
			(uint16_t*)pHandle->pTXBuffer++;
		}
		else //8bits
		{
			pHandle->pSPIX->DR = *(pHandle->pTXBuffer);
			pHandle->TxLen--;
			pHandle->pTXBuffer++;
		}
		if (! pHandle->TxLen)
		{
			SPI_TX_CLOSE(pHandle);
			SPI_APP_CALBK(pHandle,SPI_TX_CMPLT);
		}
}
void spi_rx_it_handle(SPI_Handel_t *pHandle)
{


		if (pHandle->pSPIX->CR[0]&(1<<11)) //16bit mode.
		{
			pHandle->pSPIX->DR = *((uint16_t*)pHandle->pRXBuffer);
			pHandle->RxLen--;
			pHandle->RxLen--;
			(uint16_t*)pHandle->pRXBuffer++;
		}
		else //8bits
		{
			pHandle->pSPIX->DR = *(pHandle->pRXBuffer);
			pHandle->RxLen--;
			pHandle->pRXBuffer++;
		}
		if (! pHandle->RxLen)
		{
			SPI_TX_CLOSE(pHandle);
			SPI_APP_CALBK(pHandle,SPI_RX_CMPLT);
		}
}
void spi_OVR_it_handle(SPI_Handel_t *pHandle)
{
	//Clear OVR
	if(pHandle->TxState != SPI_BUSY_RX)
	{
		SPI_CLR_OVR(pHandle->pSPIX);
	}
	SPI_APP_CALBK(pHandle,SPI_OVR);

}

void SPI_CLR_OVR(SPI_RegDef_t *pSPIx)
{
	uint8_t temp = 	pSPIx->DR;
	temp =pSPIx->SR;
}
void SPI_TX_CLOSE(SPI_Handel_t *pHandle)
{
	pHandle->pSPIX->CR[1]&= ~(1<<7);
	pHandle->pTXBuffer = NULL;
	pHandle->TxState = SPI_READY;
	SPI_APP_CALBK(pHandle,SPI_TX_CMPLT);
}
void SPI_RX_CLOSE(SPI_Handel_t *pHandle)
{
	pHandle->pSPIX->CR[1]&= ~(1<<6);
	pHandle->pRXBuffer = NULL;
	pHandle->RxState = SPI_READY;
	SPI_APP_CALBK(pHandle,SPI_RX_CMPLT);
}


void SPI_IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority)
{
	(pNVIC_PR)[IRQNumber/4]&= ~(0xFF<<8*IRQNumber%4);
	(pNVIC_PR)[IRQNumber/4]|= (IRQPriority<<(8*IRQNumber%4+8-NO_PR_BIS));
}

uint8_t SPI_SendDataIT(SPI_Handel_t *pSPIxH,uint8_t *pTXBuffer, uint32_t Len)
{
	if(pSPIxH->TxState != SPI_BUSY_TX)
	{
		pSPIxH->TxLen = Len;
		pSPIxH->pTXBuffer = pTXBuffer;

		pSPIxH->TxState = SPI_BUSY_TX;
		pSPIxH->pSPIX->CR[1] |= (1<<7);
	}
	return pSPIxH->TxState;
}
uint8_t SPI_receiveDataIT(SPI_Handel_t *pSPIxH,uint8_t *pRXBuffer, uint32_t Len)
{
	if(pSPIxH->RxState != SPI_BUSY_RX)
		{
			pSPIxH->RxLen = Len;
			pSPIxH->pRXBuffer = pRXBuffer;

			pSPIxH->RxState = SPI_BUSY_RX;
			pSPIxH->pSPIX->CR[1] |= (1<<6);
		}
		return pSPIxH->RxState;
}

__weak void SPI_APP_CALBK(SPI_Handel_t *pHandle,uint8_t SPI_EVENT)
{
	//weak
}
