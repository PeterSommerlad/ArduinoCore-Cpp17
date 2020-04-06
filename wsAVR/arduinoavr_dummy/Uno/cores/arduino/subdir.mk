################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/WInterrupts.c \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/hooks.c \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring.c \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_analog.c \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_digital.c \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_pulse.c \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_shift.c 

CPP_SRCS += \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/CDC.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial0.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial1.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial2.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial3.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/IPAddress.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/PluggableUSB.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/Print.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/Stream.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/Tone.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/USBCore.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/WMath.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/WString.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/abi.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/main.cpp \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/new.cpp 

S_UPPER_SRCS += \
/Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_pulse.S 

OBJS += \
./cores/arduino/CDC.o \
./cores/arduino/HardwareSerial.o \
./cores/arduino/HardwareSerial0.o \
./cores/arduino/HardwareSerial1.o \
./cores/arduino/HardwareSerial2.o \
./cores/arduino/HardwareSerial3.o \
./cores/arduino/IPAddress.o \
./cores/arduino/PluggableUSB.o \
./cores/arduino/Print.o \
./cores/arduino/Stream.o \
./cores/arduino/Tone.o \
./cores/arduino/USBCore.o \
./cores/arduino/WInterrupts.o \
./cores/arduino/WMath.o \
./cores/arduino/WString.o \
./cores/arduino/abi.o \
./cores/arduino/hooks.o \
./cores/arduino/main.o \
./cores/arduino/new.o \
./cores/arduino/wiring.o \
./cores/arduino/wiring_analog.o \
./cores/arduino/wiring_digital.o \
./cores/arduino/wiring_pulse.o \
./cores/arduino/wiring_shift.o 

C_DEPS += \
./cores/arduino/WInterrupts.d \
./cores/arduino/hooks.d \
./cores/arduino/wiring.d \
./cores/arduino/wiring_analog.d \
./cores/arduino/wiring_digital.d \
./cores/arduino/wiring_pulse.d \
./cores/arduino/wiring_shift.d 

CPP_DEPS += \
./cores/arduino/CDC.d \
./cores/arduino/HardwareSerial.d \
./cores/arduino/HardwareSerial0.d \
./cores/arduino/HardwareSerial1.d \
./cores/arduino/HardwareSerial2.d \
./cores/arduino/HardwareSerial3.d \
./cores/arduino/IPAddress.d \
./cores/arduino/PluggableUSB.d \
./cores/arduino/Print.d \
./cores/arduino/Stream.d \
./cores/arduino/Tone.d \
./cores/arduino/USBCore.d \
./cores/arduino/WMath.d \
./cores/arduino/WString.d \
./cores/arduino/abi.d \
./cores/arduino/main.d \
./cores/arduino/new.d 


# Each subdirectory must supply rules for building sources it contributes
cores/arduino/CDC.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/CDC.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/HardwareSerial.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/HardwareSerial0.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial0.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/HardwareSerial1.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial1.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/HardwareSerial2.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/HardwareSerial3.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/HardwareSerial3.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/IPAddress.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/PluggableUSB.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/PluggableUSB.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/Print.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/Print.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/Stream.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/Stream.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/Tone.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/Tone.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/USBCore.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/WInterrupts.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	avr-g++ -std=c++17 -x c++ -DF_CPU=16000000L -DARDUINO=10812 -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/WMath.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/WMath.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/WString.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/WString.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/abi.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/abi.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/hooks.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/hooks.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	avr-g++ -std=c++17 -x c++ -DF_CPU=16000000L -DARDUINO=10812 -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/main.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/new.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/new.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	avr-g++ -std=c++17 -DARDUINO=10812 -DF_CPU=16000000L -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -I/Users/sop/Arduino/ArduinoCore-avr/libraries/SoftwareSerial/src -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/wiring.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	avr-g++ -std=c++17 -x c++ -DF_CPU=16000000L -DARDUINO=10812 -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/wiring_analog.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	avr-g++ -std=c++17 -x c++ -DF_CPU=16000000L -DARDUINO=10812 -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/wiring_digital.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	avr-g++ -std=c++17 -x c++ -DF_CPU=16000000L -DARDUINO=10812 -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/wiring_pulse.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_pulse.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Assembler'
	avr-as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/wiring_pulse.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	avr-g++ -std=c++17 -x c++ -DF_CPU=16000000L -DARDUINO=10812 -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cores/arduino/wiring_shift.o: /Users/sop/Arduino/ArduinoCore-avr/cores/arduino/wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	avr-g++ -std=c++17 -x c++ -DF_CPU=16000000L -DARDUINO=10812 -DFLASHEND=32256 -DRAMEND=2048 -DARDUINO_arch=avr -DARDUINO_unop -DARDUINO_ARCH_avr -DUsePetersCpp17 -I/Users/sop/Arduino/ArduinoCore-avr/variants/standard -I/Users/sop/Arduino/ArduinoCore-avr/cores/arduino -Os -g3 -Wall -c -fmessage-length=0 -mmcu=atmega328p -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


