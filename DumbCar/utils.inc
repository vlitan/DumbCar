/*
 * utils.inc
 *
 *  Created: 12/5/2016 11:27:51 AM
 *   Author: virgil
 */ 

 #ifndef _UTILS_INC_
 #define _UTILS_INC_
.macro cb_to_reg_l ;  reg byte
	ldi r18, @1
	out @0, r18
.endmacro

.macro cb_to_reg_h ;  reg byte
	ldi r18, @1
	sts @0, r18
.endmacro

.macro init_stack ; initialise stack pointer
	cb_to_reg_l SPL, low(RAMEND)
	cb_to_reg_l SPH, high(RAMEND)
.endmacro


 #endif
