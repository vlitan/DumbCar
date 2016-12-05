;
; DumbCar.asm
;
; Created: 12/5/2016 11:14:16 AM
; Author : virgil
;

;=====includes=========
.include "m328Pdef.inc"
.include "utils.inc"
.include "pwm.inc"
;======================

; Replace with your application code
start:
    ;-----setup--------
	init_timer_0
	enable_channel_0A
	enable_channel_0B
	set_match_0B 100
	set_match_0A 200
	;------------------
	inf:
		;----infinite loop--
	rjmp inf

;====include methods===
.include "utils.asm"
.include "pwm.asm"
;======================
