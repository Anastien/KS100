/*
 * stm32f407xx.h
 * stm32f40xx.h device specific header file.
 *  Created on: Jan 21, 2024
 *      Author: anast
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_
#include <stdint.h>
#include <stddef.h>
#define __weak __attribute__((weak))
//NVIC
#define NVIC_ISER0		((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1		((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2		((volatile uint32_t*)0xE000E108)
#define NVIC_ISER3		((volatile uint32_t*)0xE000E10C)

#define NVIC_ICER0		((volatile uint32_t*)0xE000E180)
#define NVIC_ICER1		((volatile uint32_t*)0xE000E184)
#define NVIC_ICER2		((volatile uint32_t*)0xE000E188)
#define NVIC_ICER3		((volatile uint32_t*)0xE000E18C)

#define NO_PR_BIS		4
#define pNVIC_PR		((volatile uint32_t*)0xE000E400)
/*
 * base addresses of Flash and SRAM Memories.
 */
/*begin*/
#define FLASH_BASEADDR 0x08000000U
#define SRAM1_BASEADDR 0x20000000U
#define SRAM2_BASEADDR 0x2001c000U
#define ROM_BASEADDR   0x1fff0000U
#define SRAM_BASEADDR  SRAM1_BASEADDR
/*end*/


/*
 * base busses addresses .
 */
/*begin*/
#define PERIPH_BASE           0x40000000U
#define AHB1_PERIPH_BASE_ADDR 0x40020000U
#define AHB2_PERIPH_BASE_ADDR 0x50000000U
#define APB1_PERIPH_BASE_ADDR PERIPH_BASE
#define APB2_PERIPH_BASE_ADDR 0x40010000U

/*end*/

/*
 * base AHB1 Peripherals  addresses .
 */
/*begin*/
#define GPIOA_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x0000)
#define GPIOB_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x0400)
#define GPIOC_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x0800)
#define GPIOD_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x0C00)
#define GPIOE_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x1000)
#define GPIOF_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x1400)
#define GPIOG_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x1800)
#define GPIOH_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x1C00)
#define GPIOI_BASEADDR (AHB1_PERIPH_BASE_ADDR + 0x2000)
#define BASEADDR   (AHB1_PERIPH_BASE_ADDR + 0x3800)


/*end*/

/*
 * base APB1 Peripherals  addresses .
 */
/*begin*/
#define I2C1_BASEADDR    (APB1_PERIPH_BASE_ADDR + 0x5400)
#define I2C2_BASEADDR    (APB1_PERIPH_BASE_ADDR + 0x5800)
#define I2C3_BASEADDR    (APB1_PERIPH_BASE_ADDR + 0x5C00)
#define SPI2_BASEADDR    (APB1_PERIPH_BASE_ADDR + 0x3800)
#define SPI3_BASEADDR    (APB1_PERIPH_BASE_ADDR + 0x3C00)
#define USART2_BASEADDR  (APB1_PERIPH_BASE_ADDR + 0x4400)
#define USART3_BASEADDR  (APB1_PERIPH_BASE_ADDR + 0x4800)
#define UART4_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x4C00)
#define UART5_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x5000)

#define TIM2_BASEADDR   (APB1_PERIPH_BASE_ADDR)
#define TIM3_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x400)
#define TIM4_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x800)
#define TIM5_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0xC00)
#define TIM6_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x1000)
#define TIM7_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x1400)
#define TIM12_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x1800)
#define TIM14_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x1C00)
#define TIM14_BASEADDR   (APB1_PERIPH_BASE_ADDR + 0x2000)


/*end*/




/*
 * base APB2 Peripherals  addresses .
 */
/*begin*/
#define EXTI_BASEADDR     (APB2_PERIPH_BASE_ADDR + 0x3C00)
#define USART1_BASEADDR   (APB2_PERIPH_BASE_ADDR + 0x1000)
#define USART6_BASEADDR   (APB2_PERIPH_BASE_ADDR + 0x1400)
#define SPI1_BASEADDR     (APB2_PERIPH_BASE_ADDR + 0x3000)
#define SYSCFG_BASEADDR   (APB2_PERIPH_BASE_ADDR + 0x3800)
/*end*/


/*
 * GPIO STRUCT AND INSTANCES.
 */
/*begin*/
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];

}GPIO_RegDef_t;
#define GPIOA ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI ((GPIO_RegDef_t*) GPIOI_BASEADDR)

#define EXTI  ((EXTI_RegDef_t*) EXTI_BASEADDR)





/*
 * RCC STRUCT.
 */
/*begin*/
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t RSVD1;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t RSVD2;
	volatile uint32_t RSVD3;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t RSVD4;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t RSVD5;
	volatile uint32_t RSVD6;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t RSVD7;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t RSVD9;
	volatile uint32_t RSVD10;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t RSVD11;
	volatile uint32_t RSVD12;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLSAICFGR;
	volatile uint32_t PLLDCKCFGR;

}RCC_RegDef_t;

