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
#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12

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

namespace mega{

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST
	// -------------------------------------------
	PE	, // PE 0 ** 0 ** USART0_RX
	PE	, // PE 1 ** 1 ** USART0_TX
	PE	, // PE 4 ** 2 ** PWM2
	PE	, // PE 5 ** 3 ** PWM3
	PG	, // PG 5 ** 4 ** PWM4
	PE	, // PE 3 ** 5 ** PWM5
	PH	, // PH 3 ** 6 ** PWM6
	PH	, // PH 4 ** 7 ** PWM7
	PH	, // PH 5 ** 8 ** PWM8
	PH	, // PH 6 ** 9 ** PWM9
	PB	, // PB 4 ** 10 ** PWM10
	PB	, // PB 5 ** 11 ** PWM11
	PB	, // PB 6 ** 12 ** PWM12
	PB	, // PB 7 ** 13 ** PWM13
	PJ	, // PJ 1 ** 14 ** USART3_TX
	PJ	, // PJ 0 ** 15 ** USART3_RX
	PH	, // PH 1 ** 16 ** USART2_TX
	PH	, // PH 0 ** 17 ** USART2_RX
	PD	, // PD 3 ** 18 ** USART1_TX
	PD	, // PD 2 ** 19 ** USART1_RX
	PD	, // PD 1 ** 20 ** I2C_SDA
	PD	, // PD 0 ** 21 ** I2C_SCL
	PA	, // PA 0 ** 22 ** D22
	PA	, // PA 1 ** 23 ** D23
	PA	, // PA 2 ** 24 ** D24
	PA	, // PA 3 ** 25 ** D25
	PA	, // PA 4 ** 26 ** D26
	PA	, // PA 5 ** 27 ** D27
	PA	, // PA 6 ** 28 ** D28
	PA	, // PA 7 ** 29 ** D29
	PC	, // PC 7 ** 30 ** D30
	PC	, // PC 6 ** 31 ** D31
	PC	, // PC 5 ** 32 ** D32
	PC	, // PC 4 ** 33 ** D33
	PC	, // PC 3 ** 34 ** D34
	PC	, // PC 2 ** 35 ** D35
	PC	, // PC 1 ** 36 ** D36
	PC	, // PC 0 ** 37 ** D37
	PD	, // PD 7 ** 38 ** D38
	PG	, // PG 2 ** 39 ** D39
	PG	, // PG 1 ** 40 ** D40
	PG	, // PG 0 ** 41 ** D41
	PL	, // PL 7 ** 42 ** D42
	PL	, // PL 6 ** 43 ** D43
	PL	, // PL 5 ** 44 ** D44
	PL	, // PL 4 ** 45 ** D45
	PL	, // PL 3 ** 46 ** D46
	PL	, // PL 2 ** 47 ** D47
	PL	, // PL 1 ** 48 ** D48
	PL	, // PL 0 ** 49 ** D49
	PB	, // PB 3 ** 50 ** SPI_MISO
	PB	, // PB 2 ** 51 ** SPI_MOSI
	PB	, // PB 1 ** 52 ** SPI_SCK
	PB	, // PB 0 ** 53 ** SPI_SS
	PF	, // PF 0 ** 54 ** A0
	PF	, // PF 1 ** 55 ** A1
	PF	, // PF 2 ** 56 ** A2
	PF	, // PF 3 ** 57 ** A3
	PF	, // PF 4 ** 58 ** A4
	PF	, // PF 5 ** 59 ** A5
	PF	, // PF 6 ** 60 ** A6
	PF	, // PF 7 ** 61 ** A7
	PK	, // PK 0 ** 62 ** A8
	PK	, // PK 1 ** 63 ** A9
	PK	, // PK 2 ** 64 ** A10
	PK	, // PK 3 ** 65 ** A11
	PK	, // PK 4 ** 66 ** A12
	PK	, // PK 5 ** 67 ** A13
	PK	, // PK 6 ** 68 ** A14
	PK	, // PK 7 ** 69 ** A15
};

