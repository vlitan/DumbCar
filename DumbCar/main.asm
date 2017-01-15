;
; DumbCar.asm
;
; Created: 12/5/2016 11:14:16 AM
; Author : virgil
;



;=====includes=========
.include "m328Pdef.inc"
.include "utils.inc"
.include "motors.inc"
.include "encoders.inc"
.include "analog_input.inc"
.include "misc.inc"
.include "timing.inc"
;======defines=========
.org 0x0000
rjmp start ; reset ISR
.org 0x0016 ;Timer/Counter1 Capture Event
rjmp tim1_compa

start:
    ;-----setup-------- 5.1)
	init_motors
	init_stack
	init_encoders
	init_adc
	init_led
	init_timer
	sei
	;------------------
	ldi SL, 0
	ldi VL, 255
	ldi SR, 0
	ldi VR, 255
	run: ;5.2)
		compute_des_speed ;5.2.1) get the desired speed. the value is stored in DS
		mov SL, DSS
		mov SR, DSS
		mov VL, DS
		mov VR, DS
		go ;5.2.5) apply the values in SL, VL, SR and VR to the motors
	rjmp run
;timing interrupt
tim1_compa:
	 inc MSL
	 brvs ovrfl
	 rjmp no_ovrfl
	 ovrfl: 
		inc MSH
	//	toggle_led
	 no_ovrfl:
	reti
;====include methods===
.include "utils.asm"
.include "pwm.asm"
.include "motors.asm"
.include "encoders.asm"
.include "analog_input.asm"
.include "misc.asm"
;======================
