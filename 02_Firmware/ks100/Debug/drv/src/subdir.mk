################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drv/src/DEM128064E1FGH.c \
../drv/src/LCDHAL.c \
../drv/src/Stm32f407xx_RCC.c \
../drv/src/keybrd.c \
../drv/src/stm32f407xx_gpio.c \
../drv/src/stm32f407xx_spi.c \
../drv/src/stm32f407xx_tim.c 

OBJS += \
./drv/src/DEM128064E1FGH.o \
./drv/src/LCDHAL.o \
./drv/src/Stm32f407xx_RCC.o \
./drv/src/keybrd.o \
./drv/src/stm32f407xx_gpio.o \
./drv/src/stm32f407xx_spi.o \
./drv/src/stm32f407xx_tim.o 

C_DEPS += \
./drv/src/DEM128064E1FGH.d \
./drv/src/LCDHAL.d \
./drv/src/Stm32f407xx_RCC.d \
./drv/src/keybrd.d \
./drv/src/stm32f407xx_gpio.d \
./drv/src/stm32f407xx_spi.d \
./drv/src/stm32f407xx_tim.d 


# Each subdirectory must supply rules for building sources it contributes
drv/src/%.o drv/src/%.su drv/src/%.cyclo: ../drv/src/%.c drv/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I"E:/01_WORK/02_Projects/02-WIP/KS100/02_Firmware/ks100/drv/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-drv-2f-src

clean-drv-2f-src:
	-$(RM) ./drv/src/DEM128064E1FGH.cyclo ./drv/src/DEM128064E1FGH.d ./drv/src/DEM128064E1FGH.o ./drv/src/DEM128064E1FGH.su ./drv/src/LCDHAL.cyclo ./drv/src/LCDHAL.d ./drv/src/LCDHAL.o ./drv/src/LCDHAL.su ./drv/src/Stm32f407xx_RCC.cyclo ./drv/src/Stm32f407xx_RCC.d ./drv/src/Stm32f407xx_RCC.o ./drv/src/Stm32f407xx_RCC.su ./drv/src/keybrd.cyclo ./drv/src/keybrd.d ./drv/src/keybrd.o ./drv/src/keybrd.su ./drv/src/stm32f407xx_gpio.cyclo ./drv/src/stm32f407xx_gpio.d ./drv/src/stm32f407xx_gpio.o ./drv/src/stm32f407xx_gpio.su ./drv/src/stm32f407xx_spi.cyclo ./drv/src/stm32f407xx_spi.d ./drv/src/stm32f407xx_spi.o ./drv/src/stm32f407xx_spi.su ./drv/src/stm32f407xx_tim.cyclo ./drv/src/stm32f407xx_tim.d ./drv/src/stm32f407xx_tim.o ./drv/src/stm32f407xx_tim.su

.PHONY: clean-drv-2f-src

