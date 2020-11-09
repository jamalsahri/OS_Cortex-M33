################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/uart/usart_adapter.c 

OBJS += \
./component/uart/usart_adapter.o 

C_DEPS += \
./component/uart/usart_adapter.d 


# Each subdirectory must supply rules for building sources it contributes
component/uart/%.o: ../component/uart/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\board" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\source" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\drivers" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\device" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\CMSIS" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\utilities" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\component\serial_manager" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\component\lists" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\component\uart" -I"C:\Users\Jamal\Desktop\Discord COURS\S7\OS\LPC55S69_OS.src\startup" -I"/LPC55S69_OS.src/kernel" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


