/*
 * tests.inc
 *
 *  Created: 09-Feb-17 10:45:13 AM
 *   Author: virgil
 */ 
 #ifndef _TESTS_INC_
 #define _TESTS_INC_

 .include "encoders.inc"
 .include "feedback.inc"
 .include "motors.inc"

 ;this simple test displays the value of an ecoder on the led
 .macro test_encoders
	read_encoder @0
	sbrc ENC_VALS, @0
		set_led
	sbrs ENC_VALS, @0
		clear_led
 .endmacro
 

 .macro test_motor
	compute_des_speed
	.if @0 == 1
		mov VL, DS
		mov SL, DSS
		call go_left
	.else
		mov VR, DS
		mov SR, DSS
		call go_right
	.endif
 .endmacro

 .macro test_lookup
 		ldi MS_DIFL, 1
		read_map MS_DIFL
		sbrc r0, 0
			rjmp tuna
			rjmp tdoua
			tuna:
				set_led
			tdoua:
 .endmacro

 .macro test_interval ;motor, check value
		read_encoder @0 ;5.2.2.1)
		compute_des_speed ;5.2.1) get the desired speed. the value is stored in DS
		sbrc ENC_EDGE, @0
			rjmp edg@0
		rjmp nedg@0
		edg@0:;***edge on encoder 2***
		 ;dif = now
			mov MS_DIFL, MSL
			mov MS_DIFH, MSH
		 ;dif -= last
			sub MS_DIFL, LAST_MSL
			sbc MS_DIFH, LAST_MSH
		 ;last += dif
			add LAST_MSL, MS_DIFL
			adc LAST_MSH, MS_DIFH
		; at this point the time interval between the edges is in MS_DIFH:MS_DIFL 5.2.2.3
		nedg@0:;***end edge on encoder 2***

		cpi MS_DIFL, @1
		brlo ndnd@0
			clear_led
			rjmp dndn@0
		ndnd@0:
			set_led
		dndn@0:

 .endmacro
 

 #endif
