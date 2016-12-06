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
;======defines=========
.def A=r26
.def B=r27
.def C=r28
.def D=r29

; Replace with your application code
start:
    ;-----setup--------
	init_timer_0
	enable_channel_0A
	enable_channel_0B
	
	init_timer_2
	enable_channel_2A
	enable_channel_2B

	ldi A, 0
	ldi B, 70
	ldi C, 130
	ldi D, 190
	;------------------
	inf:
		inc A
		inc B
		inc C
		inc D
		set_match_0A A
		set_match_0B B
		set_match_2A C
		set_match_2B D
		CALL delay_half_sec ; mult mai putin acum!
	rjmp inf

;====include methods===
.include "utils.asm"
.include "pwm.asm"
;======================
