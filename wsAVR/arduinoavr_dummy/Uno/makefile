################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include libraries/Wire/src/utility/subdir.mk
-include libraries/Wire/src/subdir.mk
-include libraries/SoftwareSerial/src/subdir.mk
-include libraries/SPI/src/subdir.mk
-include libraries/HID/src/subdir.mk
-include cores/arduino/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: arduinoavr_dummy

# Tool invocations
arduinoavr_dummy: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	avr-g++ -Xlinker -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -Xlinker -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -Os -o "arduinoavr_dummy" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) arduinoavr_dummy
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