#define RCC ((RCC_RegDef_t*)BASEADDR)

//EXTI Struct

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_RegDef_t;

typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t rsv[2];
	volatile uint32_t CMPCR;
}SYSCFG_RegDef_t;
#define SYSCFG ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


//SPI STRUT

typedef struct
{
	volatile uint32_t CR[2];
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR;
}SPI_RegDef_t;
#define SPI1 ((SPI_RegDef_t*) SPI1_BASEADDR)
#define SPI2 ((SPI_RegDef_t*) SPI2_BASEADDR)
#define SPI3 ((SPI_RegDef_t*) SPI3_BASEADDR)

/*I2C  STRUCT*/

typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;
	volatile uint32_t FLTR;
}I2C_RegDef_t;

#define I2C1 ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2 ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3 ((I2C_RegDef_t*)I2C3_BASEADDR)

//Timers Struct
typedef struct
{
	volatile uint32_t CR[2];
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR[2];
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR[4];
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t TIM2_5OR;



}TIMX_RegDef_t;

//TIM 1>5
#define TIM6 ((TIMX_RegDef_t*)TIM6_BASEADDR)



/*CLK EN macros*/
//GPIO
#define GPIOA_PCLK_EN()	(RCC->AHB1ENR|=(1<<0))
#define GPIOB_PCLK_EN()	(RCC->AHB1ENR|=(1<<1))
#define GPIOC_PCLK_EN()	(RCC->AHB1ENR|=(1<<2))
#define GPIOD_PCLK_EN()	(RCC->AHB1ENR|=(1<<3))
#define GPIOE_PCLK_EN()	(RCC->AHB1ENR|=(1<<4))
#define GPIOF_PCLK_EN()	(RCC->AHB1ENR|=(1<<5))
#define GPIOG_PCLK_EN()	(RCC->AHB1ENR|=(1<<6))
#define GPIOH_PCLK_EN()	(RCC->AHB1ENR|=(1<<7))
#define GPIOI_PCLK_EN()	(RCC->AHB1ENR|=(1<<8))
//I2C
#define I2C1_PCLK_EN()	(RCC->APB1ENR|=(1<<21))
#define I2C2_PCLK_EN()	(RCC->APB1ENR|=(1<<22))
#define I2C3_PCLK_EN()	(RCC->APB1ENR|=(1<<23))
//SPI
#define SPI1_PCLK_EN()	(RCC->APB2ENR|=(1<<12))
#define SPI2_PCLK_EN()	(RCC->APB1ENR|=(1<<14))
#define SPI3_PCLK_EN()	(RCC->APB1ENR|=(1<<15))
//USART
#define USART1_PCLK_EN()	(RCC->APB2ENR|=(1<<4))
#define USART6_PCLK_EN()	(RCC->APB2ENR|=(1<<5))
#define USART2_PCLK_EN()	(RCC->APB1ENR|=(1<<17))
#define USART3_PCLK_EN()	(RCC->APB1ENR|=(1<<18))
#define USART4_PCLK_EN()	(RCC->APB1ENR|=(1<<19))
#define UART5_PCLK_EN()	    (RCC->APB1ENR|=(1<<20))
//SYSCFG
#define SYSCFG_PCLK_EN()	(RCC->APB2ENR|=(1<<14))


/*CLK DIS macros*/
//GPIO
#define GPIOA_PCLK_DI()	(RCC->AHB1ENR&=~(1<<0))
#define GPIOB_PCLK_DI()	(RCC->AHB1ENR&=~(1<<1))
#define GPIOC_PCLK_DI()	(RCC->AHB1ENR&=~(1<<2))
#define GPIOD_PCLK_DI()	(RCC->AHB1ENR&=~(1<<3))
#define GPIOE_PCLK_DI()	(RCC->AHB1ENR&=~(1<<4))
#define GPIOF_PCLK_DI()	(RCC->AHB1ENR&=~(1<<5))
#define GPIOG_PCLK_DI()	(RCC->AHB1ENR&=~(1<<6))
#define GPIOH_PCLK_DI()	(RCC->AHB1ENR&=~(1<<7))
#define GPIOI_PCLK_DI()	(RCC->AHB1ENR&=~(1<<8))
//I2C
#define I2C1_PCLK_DI()	(RCC->APB1ENR&=~(1<<21))
#define I2C2_PCLK_DI()	(RCC->APB1ENR&=~(1<<22))
#define I2C3_PCLK_DI()	(RCC->APB1ENR&=~(1<<23))
//SPI
#define SPI1_PCLK_DI()	(RCC->APB2ENR&=~(1<<12))
#define SPI2_PCLK_DI()	(RCC->APB1ENR&=~(1<<14))
#define SPI3_PCLK_DI()	(RCC->APB1ENR&=~(1<<15))
//USART
#define USART1_PCLK_DI()	(RCC->APB2ENR&=~(1<<4))
#define USART6_PCLK_DI()	(RCC->APB2ENR&=~(1<<5))
#define USART2_PCLK_DI()	(RCC->APB1ENR&=~(1<<17))
#define USART3_PCLK_DI()	(RCC->APB1ENR&=~(1<<18))
#define USART4_PCLK_DI()	(RCC->APB1ENR&=~(1<<19))
#define UART5_PCLK_DI()	    (RCC->APB1ENR&=~(1<<20))
//SYSCFG
#define SYSCFG_PCLK_DI()	(RCC->APB2ENR&=~(1<<14))