enum PinType:uint8_t {
	D00, D01, D02, D03, D04, D05, D06, D07,	D08, D09,
	D10, D11, D12, D13, D14, D15, D16, D17, D18, D19,
	D20, D21, D22, D23, D24, D25, D26, D27, D28, D29,
	D30, D31, D32, D33, D34, D35, D36, D37, D38, D39,
	D40, D41, D42, D43, D44, D45, D46, D47, D48, D49,
	D50, D51, D52, D53, D54, D55, D56, D57, D58, D59,
	D60, D61, D62, D63, D64, D65, D66, D67, D68, D69,
	USART0_RX=D00,USART0_TX=D01,
	PWM2=D02, PWM3=D03, PWM4=D04, PWM5=D05, PWM6=D06, PWM7=D07,
	PWM8=D08, PWM9=D09, PWM10=D10, PWM11=D11, PWM12=D12, PWM13=D13,
	USART3_TX=D14, USART3_RX=D15, USART2_TX=D16, USART2_RX=D17,
	USART1_TX=D18, USART1_RX=D19,
	SPI_MISO=D50, SPI_MOSI=D51, SPI_SCK=D52, SPI_SS=D53,
	I2C_SDA=D20, I2C_SCL=D21,
//	A0=D54, A1=D55, A2=D56, A3=D57, A4=D58, A5=D59,
//	A6=D60, A7=D61, A8=D62, A9=D63, A10=D64, A11=D65,
//	A12=D66, A13=D67, A14=D68, A15=D69
};
#undef PA
#undef PB
#undef PC
#undef PD
#undef PE
#undef PF
#undef PG
#undef PH
#undef PJ
#undef PK
#undef PL
enum class PortType: uint8_t {
	No_Port=0, PA=1, PB=2, PC=3, PD=4, PE=5, PF=6, PG=7, PH=8, PJ=10, PK=11, PL=12
};
#define NO_PORT PortType::No_Port

constexpr inline PortType digital_pin_to_Port_PS(uint8_t pin) noexcept {
	switch(static_cast<PinType>(pin)){
	case D22: case D23: case D24: case D25: case D26: case D27: case D28: case D29:
		return PortType::PA;
	case D10: case D11: case D12: case D13: case D50: case D51: case D52: case D53:
		return PortType::PB;
	case D30: case D31: case D32: case D33: case D34: case D35: case D36: case D37:
		return PortType::PC;
	case D18: case D19: case D20: case D21: case D38:
		return PortType::PD;
	case D00: case D01: case D02: case D03:	case D05:
		return PortType::PE;
	case D54: case D55: case D56: case D57: case D58: case D59: case D60: case D61:
		return PortType::PF;
	case D04: case D39: case D40: case D41:
		return PortType::PG;
	case D06: case D07: case D08: case D09: case D16: case D17:
		return PortType::PH;
	case D14: case D15:
		return PortType::PJ;
	case D62: case D63: case D64: case D65: case D66: case D67: case D68: case D69:
		return PortType::PK;
	case D42: case D43: case D44: case D45: case D46: case D47: case D48: case D49:
		return PortType::PL;
	}
	return NO_PORT;
}

