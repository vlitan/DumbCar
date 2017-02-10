/*
 * motors.inc
 *
 *  Created: 12/6/2016 9:41:10 PM
 *   Author: virgil
 */
 #ifndef _MOTORS_INC_
 #define _MOTORS_INC_

 .include "pwm.inc"

 .def SL = r26 ;sign left
 .def VL = r27 ;value left
 .def SR = r28 ;sign left
 .def VR = r29 ;value left

 .macro init_motors
	clr SL ;clear registers
	clr VL
	clr SR
	clr VR
 	init_timer_0 ; init timers
	init_timer_2
 .endmacro

 .macro go ;call routines for each motor
 CALL go_left
 CALL go_right
 .endmacro

 #endif
