#!/bin/bash

# create template code for timers to set pwm on AVRmegaxxx fro Arduino

cat <<!EOF0

// generated from createAnalogWriteTemplateSpecializations.sh
#ifndef _SFR_BYTE
#include <avr/io.h>
#endif

template <typename PTR>
inline
__attribute__((always_inline))
void cbi(PTR sfr, uint8_t const bit)
{
	(_SFR_BYTE(sfr) &= ~_BV(bit));
}
template <typename PTR>
inline
__attribute__((always_inline))
void sbi(PTR sfr, uint8_t const bit)
{
	(_SFR_BYTE(sfr) |= _BV(bit));
}

template <uint8_t pin, uint8_t val>
inline
__attribute__((always_inline))
void digitalWrite();


template<timer_values t>
inline
__attribute__((always_inline)) 
void setPWMValue(int val);



// special cases taken from avr
#if defined(TCCR0) && defined(COM00) && !defined(__AVR_ATmega8__)
template <> inline 
__attribute__((always_inline)) 
void setPWMValue<TIMER0A>(int val) 
{
	sbi(TCCR0, COM00);
	OCR0 = val;
}
#endif
#if defined(TCCR2) && defined(COM21)
template <> inline 
__attribute__((always_inline)) 
void setPWMValue<TIMER2>(int val) 
{
	sbi(TCCR2, COM21);
	OCR2 = val;
}
#endif
#if defined(TCCR4A) 
template <> inline 
__attribute__((always_inline)) 
void setPWMValue<TIMER4A>(int val) 
{
	sbi(TCCR4A, COM4A1);
	#if defined(COM4A0)
	cbi(TCCR4A, COM4A0);
	#endif
	OCR4A = val;
}
#endif
#if defined(TCCR4C) && defined(COM4D1) 
template <> inline 
__attribute__((always_inline)) 
void setPWMValue<TIMER4D>(int val) 
{
	sbi(TCCR4C, COM4D1);
	#if defined(COM4D0)
	cbi(TCCR4C, COM4D0);
	#endif
	OCR4D = val;
}
#endif

!EOF0

function timers() {
	case "$1" in
		0) echo A B ;;
		1) echo A B C ;;
		2) echo A B ;;
		3) echo A B C ;;
		4) echo B C  ;; # 4A and 4 D special cases
		5) echo A B C ;;
	esac
}

for num in 0 1 2 3 4 5
do
	for c in `timers $num `
	do
		# some wrong 0 4A $D, some missing some superfluous
		cat <<!EOF
#if defined(TCCR${num}A) && defined(COM${num}${c}1)
template <> inline 
__attribute__((always_inline))
void setPWMValue<TIMER${num}${c}>(int val) 
{
	sbi(TCCR${num}A, COM${num}${c}1);
	OCR${num}${c} = val;
}
#endif
!EOF
done
done		


cat <<!EOF2
template<PinType pin>
void setPWMValuePin(int val){
	if constexpr (digitalPinToTimer(pin) != NOT_ON_TIMER)
		setPWMValue<digitalPinToTimer(pin)>(val);
	else {
		if (val < 128) {
			digitalWrite<pin, LOW>();
		} else {
			digitalWrite<pin, HIGH>();
		}
	}
}


// to be defined in pins_arduino.h afterwards, since it depends on available timers
inline void analog_timer_turnoff(timer_values const theTimer) ;

// make it a compile error if called with NOT_ON_TIMER


template<timer_values t> inline 
__attribute__((always_inline))
void analog_timer_turnoff() ;

template<PinType pin> inline
__attribute__((always_inline)) 
void analog_pin_to_timer_turnoff()  
{
	if constexpr(digital_pin_to_timer_PS(pin) != NOT_ON_TIMER)
		analog_timer_turnoff<digital_pin_to_timer_PS(pin)>();
}


#if defined(TCCR2) && defined(COM21)
template <> inline 
__attribute__((always_inline))
void analog_timer_turnoff<TIMER2>() 
{
	cbi(TCCR2, COM21);
}
#endif

#if defined(TCCR4C) && defined(COM4D1)
template <> inline 
__attribute__((always_inline))
void analog_timer_turnoff<TIMER4D>() 
{
	cbi(TCCR4C, COM4D1);
}
#endif

!EOF2

function timers_to_turn_off() {
	case "$1" in
		0) echo A B ;;
		1) echo A B C ;;
		2) echo A B ;; # 2 nothing is special case
		3) echo A B C ;;
		4) echo A B C   ;; # 4 D special case
		5) echo A B C ;;
	esac
}


for num in 0 1 2 3 4 5
do
	for c in `timers_to_turn_off $num `
	do
		# some wrong 0 4A $D, some missing some superfluous
		cat <<!EOF
#if defined(TCCR${num}A) && defined(COM${num}${c}1)
template <> inline 
__attribute__((always_inline))
void analog_timer_turnoff<TIMER${num}${c}>() 
{
	cbi(TCCR${num}A, COM${num}${c}1);
}
#endif
!EOF
done
done		