void testThatdigitalPinToPortProducesIdenticalResultsThatAreInTheMap() {
	for (uint8_t pin=0; pin < array_count_elements(digital_pin_to_port_PGM); ++pin){
		std::string msg{"at pin: "};
		msg += std::to_string(static_cast<int>(pin));

		ASSERT_EQUALM(msg,(int)digital_pin_to_port_PGM[pin],(int)digital_pin_to_Port_PS(pin));
	}
}
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT
	// -------------------------------------------
	_BV( 0 )	, // PE 0 ** 0 ** USART0_RX
	_BV( 1 )	, // PE 1 ** 1 ** USART0_TX
	_BV( 4 )	, // PE 4 ** 2 ** PWM2
	_BV( 5 )	, // PE 5 ** 3 ** PWM3
	_BV( 5 )	, // PG 5 ** 4 ** PWM4
	_BV( 3 )	, // PE 3 ** 5 ** PWM5
	_BV( 3 )	, // PH 3 ** 6 ** PWM6
	_BV( 4 )	, // PH 4 ** 7 ** PWM7
	_BV( 5 )	, // PH 5 ** 8 ** PWM8
	_BV( 6 )	, // PH 6 ** 9 ** PWM9
	_BV( 4 )	, // PB 4 ** 10 ** PWM10
	_BV( 5 )	, // PB 5 ** 11 ** PWM11
	_BV( 6 )	, // PB 6 ** 12 ** PWM12
	_BV( 7 )	, // PB 7 ** 13 ** PWM13
	_BV( 1 )	, // PJ 1 ** 14 ** USART3_TX
	_BV( 0 )	, // PJ 0 ** 15 ** USART3_RX
	_BV( 1 )	, // PH 1 ** 16 ** USART2_TX
	_BV( 0 )	, // PH 0 ** 17 ** USART2_RX
	_BV( 3 )	, // PD 3 ** 18 ** USART1_TX
	_BV( 2 )	, // PD 2 ** 19 ** USART1_RX
	_BV( 1 )	, // PD 1 ** 20 ** I2C_SDA
	_BV( 0 )	, // PD 0 ** 21 ** I2C_SCL
	_BV( 0 )	, // PA 0 ** 22 ** D22
	_BV( 1 )	, // PA 1 ** 23 ** D23
	_BV( 2 )	, // PA 2 ** 24 ** D24
	_BV( 3 )	, // PA 3 ** 25 ** D25
	_BV( 4 )	, // PA 4 ** 26 ** D26
	_BV( 5 )	, // PA 5 ** 27 ** D27
	_BV( 6 )	, // PA 6 ** 28 ** D28
	_BV( 7 )	, // PA 7 ** 29 ** D29
	_BV( 7 )	, // PC 7 ** 30 ** D30
	_BV( 6 )	, // PC 6 ** 31 ** D31
	_BV( 5 )	, // PC 5 ** 32 ** D32
	_BV( 4 )	, // PC 4 ** 33 ** D33
	_BV( 3 )	, // PC 3 ** 34 ** D34
	_BV( 2 )	, // PC 2 ** 35 ** D35
	_BV( 1 )	, // PC 1 ** 36 ** D36
	_BV( 0 )	, // PC 0 ** 37 ** D37
	_BV( 7 )	, // PD 7 ** 38 ** D38
	_BV( 2 )	, // PG 2 ** 39 ** D39
	_BV( 1 )	, // PG 1 ** 40 ** D40
	_BV( 0 )	, // PG 0 ** 41 ** D41
	_BV( 7 )	, // PL 7 ** 42 ** D42
	_BV( 6 )	, // PL 6 ** 43 ** D43
	_BV( 5 )	, // PL 5 ** 44 ** D44
	_BV( 4 )	, // PL 4 ** 45 ** D45
	_BV( 3 )	, // PL 3 ** 46 ** D46
	_BV( 2 )	, // PL 2 ** 47 ** D47
	_BV( 1 )	, // PL 1 ** 48 ** D48
	_BV( 0 )	, // PL 0 ** 49 ** D49
	_BV( 3 )	, // PB 3 ** 50 ** SPI_MISO
	_BV( 2 )	, // PB 2 ** 51 ** SPI_MOSI
	_BV( 1 )	, // PB 1 ** 52 ** SPI_SCK
	_BV( 0 )	, // PB 0 ** 53 ** SPI_SS
	_BV( 0 )	, // PF 0 ** 54 ** A0
	_BV( 1 )	, // PF 1 ** 55 ** A1
	_BV( 2 )	, // PF 2 ** 56 ** A2
	_BV( 3 )	, // PF 3 ** 57 ** A3
	_BV( 4 )	, // PF 4 ** 58 ** A4
	_BV( 5 )	, // PF 5 ** 59 ** A5
	_BV( 6 )	, // PF 6 ** 60 ** A6
	_BV( 7 )	, // PF 7 ** 61 ** A7
	_BV( 0 )	, // PK 0 ** 62 ** A8
	_BV( 1 )	, // PK 1 ** 63 ** A9
	_BV( 2 )	, // PK 2 ** 64 ** A10
	_BV( 3 )	, // PK 3 ** 65 ** A11
	_BV( 4 )	, // PK 4 ** 66 ** A12
	_BV( 5 )	, // PK 5 ** 67 ** A13
	_BV( 6 )	, // PK 6 ** 68 ** A14
	_BV( 7 )	, // PK 7 ** 69 ** A15
};
struct bitmask {
enum  bitmask_in_byte:uint8_t {
	b0=1,b1=2,b2=4,b3=8,b4=16,b5=32,b6=64,b7=128
};
static constexpr inline uint8_t digital_pin_to_BitMask_PS(uint8_t const pin) noexcept {
	switch (static_cast<PinType>(pin)) {
		case D00: case D15: case D17: case D21: case D22: case D37: case D41: case D49: case D53: case D54: case D62:
			return bitmask_in_byte::b0;
		case D01: case D14: case D16: case D20: case D23: case D36: case D40: case D48: case D52: case D55: case D63:
			return bitmask_in_byte::b1;

		case D19: case D24: case D35: case D39: case D47: case D51: case D56: case D64:
			return bitmask_in_byte::b2;

		case D05: case D06: case D18: case D25: case D34: case D46: case D50: case D57: case D65:
			return bitmask_in_byte::b3;

		case D02: case D07: case D10: case D26: case D33: case D45: case D58: case D66:
			return bitmask_in_byte::b4;
		case D03: case D04: case D08: case D11: case D27: case D32: case D44: case D59: case D67:
			return bitmask_in_byte::b5;
		case D09: case D12: case D28: case D31: case D43: case D60: case D68:
			return bitmask_in_byte::b6;
		case D13: case D29: case D30: case D38: case D42: case D61: case D69:
			return bitmask_in_byte::b7;
	}
	return 0; // 0 might break code, may be, but would be better indicator.
}
};

