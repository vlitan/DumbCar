/*
 * timing.inc
 *
 *  Created: 12/18/2016 3:49:36 PM
 *   Author: virgil
 */ 

 #ifndef _TIMING_INC_
 #define _TIMING_INC_
 
 .def MS = r20
 
 .macro init_timer
	cb_to_reg_h TCCR1B,(1 << WGM12)|(1<<CS11)|(1<<CS10); timer clock = system clock/64
	cb_to_reg_h OCR1AH, 0xff
	cb_to_reg_h OCR1AL, 0xff
	cb_to_reg_h TIMSK1, 1<<OCIE1A; 
 .endmacro

 #endif
