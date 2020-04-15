# ArduinoCore-Cpp17

Infrastructure to port ArduinoCore to C++17 (no C) - an attempt

For example, instead of PROGMEM tables, use constexpr inline functions, which saves space and does not require special inline assembly on AVR.

Could use more type safety, but let's cross the bridge when we come to it.

Could only test with the Arduino AVR boards that I own (Uno, Micro, MegaADK), Help wanted.

The source code for the AVR cores is at https://github.com/PeterSommerlad/ArduinoCore-avr/tree/Cpp17

### Achievement Log

* AVR Core package with self-built gcc 9.3.0, binutils 2.34 and avr-libc trunk (Macos Mojave only)
* ARM Core package with more recent compiler binary gcc9.2.1 from xpack project
* Own ARM Core package clone `package_Cpp17ARM_index.json`
* Own AVR Core package clone `package_Cpp17AVR_index.json`
* all .c files for all cores compiled as C++ 
* `pins_arduino.h` for all supported variants C++-ified
   * removed PROGMEM tables for better compile-time computation support
   * inlined most of wiring in `wiring_inline.h` to enable better inlining
   * provide overloads of wiring API that take template arguments instead of run-time function arguments for optimal codegen
* simplified tone.cpp to remove unused code and flexibility derived from original source, minimize its RAM requirement
* RAII class for inhibiting interrupts SafeStatusRegisterAndClearInterrupt in Arduino.h and used in wiring code.
* some improved type safety through enum class for PortType and PinType.
* removed non-converted obsolete variants and boards (unless being already converted): 
  * Adafruit Circuiplay (circuitplay32u4 - is almost 1-1 leonardo clone)
  * Arduino Ethernet (ethernet - retired product)
  * Arduino Gemma (gemma - retired product)
  * Arduino Robot (robot\_control, robot\_motor - retired product)
* USBApi.h defines u8 u16 and u32 -> refactor to use inttypes.h official names, also used in CDC.cpp
* cleaning up (partially) of Arduino.h to provide clean official interface
* better type safety through enums for all GPIO pins, Ports and timers

### Caveats

* So far only doing things for Macos Mojave (cross compiling all tools is just too much work for a proof of concept)
* Not automated tests by Arduino found, some written where I changed logic heavily (`pins_arduino.h`)
* Arduino API derived from Processing not always helpful or good C++

### Acknowledgements

* Thanks to https://www.hackster.io/wallarug/arduino-ide-creating-custom-boards-89f7a6
* Thanks to https://www.hackster.io/andrewm1100 for the python script
* Thanks to https://www.avrfreaks.net/forum/building-gcc83-avr-libc-linux-w-atpack-hooks for building avr-gcc
* Thanks to https://xpack.github.io/arm-none-eabi-gcc/ for arm-none-eabi-gcc


### Notes and Todos

* eliminate more macros and redundancy
* provide platform for download and for non-macos (Windows, Linux)
* check if gcc8.3 really provides better codegen as supposed
* may be help with keeping AVR backend non-deprecated for gcc10...
* adjust ARM core accordingly to 