void testThatdigitalPinToBitmaskProducesIdenticalResultsThatAreInTheMap() {
	for (uint8_t pin=0; pin < array_count_elements(digital_pin_to_bit_mask_PGM); ++pin)
		ASSERT_EQUAL((int)digital_pin_to_bit_mask_PGM[pin],(int)bitmask::digital_pin_to_BitMask_PS(pin));
}
const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS
	// -------------------------------------------
	NOT_ON_TIMER	, // PE 0 ** 0 ** USART0_RX
	NOT_ON_TIMER	, // PE 1 ** 1 ** USART0_TX
	TIMER3B	, // PE 4 ** 2 ** PWM2
	TIMER3C	, // PE 5 ** 3 ** PWM3
	TIMER0B	, // PG 5 ** 4 ** PWM4
	TIMER3A	, // PE 3 ** 5 ** PWM5
	TIMER4A	, // PH 3 ** 6 ** PWM6
	TIMER4B	, // PH 4 ** 7 ** PWM7
	TIMER4C	, // PH 5 ** 8 ** PWM8
	TIMER2B	, // PH 6 ** 9 ** PWM9
	TIMER2A	, // PB 4 ** 10 ** PWM10
	TIMER1A	, // PB 5 ** 11 ** PWM11
	TIMER1B	, // PB 6 ** 12 ** PWM12
	TIMER0A	, // PB 7 ** 13 ** PWM13
	NOT_ON_TIMER	, // PJ 1 ** 14 ** USART3_TX
	NOT_ON_TIMER	, // PJ 0 ** 15 ** USART3_RX
	NOT_ON_TIMER	, // PH 1 ** 16 ** USART2_TX
	NOT_ON_TIMER	, // PH 0 ** 17 ** USART2_RX
	NOT_ON_TIMER	, // PD 3 ** 18 ** USART1_TX
	NOT_ON_TIMER	, // PD 2 ** 19 ** USART1_RX
	NOT_ON_TIMER	, // PD 1 ** 20 ** I2C_SDA
	NOT_ON_TIMER	, // PD 0 ** 21 ** I2C_SCL
	NOT_ON_TIMER	, // PA 0 ** 22 ** D22
	NOT_ON_TIMER	, // PA 1 ** 23 ** D23
	NOT_ON_TIMER	, // PA 2 ** 24 ** D24
	NOT_ON_TIMER	, // PA 3 ** 25 ** D25
	NOT_ON_TIMER	, // PA 4 ** 26 ** D26
	NOT_ON_TIMER	, // PA 5 ** 27 ** D27
	NOT_ON_TIMER	, // PA 6 ** 28 ** D28
	NOT_ON_TIMER	, // PA 7 ** 29 ** D29
	NOT_ON_TIMER	, // PC 7 ** 30 ** D30
	NOT_ON_TIMER	, // PC 6 ** 31 ** D31
	NOT_ON_TIMER	, // PC 5 ** 32 ** D32
	NOT_ON_TIMER	, // PC 4 ** 33 ** D33
	NOT_ON_TIMER	, // PC 3 ** 34 ** D34
	NOT_ON_TIMER	, // PC 2 ** 35 ** D35
	NOT_ON_TIMER	, // PC 1 ** 36 ** D36
	NOT_ON_TIMER	, // PC 0 ** 37 ** D37
	NOT_ON_TIMER	, // PD 7 ** 38 ** D38
	NOT_ON_TIMER	, // PG 2 ** 39 ** D39
	NOT_ON_TIMER	, // PG 1 ** 40 ** D40
	NOT_ON_TIMER	, // PG 0 ** 41 ** D41
	NOT_ON_TIMER	, // PL 7 ** 42 ** D42
	NOT_ON_TIMER	, // PL 6 ** 43 ** D43
	TIMER5C	, // PL 5 ** 44 ** D44
	TIMER5B	, // PL 4 ** 45 ** D45
	TIMER5A	, // PL 3 ** 46 ** D46
	NOT_ON_TIMER	, // PL 2 ** 47 ** D47
	NOT_ON_TIMER	, // PL 1 ** 48 ** D48
	NOT_ON_TIMER	, // PL 0 ** 49 ** D49
	NOT_ON_TIMER	, // PB 3 ** 50 ** SPI_MISO
	NOT_ON_TIMER	, // PB 2 ** 51 ** SPI_MOSI
	NOT_ON_TIMER	, // PB 1 ** 52 ** SPI_SCK
	NOT_ON_TIMER	, // PB 0 ** 53 ** SPI_SS
	NOT_ON_TIMER	, // PF 0 ** 54 ** A0
	NOT_ON_TIMER	, // PF 1 ** 55 ** A1
	NOT_ON_TIMER	, // PF 2 ** 56 ** A2
	NOT_ON_TIMER	, // PF 3 ** 57 ** A3
	NOT_ON_TIMER	, // PF 4 ** 58 ** A4
	NOT_ON_TIMER	, // PF 5 ** 59 ** A5
	NOT_ON_TIMER	, // PF 6 ** 60 ** A6
	NOT_ON_TIMER	, // PF 7 ** 61 ** A7
	NOT_ON_TIMER	, // PK 0 ** 62 ** A8
	NOT_ON_TIMER	, // PK 1 ** 63 ** A9
	NOT_ON_TIMER	, // PK 2 ** 64 ** A10
	NOT_ON_TIMER	, // PK 3 ** 65 ** A11
	NOT_ON_TIMER	, // PK 4 ** 66 ** A12
	NOT_ON_TIMER	, // PK 5 ** 67 ** A13
	NOT_ON_TIMER	, // PK 6 ** 68 ** A14
	NOT_ON_TIMER	, // PK 7 ** 69 ** A15
};

