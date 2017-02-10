/*
 * utils.inc
 *
 *  Created: 12/5/2016 11:27:51 AM
 *   Author: virgil
 */ 

 #ifndef _UTILS_INC_
 #define _UTILS_INC_
;copy byte into register if the register is at low address
.macro cb_to_reg_l ;  reg byte
	ldi r16, @1
	out @0, r16
.endmacro

;copy byte into register if the register is at high address
.macro cb_to_reg_h ;  reg byte
	ldi r16, @1
	sts @0, r16
.endmacro

.macro init_stack ; initialise stack pointer
	cb_to_reg_l SPL, low(RAMEND)
	cb_to_reg_l SPH, high(RAMEND)
.endmacro

;sets bit in register if the register is at high address
.macro set_bit_h
	lds r16, @0
	ori r16, (1 << @1)
	sts @0, r16
.endmacro

;sets bit in register if the register is at low address
.macro set_bit_l
	in r16, @0
	ori r16, (1 << @1)
	out @0, r16
.endmacro

;clears bit in register if the register is at low address
.macro clear_bit_h
	lds r16, @0
	andi r16, ~(1 << @1)
	sts @0, r16
.endmacro

;clears bit in register if the register is at high address
.macro clear_bit_l
	in r16, @0
	andi r16, ~(1 << @1)
	out @0, r16
.endmacro

;toggle bit in register if the register is at high address
.macro toggle_bit_h
	lds r16, @0
	eor r16, (1 << @1)
	sts @0, r16
.endmacro

;toggle bit in register if the register is at low address
.macro toggle_bit_l ;TODO r17 used here
	in r16, @0
	push r17
	ldi r17, (1 << @1)
	eor r16, r17
	pop r17
	out @0, r16
.endmacro

 #endif
