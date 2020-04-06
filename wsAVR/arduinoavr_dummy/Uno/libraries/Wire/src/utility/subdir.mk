################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/sop/Arduino/ArduinoCore-avr/libraries/Wire/src/utility/twi.c 

OBJS += \
./libraries/Wire/src/utility/twi.o 

C_DEPS += \
./libraries/Wire/src/utility/twi.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/Wire/src/utility/twi.o: /Users/sop/Arduino/ArduinoCore-avr/libraries/Wire/src/utility/twi.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	avr-g++ -std=c++17 -x c++ -DF_CPU=16000000L -DARDUINO=10812 -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


