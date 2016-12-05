/*
 * utils.inc
 *
 *  Created: 12/5/2016 11:27:51 AM
 *   Author: virgil
 */ 

 #ifndef _UTILS_INC_
 #define _UTILS_INC_
.macro byte_to_reg_l ;  reg byte
	ldi r16, @1
	out @0, r16
.endmacro

.macro byte_to_reg_h ;  reg byte
	ldi r16, @1
	sts @0, r16
.endmacro

;TODO yet not working. HIGH / LOW Address issue
.macro set_bit ; reg index
	in r16, @0
	sbr r16,  @1
	out @0, r16
.endmacro
 #endif
