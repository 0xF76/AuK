################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CUnit/Sources/Basic/Basic.c 

OBJS += \
./CUnit/Sources/Basic/Basic.o 

C_DEPS += \
./CUnit/Sources/Basic/Basic.d 


# Each subdirectory must supply rules for building sources it contributes
CUnit/Sources/Basic/%.o CUnit/Sources/Basic/%.su CUnit/Sources/Basic/%.cyclo: ../CUnit/Sources/Basic/%.c CUnit/Sources/Basic/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../WordUtilities/inc -I../CUnit -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CUnit-2f-Sources-2f-Basic

clean-CUnit-2f-Sources-2f-Basic:
	-$(RM) ./CUnit/Sources/Basic/Basic.cyclo ./CUnit/Sources/Basic/Basic.d ./CUnit/Sources/Basic/Basic.o ./CUnit/Sources/Basic/Basic.su

.PHONY: clean-CUnit-2f-Sources-2f-Basic