// GPIO RST MACROS
#define GPIOA_RST()		do{(RCC->AHB1RSTR |=(1<<0));(RCC->AHB1RSTR &=~(1<<0));} while (0)
#define GPIOB_RST()		do{(RCC->AHB1RSTR |=(1<<1));(RCC->AHB1RSTR &=~(1<<1));} while (0)
#define GPIOC_RST()		do{(RCC->AHB1RSTR |=(1<<2));(RCC->AHB1RSTR &=~(1<<2));} while (0)
#define GPIOD_RST()		do{(RCC->AHB1RSTR |=(1<<3));(RCC->AHB1RSTR &=~(1<<3));} while (0)
#define GPIOE_RST()		do{(RCC->AHB1RSTR |=(1<<4));(RCC->AHB1RSTR &=~(1<<4));} while (0)
#define GPIOF_RST()		do{(RCC->AHB1RSTR |=(1<<5));(RCC->AHB1RSTR &=~(1<<5));} while (0)
#define GPIOG_RST()		do{(RCC->AHB1RSTR |=(1<<6));(RCC->AHB1RSTR &=~(1<<6));} while (0)
#define GPIOH_RST()		do{(RCC->AHB1RSTR |=(1<<7));(RCC->AHB1RSTR &=~(1<<7));} while (0)
#define GPIOI_RST()		do{(RCC->AHB1RSTR |=(1<<8));(RCC->AHB1RSTR &=~(1<<8));} while (0)

// SPI RST MACROS
#define SPI1_RST()		do{(RCC->APB2RSTR |=(1<<12));(RCC->APB2RSTR &=~(1<<12));} while (0)
#define SPI2_RST()		do{(RCC->APB1RSTR |=(1<<14));(RCC->AHB1RSTR &=~(1<<14));} while (0)
#define SPI3_RST()		do{(RCC->APB1RSTR |=(1<<15));(RCC->AHB1RSTR &=~(1<<15));} while (0)
// I2C RST MACROS
#define I2C1_RST()		do{(RCC->APB1RSTR |=(1<<21));(RCC->APB1RSTR &=~(1<<21));} while (0)
#define I2C2_RST()		do{(RCC->APB1RSTR |=(1<<22));(RCC->AHB1RSTR &=~(1<<22));} while (0)
#define I2C3_RST()		do{(RCC->APB1RSTR |=(1<<23));(RCC->AHB1RSTR &=~(1<<23));} while (0)

//Generic Macros
#define HIGH 1
#define LOW 0
#define ENABLE 1
#define DISABLE 0
#define SET ENABLE
#define RESET DISABLE
#define PORTCODE(x)                    ((x==GPIOA)? 0 :\
										(x==GPIOC)? 1 :\
										(x==GPIOD)? 2 :\
										(x==GPIOE)? 3 :\
										(x==GPIOF)? 4 :\
										(x==GPIOG)? 5 :\
										(x==GPIOH)? 6 :\
										(x==GPIOI)? 7 :0)
//IRQ Number Macros
#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXT9_5		23
#define IRQ_NO_EXT15_10		40
#define IRQ_NO_SPI_1		42
#define IRQ_NO_SPI_2		43
#define IRQ_NO_SPI_3		51
#define IRQ_NO_I2C1_EV		31
#define IRQ_NO_I2C1_ER		32

//SPI MACROS
#define SPI_MODE_MASTER  1
#define SPI_MODE_SLAVE   0

#define SPI_FD			1
#define SPI_HD			2
#define SPI_S_TX		3
#define SPI_S_RX		4

#define PCLK_D2			0 // PCLK/2
#define PCLK_D4			1
#define PCLK_D8			2
#define PCLK_D16		3
#define PCLK_D32		4
#define PCLK_D64		5
#define PCLK_D128		6
#define PCLK_D256		7

#define SPI_DFF_8BITS	0
#define SPI_DFF_16BITS	1

#define SPI_CPOL_HIGH	1
#define SPI_CPOL_LOW	0

#define SPI_CPHA_FIRST_EDGE		0
#define SPI_CPHA_SECOND_EDGE  	1

#define SPI_MSB				  	0
#define SPI_LSB				  	1


#define SPI_SSM_DI		0
#define SPI_SSM_EN		1

#define HSI				1
#define HSE				2
#define PLL				3
#include "stm32f407xx_gpio.h"
#include "stm32f407xx_spi.h"
//#include "stm32f407xx_I2C.h"
#endif /* INC_STM32F407XX_H_ */
