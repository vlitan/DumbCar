/*
 * pwm.inc
 *
 *  Created: 12/5/2016 11:27:36 AM
 *   Author: virgil
 */ 

 #ifndef _PWM_INC_
 #define _PWM_INC_

 .include "m328Pdef.inc"
 .include "utils.inc"

 ;=====timer 0=====
 .macro init_timer_0
	byte_to_reg TCCR0A, (1 << WGM01) | (1 << WGM00)
	byte_to_reg TCCR0B, (1 << CS01)
 .endmacro
 ;-----channel A---
 .macro enable_channel_0A
	set_byte TCCR0A, COM0A1
 .endmacro

 .macro disable_channel_0A
	cbi TCCR0A, COM0A1
 .endmacro

 .macro set_match_0A
	byte_to_reg OCR0A, @0
 .endmacro
 
 ;-----channel B---
 .macro enable_channel_0B
	set_byte TCCR0A, COM0B1
 .endmacro

 .macro disable_channel_0B
	cbi TCCR0A, COM0B1
 .endmacro

 .macro set_match_0B
	byte_to_reg OCR0B, @0
 .endmacro

 ;=====timer 2=====
 ;-----channel A---
 ;-----channel B---
 ;=================
 #endif
