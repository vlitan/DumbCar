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
	;------------------
	inf:
		;----infinite loop--
	rjmp inf

;====include methods===
.include "utils.asm"
.include "pwm.asm"
;======================
