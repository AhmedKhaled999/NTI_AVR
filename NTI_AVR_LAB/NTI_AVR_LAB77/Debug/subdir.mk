################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../LCD_Program.c \
../LED_Config.c \
../LED_Progrm.c \
../SWITCH_Config.c \
../SWITCH_Program.c \
../main.c 

OBJS += \
./DIO_Program.o \
./LCD_Program.o \
./LED_Config.o \
./LED_Progrm.o \
./SWITCH_Config.o \
./SWITCH_Program.o \
./main.o 

C_DEPS += \
./DIO_Program.d \
./LCD_Program.d \
./LED_Config.d \
./LED_Progrm.d \
./SWITCH_Config.d \
./SWITCH_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


