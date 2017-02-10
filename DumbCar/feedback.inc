/*
 * feedback.inc
 *
 *  Created: 09-Feb-17 9:11:52 PM
 *   Author: virgil
 */ 

 #ifndef _FEEDBACK_INC_
 #define _FEEDBACK_INC_
 
 .include "misc.inc"
 .include "encoders.inc"
 .include "motors.inc"

.def MAP_RES=r0
.def MS_DIFL=r18
.def MS_DIFH=r19
.def LAST_MS1L=r5
.def LAST_MS1H=r6
.def LAST_MS2L=r7
.def LAST_MS2H=r8

.macro init_vars ;clear registers
	clr MS_DIFH
	clr MS_DIFL
	clr LAST_MS1H
	clr LAST_MS1L
	clr LAST_MS2H
	clr LAST_MS2L
.endmacro

 .macro feedback ;arg0 1 or 2. computes the speed and adjusts the pwm signal
		read_encoder @0		;read the encoders state. this is needed just to detect edges
		compute_des_speed	;get the desired speed. the value is stored in DS
		sbrc ENC_EDGE, @0	;check if there was an edge
			rjmp edg@0		;if there was jump to the apropriate label
		rjmp nedg@0			;if not jump elsewhere
		edg@0:;edge on encoder. compute interval on 16 bits from last edge
			mov MS_DIFL, MSL ;interval = now
			mov MS_DIFH, MSH ;
			.if @0 == 1
				sub MS_DIFL, LAST_MS1L;interval -= last
				sbc MS_DIFH, LAST_MS1H
				add LAST_MS1L, MS_DIFL ;last += interval
				adc LAST_MS1H, MS_DIFH ;in last is stored now
			.else
				sub MS_DIFL, LAST_MS2L;same thing as above
				sbc MS_DIFH, LAST_MS2H;the "last" variable differs
				add LAST_MS2L, MS_DIFL ;last += dif
				adc LAST_MS2H, MS_DIFH
			.endif
			; at this point the time interval between the edges is in MS_DIFH:MS_DIFL
		nedg@0:;***end edge on encoder***
	
	 	read_map MS_DIFL;map time interval to pwm values. result in MAP_RES
		
		cp DS, MAP_RES 
		breq all_fine@0 ;if values are equal all is fine
		cp DS, MAP_RES
		brlo ds_lower@0 ;if real speed < desired speed: motorspeed = desired_speed + desired_speed - real speed
			set_led
			mov r16, DS
			sub r16, MAP_RES
			add DS, r16
			;constrain DS. if overflow DS gets the maximum value
			brvs ovrflow@0
			rjmp no_ovrflow@0
			ovrflow@0:
				ldi DS, 0xff
			no_ovrflow@0:
		rjmp all_fine@0
		ds_lower@0:
			//slow down
		all_fine@0:
	
		.if @0 == 1 ;set the motors values
			mov VL, DS
			mov SL, DSS
		.else
			mov VR, DS
			mov SR, DSS
		.endif

	.endmacro
 
 #endif
