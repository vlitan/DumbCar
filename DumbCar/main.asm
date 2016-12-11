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
.include "analog_input.inc"
;======defines=========

.cseg
; Replace with your application code
start:
    ;-----setup--------
	init_motors
	init_stack
	init_encoders
	init_adc
	;------------------
	ldi SL, 0
	ldi VL, 0
	inf:
		analog_read
		mov VL, DS
		go
		CALL delay_ms
	rjmp inf

;====include methods===
.include "utils.asm"
.include "pwm.asm"
.include "motors.asm"
.include "encoders.asm"
.include "analog_input.asm"
;======================
