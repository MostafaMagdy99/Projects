################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Service/subdir.mk
-include MCAL/GPIO/subdir.mk
-include MCAL/Ext_Interrupt/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/lcd/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
LM_Sensor_Project.lss \

FLASH_IMAGE += \
LM_Sensor_Project.hex \

EEPROM_IMAGE += \
LM_Sensor_Project.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LM_Sensor_Project.elf secondary-outputs

# Tool invocations
LM_Sensor_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LM_Sensor_Project.map -mmcu=atmega32 -o "LM_Sensor_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LM_Sensor_Project.lss: LM_Sensor_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LM_Sensor_Project.elf  >"LM_Sensor_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

LM_Sensor_Project.hex: LM_Sensor_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LM_Sensor_Project.elf  "LM_Sensor_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

LM_Sensor_Project.eep: LM_Sensor_Project.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LM_Sensor_Project.elf  "LM_Sensor_Project.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LM_Sensor_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LM_Sensor_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LM_Sensor_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
