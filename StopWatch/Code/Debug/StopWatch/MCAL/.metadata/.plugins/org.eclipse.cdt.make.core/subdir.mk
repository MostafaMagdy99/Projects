################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../StopWatch/MCAL/.metadata/.plugins/org.eclipse.cdt.make.core/specs.c 

OBJS += \
./StopWatch/MCAL/.metadata/.plugins/org.eclipse.cdt.make.core/specs.o 

C_DEPS += \
./StopWatch/MCAL/.metadata/.plugins/org.eclipse.cdt.make.core/specs.d 


# Each subdirectory must supply rules for building sources it contributes
StopWatch/MCAL/.metadata/.plugins/org.eclipse.cdt.make.core/%.o: ../StopWatch/MCAL/.metadata/.plugins/org.eclipse.cdt.make.core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


