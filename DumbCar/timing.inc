/*
 * timing.inc
 *
 *  Created: 12/18/2016 3:49:36 PM
 *   Author: virgil
 */ 

 #ifndef _TIMING_INC_
 #define _TIMING_INC_
 
 .def MSL = r20
 .def MSH = r21
 
 .macro init_timer ; init timer, interupts occur each 0.5 ms
 /*   cb_to_reg_h TCCR1B,(1 << WGM12)|(1<<CS11)|(1<<CS10); timer clock = system clock/64
    cb_to_reg_h OCR1AH, 0x00
    cb_to_reg_h OCR1AL, 0xff*/


	cb_to_reg_h TCCR1B,(1 << WGM12)|(1<<CS11); timer clock = system clock/8
	cb_to_reg_h OCR1AH, 0x0f ;set match value to 499
	cb_to_reg_h OCR1AL, 0xf3
	cb_to_reg_h TIMSK1, 1<<OCIE1A; 
 .endmacro

 #endif
