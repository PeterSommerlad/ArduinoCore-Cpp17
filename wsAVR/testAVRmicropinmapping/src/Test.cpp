#include <cstdlib>
#define PROGMEM
// from Arduino.h
#define ARDUINO_MAIN
#define NOT_A_PORT 0
enum timer_values:uint8_t {
NOT_ON_TIMER=0,
TIMER0A = 1,
TIMER0B = 2,
TIMER1A = 3,
TIMER1B = 4,
TIMER1C = 5,
TIMER2  = 6,
TIMER2A = 7,
TIMER2B = 8,

TIMER3A = 9,
TIMER3B = 10,
TIMER3C = 11,
TIMER4A = 12,
TIMER4B = 13,
TIMER4C = 14,
TIMER4D = 15,
TIMER5A = 16,
TIMER5B = 17,
TIMER5C = 18

};

// from sfr_defs.h --> should be replaced
#define _BV(bit) (1 << (bit))


// from iom32u4.h
#define _SFR_IO8(x) (*(uint16_t *)(x))
#include "dummy_iom32u4.h"

#include "pins_arduino.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#define array_count_elements(arr) (sizeof(arr)/sizeof(arr[0]))

void testThatdigitalPinToPortProducesIdenticalResultsThatAreInTheMap() {
	for (uint8_t pin=0; pin < array_count_elements(digital_pin_to_port_PGM); ++pin)
		ASSERT_EQUAL((int)digital_pin_to_port_PGM[pin],(int)digital_pin_to_Port_PS(pin));
}
void testThatdigitalPinToBitmaskProducesIdenticalResultsThatAreInTheMap() {
	for (uint8_t pin=0; pin < array_count_elements(digital_pin_to_bit_mask_PGM); ++pin)
		ASSERT_EQUAL((int)digital_pin_to_bit_mask_PGM[pin],(int)bitmask::digital_pin_to_BitMask_PS(pin));
}
void testThatdigitalPinToTimerProducesIdenticalResultsThatAreInTheMap() {
	for (uint8_t pin=0; pin < array_count_elements(digital_pin_to_timer_PGM); ++pin)
		ASSERT_EQUAL((int)digital_pin_to_timer_PGM[pin],(int)digital_pin_to_timer_PS(pin));
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(testThatdigitalPinToPortProducesIdenticalResultsThatAreInTheMap));
	s.push_back(CUTE(testThatdigitalPinToBitmaskProducesIdenticalResultsThatAreInTheMap));
	s.push_back(CUTE(testThatdigitalPinToTimerProducesIdenticalResultsThatAreInTheMap));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
