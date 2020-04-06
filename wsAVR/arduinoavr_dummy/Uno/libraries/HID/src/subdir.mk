################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/Users/sop/Arduino/ArduinoCore-avr/libraries/HID/src/HID.cpp 

OBJS += \
./libraries/HID/src/HID.o 

CPP_DEPS += \
./libraries/HID/src/HID.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/HID/src/HID.o: /Users/sop/Arduino/ArduinoCore-avr/libraries/HID/src/HID.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


