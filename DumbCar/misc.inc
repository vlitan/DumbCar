/*
 * misc.inc
 *
 *  Created: 12/13/2016 10:51:57 PM
 *   Author: virgil
 */ 
 #ifndef _MISC_INC_
 #define _MISC_INC_

 .include "utils.inc"

 .macro init_led
	sbi DDRD, PD2
 .endmacro

 .macro set_led
	sbi PORTD, PD2
 .endmacro

 .macro clear_led
	cbi PORTD, PD2
 .endmacro

 .macro toggle_led
	toggle_bit_l PORTD, PD2
 .endmacro

 .macro val_to_led
 .endmacro

 #endif
