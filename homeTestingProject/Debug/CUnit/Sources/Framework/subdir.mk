################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CUnit/Sources/Framework/CUError.c \
../CUnit/Sources/Framework/MessageHandlers.c \
../CUnit/Sources/Framework/MyMem.c \
../CUnit/Sources/Framework/TestDB.c \
../CUnit/Sources/Framework/TestFixture.c \
../CUnit/Sources/Framework/TestRun.c \
../CUnit/Sources/Framework/Util.c 

OBJS += \
./CUnit/Sources/Framework/CUError.o \
./CUnit/Sources/Framework/MessageHandlers.o \
./CUnit/Sources/Framework/MyMem.o \
./CUnit/Sources/Framework/TestDB.o \
./CUnit/Sources/Framework/TestFixture.o \
./CUnit/Sources/Framework/TestRun.o \
./CUnit/Sources/Framework/Util.o 

C_DEPS += \
./CUnit/Sources/Framework/CUError.d \
./CUnit/Sources/Framework/MessageHandlers.d \
./CUnit/Sources/Framework/MyMem.d \
./CUnit/Sources/Framework/TestDB.d \
./CUnit/Sources/Framework/TestFixture.d \
./CUnit/Sources/Framework/TestRun.d \
./CUnit/Sources/Framework/Util.d 


# Each subdirectory must supply rules for building sources it contributes
CUnit/Sources/Framework/%.o CUnit/Sources/Framework/%.su CUnit/Sources/Framework/%.cyclo: ../CUnit/Sources/Framework/%.c CUnit/Sources/Framework/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../WordUtilities/inc -I../CUnit -O3 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CUnit-2f-Sources-2f-Framework

clean-CUnit-2f-Sources-2f-Framework:
	-$(RM) ./CUnit/Sources/Framework/CUError.cyclo ./CUnit/Sources/Framework/CUError.d ./CUnit/Sources/Framework/CUError.o ./CUnit/Sources/Framework/CUError.su ./CUnit/Sources/Framework/MessageHandlers.cyclo ./CUnit/Sources/Framework/MessageHandlers.d ./CUnit/Sources/Framework/MessageHandlers.o ./CUnit/Sources/Framework/MessageHandlers.su ./CUnit/Sources/Framework/MyMem.cyclo ./CUnit/Sources/Framework/MyMem.d ./CUnit/Sources/Framework/MyMem.o ./CUnit/Sources/Framework/MyMem.su ./CUnit/Sources/Framework/TestDB.cyclo ./CUnit/Sources/Framework/TestDB.d ./CUnit/Sources/Framework/TestDB.o ./CUnit/Sources/Framework/TestDB.su ./CUnit/Sources/Framework/TestFixture.cyclo ./CUnit/Sources/Framework/TestFixture.d ./CUnit/Sources/Framework/TestFixture.o ./CUnit/Sources/Framework/TestFixture.su ./CUnit/Sources/Framework/TestRun.cyclo ./CUnit/Sources/Framework/TestRun.d ./CUnit/Sources/Framework/TestRun.o ./CUnit/Sources/Framework/TestRun.su ./CUnit/Sources/Framework/Util.cyclo ./CUnit/Sources/Framework/Util.d ./CUnit/Sources/Framework/Util.o ./CUnit/Sources/Framework/Util.su

.PHONY: clean-CUnit-2f-Sources-2f-Framework

