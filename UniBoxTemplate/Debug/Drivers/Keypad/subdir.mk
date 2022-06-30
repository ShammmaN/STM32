################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Keypad/Keypad.c 

C_DEPS += \
./Drivers/Keypad/Keypad.d 

OBJS += \
./Drivers/Keypad/Keypad.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Keypad/%.o Drivers/Keypad/%.su: ../Drivers/Keypad/%.c Drivers/Keypad/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/shammman/Dokumenty/STM32_CubeIDE/Learning/UniBoxTemplate/Drivers/Keypad" -I"/home/shammman/Dokumenty/STM32_CubeIDE/Learning/UniBoxTemplate/Drivers/LCD_I2C" -I"/home/shammman/Dokumenty/STM32_CubeIDE/Learning/UniBoxTemplate/Drivers/Menu" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Keypad

clean-Drivers-2f-Keypad:
	-$(RM) ./Drivers/Keypad/Keypad.d ./Drivers/Keypad/Keypad.o ./Drivers/Keypad/Keypad.su

.PHONY: clean-Drivers-2f-Keypad

