/*
 * stm32f407xx_gpio.h
 *
 *  Created on: Jan 23, 2024
 *      Author: anast
 */

#ifndef INC_STM32F407XX_GPIO_H_
#define INC_STM32F407XX_GPIO_H_

#include "stm32f407xx.h"

//GPIO Config Struct

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PiPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

//GPIO Handle Struct

typedef struct
{
	GPIO_RegDef_t *pGPIOX;
	GPIO_PinConfig_t GPIO_PinConfig;


}GPIO_Handel_t;
//REG VALUE MACROS.
#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALTFN 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT 4
#define GPIO_MODE_IT_RT 5
#define GPIO_MODE_IT_RfT 6

#define GPIO_TYPE_PP 0
#define GPIO_TYPE_OD 1

#define GPIO_SPEED_LOW 0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST 2
#define GPIO_SPEED_HIGH 3

#define GPIO_NO_PUPD 0
#define GPIO_PIN_PU 1
#define GPIO_pIN_PD 2

#define GPIO_PI_NO_0	0
#define GPIO_PI_NO_1	1
#define GPIO_PI_NO_2	2
#define GPIO_PI_NO_3	3
#define GPIO_PI_NO_4	4
#define GPIO_PI_NO_5	5
#define GPIO_PI_NO_6	6
#define GPIO_PI_NO_7	7
#define GPIO_PI_NO_8	8
#define GPIO_PI_NO_9	9
#define GPIO_PI_NO_10	10
#define GPIO_PI_NO_11	11
#define GPIO_PI_NO_12	12
#define GPIO_PI_NO_13	13
#define GPIO_PI_NO_14	14
#define GPIO_PI_NO_15	15


//GPIO API Prototypes

void GPIO_Init(GPIO_Handel_t *pGPIOhandel);
void GPIO_DEInit(GPIO_RegDef_t *pGPIOx);
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
void GPIO_IRQITConfig(uint8_t IRQNumber, uint8_t EnorDi );
void IRQPriorityConfig(uint8_t IRQNumber,uint8_t IRQPriority);
void GPIO_IRQHandeling(uint8_t PinNumber);


#endif /* INC_STM32F407XX_GPIO_H_ */
