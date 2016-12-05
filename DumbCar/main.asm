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
	set_match_0A 5
	set_match_0B 10
	enable_channel_0A
	enable_channel_0B
	
	init_timer_2
	set_match_2A 200
	set_match_2B 100
	enable_channel_2A
	enable_channel_2B
	;------------------
	inf:
		;----infinite loop--
	rjmp inf

;====include methods===
.include "utils.asm"
.include "pwm.asm"
;======================
