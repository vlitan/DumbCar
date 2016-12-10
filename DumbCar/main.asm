;
; DumbCar.asm
;
; Created: 12/5/2016 11:14:16 AM
; Author : virgil
;

.org $00

;=====includes=========
.include "m328Pdef.inc"
.include "utils.inc"
.include "motors.inc"
.include "encoders.inc"
;======defines=========

.cseg
; Replace with your application code
start:
    ;-----setup--------
	init_motors
	init_stack
	init_encoders
	;------------------
	ldi SL, 0
	ldi VL, 0
	ldi r18, 1
	inf:
		ldi r17, 1
		in r19, PIND
		and r17, r19
		cp r17, r18
		breq else
			ldi VL, 200
		rjmp end
		else:
			ldi VL, 0
		end:
			go
	rjmp inf

;====include methods===
.include "utils.asm"
.include "pwm.asm"
.include "motors.asm"
.include "encoders.asm"
;======================
