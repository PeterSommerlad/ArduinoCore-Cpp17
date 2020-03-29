# ArduinoCore-Cpp17

Infrastructure to port ArduinoCore to C++17 (no C) - an attempt

For example, instead of PROGMEM tables, use constexpr inline functions, which saves space and does not require special inline assembly on AVR.

Could use more type safety, but let's cross the bridge when we come to it.

### Achievement Log

* AVR Core package with self-built gcc 9.3.0, binutils 2.34 and avr-libc trunk (Macos Mojave only)
* ARM Core package with more recent compiler binary gcc9.2.1 from xpack project
* Own ARM Core package clone `package_Cpp17ARM_index.json`
* Own AVR Core package clone `package_Cpp17AVR_index.json`
* all .c files for all cores compiled as C++ 
* `pins_arduino.h` and Arduino.h for Uno and Micro (AVR) C++-ified. (Boards microp and unop have the compiler settings) Flash-program-space savings 7-20% from simple test cases

### Caveats

* So far only doing things for Macos Mojave (cross compiling all tools is just too much work for a proof of concept)
* Not automated tests by Arduino found
* Arduino API derived from Processing not always helpful or good C++

### Acknowledgements

* Thanks to https://www.hackster.io/wallarug/arduino-ide-creating-custom-boards-89f7a6
* Thanks to https://www.hackster.io/andrewm1100 for the python script
* Thanks to https://www.avrfreaks.net/forum/building-gcc83-avr-libc-linux-w-atpack-hooks for building avr-gcc
* Thanks to https://xpack.github.io/arm-none-eabi-gcc/ for arm-none-eabi-gcc