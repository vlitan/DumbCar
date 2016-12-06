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
;======defines=========

.cseg
; Replace with your application code
start:
    ;-----setup--------
	init_motors
	init_stack
	;------------------
	ldi SL, 1
	ldi VL, 0
	ldi r17, 10
	inf:
		add VL, r17
		go
		CALL delay_ms
	rjmp inf

;====include methods===
.include "utils.asm"
.include "pwm.asm"
.include "motors.asm"
;======================
