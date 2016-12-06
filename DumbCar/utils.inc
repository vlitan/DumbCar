/*
 * utils.inc
 *
 *  Created: 12/5/2016 11:27:51 AM
 *   Author: virgil
 */ 

 #ifndef _UTILS_INC_
 #define _UTILS_INC_
.macro cb_to_reg_l ;  reg byte
	ldi r16, @1
	out @0, r16
.endmacro

.macro cb_to_reg_h ;  reg byte
	ldi r16, @1
	sts @0, r16
.endmacro




 #endif
