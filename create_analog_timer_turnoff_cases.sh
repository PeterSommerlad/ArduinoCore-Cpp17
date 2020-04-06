#!/bin/bash
function timers_to_turn_off() {
	case "$1" in
		0) echo A B ;;
		1) echo A B C ;;
		2) echo A B ;; 
		3) echo A B C ;;
		4) echo A B C   ;; 
		5) echo A B C ;;
	esac
}


for num in 0 1 2 3 4 5
do
	for c in `timers_to_turn_off $num `
	do
		# some wrong 0 4A $D, some missing some superfluous
		cat <<!EOF
	case TIMER${num}${c}: analog_timer_turnoff<TIMER${num}${c}>(); break;
!EOF

    done
done