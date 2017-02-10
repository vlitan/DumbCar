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
.include "tests.inc"
.include "feedback.inc"
;======defines=========
.org 0x0000
rjmp start ; reset ISR
.org 0x0016 ;Timer/Counter1 Capture Event
rjmp tim1_compa

map_vals:; map_vals[ms] == pwm
    .db 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 253, 250, 247, 244, 241, 238, 236, 233, 230, 227, 224, 221, 219, 216, 213, 210, 207, 204, 202, 199, 196, 193, 190, 187, 185, 182, 179, 176, 173, 170, 168, 165, 162, 159, 156, 153, 151, 148, 145, 142, 139, 136, 134, 131, 128, 125, 122, 119, 117, 114, 111, 108, 105, 102, 100, 97, 94, 91, 88, 85, 83, 80, 77, 74, 71, 68, 66, 63, 60, 57, 54, 51, 49, 46, 43, 40, 37, 34, 32, 29, 26, 23, 20, 17, 15, 12, 9, 6, 3, 0, 0

.cseg
start:
    ;-----setup-------- 5.1)
	init_vars
	init_motors
	init_stack
	init_adc
	init_led
	init_encoders
	init_timer
	sei
	;------------------

	run:
		clear_led
		feedback 1 ;feedback for left motor
		feedback 2 ;feedback for right motor
		go; apply the values in SL, VL, SR and VR to the motors
	rjmp run

;timing interrupt
tim1_compa:
	 inc MSL ;increase low byte
	 brvs ovrfl
	 rjmp no_ovrfl
	 ovrfl:;if overflow increase high byte
		inc MSH
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
