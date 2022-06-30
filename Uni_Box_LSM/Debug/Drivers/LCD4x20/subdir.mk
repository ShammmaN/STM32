################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/LCD4x20/i2c-lcd.c 

OBJS += \
./Drivers/LCD4x20/i2c-lcd.o 

C_DEPS += \
./Drivers/LCD4x20/i2c-lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/LCD4x20/%.o Drivers/LCD4x20/%.su: ../Drivers/LCD4x20/%.c Drivers/LCD4x20/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/shammman/Dokumenty/STM32_CubeIDE/Learning/Uni_Box_LSM/Drivers/LCD4x20" -I"/home/shammman/Dokumenty/STM32_CubeIDE/Learning/Uni_Box_LSM/Drivers/KeyPad" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-LCD4x20

clean-Drivers-2f-LCD4x20:
	-$(RM) ./Drivers/LCD4x20/i2c-lcd.d ./Drivers/LCD4x20/i2c-lcd.o ./Drivers/LCD4x20/i2c-lcd.su

.PHONY: clean-Drivers-2f-LCD4x20