constexpr inline uint8_t digital_pin_to_timer_PS(uint8_t const pin) noexcept {
	switch (static_cast<PinType>(pin)) {
	case D02:
		return TIMER3B;
	case D03:
		return TIMER3C;
	case D04:
		return TIMER0B;
	case D05:
		return TIMER3A;
	case D06:
		return TIMER4A;
	case D07:
		return TIMER4B;
	case D08:
		return TIMER4C;
	case D09:
		return TIMER2B;
	case D10:
		return TIMER2A;
	case D11:
		return TIMER1A;
	case D12:
		return TIMER1B;
	case D13:
		return TIMER0A;
	case D44:
		return TIMER5C;
	case D45:
		return TIMER5B;
	case D46:
		return TIMER5A;
	default:
		return NOT_ON_TIMER;
	}
}
void testThatdigitalPinToTimerProducesIdenticalResultsThatAreInTheMap() {
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
	s.push_back(CUTE(mega::testThatdigitalPinToPortProducesIdenticalResultsThatAreInTheMap));
	s.push_back(CUTE(mega::testThatdigitalPinToBitmaskProducesIdenticalResultsThatAreInTheMap));
	s.push_back(CUTE(mega::testThatdigitalPinToTimerProducesIdenticalResultsThatAreInTheMap));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
