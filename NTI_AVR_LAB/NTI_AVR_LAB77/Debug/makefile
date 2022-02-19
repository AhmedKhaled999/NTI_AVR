################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
NTI_AVR_LAB77.lss \

FLASH_IMAGE += \
NTI_AVR_LAB77.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_AVR_LAB77.elf secondary-outputs

# Tool invocations
NTI_AVR_LAB77.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_AVR_LAB77.map -mmcu=atmega32 -o "NTI_AVR_LAB77.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_AVR_LAB77.lss: NTI_AVR_LAB77.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_AVR_LAB77.elf  >"NTI_AVR_LAB77.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTI_AVR_LAB77.hex: NTI_AVR_LAB77.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTI_AVR_LAB77.elf  "NTI_AVR_LAB77.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_AVR_LAB77.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_AVR_LAB77.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_AVR_LAB77.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
