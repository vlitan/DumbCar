/*
 * timing.inc
 *
 *  Created: 12/18/2016 3:49:36 PM
 *   Author: virgil
 */ 

 #ifndef _TIMING_INC_
 #define _TIMING_INC_
 
 .def MSL = r20 ;milliseconds low byte
 .def MSH = r21 ;milliseconds high byte
 
 .macro init_timer ; init timer, interupts occur each 1 ms
	clr MSL ;clear registers
	clr MSH
 	cb_to_reg_h OCR1AH, 0x1A;0x7A	;set compare values
    cb_to_reg_h OCR1AL, 0x10;0x10
	cb_to_reg_h TIMSK1, 1<<OCIE1A	;enable match interrupt
    cb_to_reg_h TCCR1B,(1 << WGM12)|(1 << CS10); timer clock = system clock; start clock
 .endmacro

 #endif
