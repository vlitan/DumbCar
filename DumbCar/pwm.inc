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

 ;TODO enable disable via TCCRXY registers by COMXY1 bits

 ;=====timer 0=====
 .macro init_timer_0
	cb_to_reg_l TCCR0A, (1 << COM0B1) | (1 << COM0A1) | (1 << WGM01) | (1 << WGM00) ; fast pwm
	cb_to_reg_l TCCR0B, (1 << CS01)					; prescaler of 8
 .endmacro
 ;-----channel A---
 .macro enable_channel_0A
 	sbi DDRD, PD6			; set pin as output
 .endmacro

 .macro disable_channel_0A
 	cbi DDRD, PD6			; set pin as input (disable aka output)
 .endmacro

 .macro set_cmatch_0A
	cb_to_reg_l OCR0A, @0
 .endmacro

  .macro set_match_0A
	out OCR0A, @0
 .endmacro
 
 ;-----channel B---
 .macro enable_channel_0B
	 sbi DDRD, PD5			; set pin as output
 .endmacro

 .macro disable_channel_0B
	cbi DDRD, PD5			; set pin as input (aka disable output)
 .endmacro

 .macro set_cmatch_0B
	cb_to_reg_l OCR0B, @0
 .endmacro

 .macro set_match_0B
	out OCR0B, @0
 .endmacro
 ;=====timer 2=====
.macro init_timer_2
	cb_to_reg_h TCCR2A, (1 << COM2B1) | (1 << COM2A1) | (1 << WGM21) | (1 << WGM20) ; fast pwm
	cb_to_reg_h TCCR2B, (1 << CS21)					; prescaler of 8
 .endmacro
 ;-----channel A---
 .macro enable_channel_2A
 	sbi DDRB, PB3			; set pin as output
 .endmacro

 .macro disable_channel_2A
 	cbi DDRB, PB3			; set pin as input (disable aka output)
 .endmacro

 .macro set_cmatch_2A
	cb_to_reg_h OCR2A, @0
 .endmacro

 
 .macro set_match_2A
	sts OCR2A, @0
 .endmacro
 
 ;-----channel B---
 .macro enable_channel_2B
	 sbi DDRD, PD3			; set pin as output
 .endmacro

 .macro disable_channel_2B
	cbi DDRD, PD3			; set pin as input (aka disable output)
 .endmacro

 .macro set_cmatch_2B
	cb_to_reg_h OCR2B, @0
 .endmacro

  .macro set_match_2B
	sts OCR2B, @0
 .endmacro
 ;=================
 #endif
