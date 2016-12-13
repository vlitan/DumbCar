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
.include "misc.inc"
;======defines=========

.cseg ;code segment

start:
    ;-----setup--------
	init_motors
	init_stack
	init_encoders
	init_adc
	init_led
	;------------------
	inf:
		toggle_led
		CALL delay_ms
	rjmp inf

;====include methods===
.include "utils.asm"
.include "pwm.asm"
.include "motors.asm"
.include "encoders.asm"
.include "analog_input.asm"
.include "misc.asm"
;======================
