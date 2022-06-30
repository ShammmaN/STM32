################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/KeyPad/hey.c 

OBJS += \
./Drivers/KeyPad/hey.o 

C_DEPS += \
./Drivers/KeyPad/hey.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/KeyPad/%.o Drivers/KeyPad/%.su: ../Drivers/KeyPad/%.c Drivers/KeyPad/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"/home/shammman/Dokumenty/STM32_CubeIDE/Learning/Universal_Box_Test/Drivers/LCD4x20" -I"/home/shammman/Dokumenty/STM32_CubeIDE/Learning/Universal_Box_Test/Drivers/KeyPad" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-KeyPad

clean-Drivers-2f-KeyPad:
	-$(RM) ./Drivers/KeyPad/hey.d ./Drivers/KeyPad/hey.o ./Drivers/KeyPad/hey.su

.PHONY: clean-Drivers-2f-KeyPad

