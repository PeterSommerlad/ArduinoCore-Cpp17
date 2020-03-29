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

namespace micro {
const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PD, // D0 - PD2
	PD,	// D1 - PD3
	PD, // D2 - PD1
	PD,	// D3 - PD0
	PD,	// D4 - PD4
	PC, // D5 - PC6
	PD, // D6 - PD7
	PE, // D7 - PE6

	PB, // D8 - PB4
	PB,	// D9 - PB5
	PB, // D10 - PB6
	PB,	// D11 - PB7
	PD, // D12 - PD6
	PC, // D13 - PC7

	PB,	// D14 - MISO - PB3
	PB,	// D15 - SCK - PB1
	PB,	// D16 - MOSI - PB2
	PB,	// D17 - SS - PB0

	PF,	// D18 - A0 - PF7
	PF, // D19 - A1 - PF6
	PF, // D20 - A2 - PF5
	PF, // D21 - A3 - PF4
	PF, // D22 - A4 - PF1
	PF, // D23 - A5 - PF0

	PD, // D24 / D4 - A6 - PD4
	PD, // D25 / D6 - A7 - PD7
	PB, // D26 / D8 - A8 - PB4
	PB, // D27 / D9 - A9 - PB5
	PB, // D28 / D10 - A10 - PB6
	PD, // D29 / D12 - A11 - PD6
	PD, // D30 / TX Led - PD5
};
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(2), // D0 - PD2
	_BV(3),	// D1 - PD3
	_BV(1), // D2 - PD1
	_BV(0),	// D3 - PD0
	_BV(4),	// D4 - PD4
	_BV(6), // D5 - PC6
	_BV(7), // D6 - PD7
	_BV(6), // D7 - PE6

	_BV(4), // D8 - PB4
	_BV(5),	// D9 - PB5
	_BV(6), // D10 - PB6
	_BV(7),	// D11 - PB7
	_BV(6), // D12 - PD6
	_BV(7), // D13 - PC7

	_BV(3),	// D14 - MISO - PB3
	_BV(1),	// D15 - SCK - PB1
	_BV(2),	// D16 - MOSI - PB2
	_BV(0),	// D17 - SS - PB0

	_BV(7),	// D18 - A0 - PF7
	_BV(6), // D19 - A1 - PF6
	_BV(5), // D20 - A2 - PF5
	_BV(4), // D21 - A3 - PF4
	_BV(1), // D22 - A4 - PF1
	_BV(0), // D23 - A5 - PF0

	_BV(4), // D24 / D4 - A6 - PD4
	_BV(7), // D25 / D6 - A7 - PD7
	_BV(4), // D26 / D8 - A8 - PB4
	_BV(5), // D27 / D9 - A9 - PB5
	_BV(6), // D28 / D10 - A10 - PB6
	_BV(6), // D29 / D12 - A11 - PD6
	_BV(5), // D30 / TX Led - PD5
};
const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER0B,		/* 3 */
	NOT_ON_TIMER,
	TIMER3A,		/* 5 */
	TIMER4D,		/* 6 */
	NOT_ON_TIMER,

	NOT_ON_TIMER,
	TIMER1A,		/* 9 */
	TIMER1B,		/* 10 */
	TIMER0A,		/* 11 */

	NOT_ON_TIMER,
	TIMER4A,		/* 13 */

	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,

	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

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

}

namespace uno{
// tests for uno timers *most tricky part
enum class PinType:uint8_t {
	D00, D01, D02, D03, D04, D05, D06, D07, D08, D09, D10, D11, D12, D13,
	A0 = PIN_A0, A1, A2, A3, A4, A5
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, /* 0 - port D */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	// on the ATmega168, digital pin 3 has hardware pwm
#if defined(__AVR_ATmega8__)
	NOT_ON_TIMER,
#else
	TIMER2B,
#endif
	NOT_ON_TIMER,
	// on the ATmega168, digital pins 5 and 6 have hardware pwm
#if defined(__AVR_ATmega8__)
	NOT_ON_TIMER,
	NOT_ON_TIMER,
#else
	TIMER0B,
	TIMER0A,
#endif
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 8 - port B */
	TIMER1A,
	TIMER1B,
#if defined(__AVR_ATmega8__)
	TIMER2,
#else
	TIMER2A,
#endif
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 14 - port C */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

constexpr inline uint8_t digital_pin_to_timer_PS(uint8_t const pin) noexcept {
	switch (static_cast<PinType>(pin)) {
#if defined(__AVR_ATmega8__)
	case PinType::D11:
		return TIMER2;//,		/* 11 */
#else
	case PinType::D03:/* 3 */
		return 	TIMER2B;
	case PinType::D05:
		return TIMER0B;//,		/* 5 */
	case PinType::D06:
		return TIMER0A;//,		/* 6 */
	case PinType::D11:
		return TIMER2A;//,		/* 11 */
#endif
	case PinType::D09:
		return TIMER1A;//,		/* 9 */
	case PinType::D10:
		return TIMER1B;//,		/* 10 */
	default:
		return NOT_ON_TIMER;
	}
}
void unotestThatdigitalPinToTimerProducesIdenticalResultsThatAreInTheMap() {
	for (uint8_t pin=0; pin < array_count_elements(digital_pin_to_timer_PGM); ++pin)
		ASSERT_EQUAL((int)digital_pin_to_timer_PGM[pin],(int)digital_pin_to_timer_PS(pin));
}

}


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(micro::testThatdigitalPinToPortProducesIdenticalResultsThatAreInTheMap));
	s.push_back(CUTE(micro::testThatdigitalPinToBitmaskProducesIdenticalResultsThatAreInTheMap));
	s.push_back(CUTE(micro::testThatdigitalPinToTimerProducesIdenticalResultsThatAreInTheMap));
	s.push_back(CUTE(uno::unotestThatdigitalPinToTimerProducesIdenticalResultsThatAreInTheMap));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
