/*
 * utils.inc
 *
 *  Created: 12/5/2016 11:27:51 AM
 *   Author: virgil
 */ 

 #ifndef _UTILS_INC_
 #define _UTILS_INC_
.macro byte_to_reg ;  reg byte
	ldi r16, @1
	out @0, r16
.endmacro

.macro set_byte ; reg index
	ldi r16, @0
	sbr r16,  @1
	out @0, r16
.endmacro
 #endif
