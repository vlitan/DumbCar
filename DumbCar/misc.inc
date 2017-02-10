/*
 * misc.inc
 *
 *  Created: 12/13/2016 10:51:57 PM
 *   Author: virgil
 */ 
 #ifndef _MISC_INC_
 #define _MISC_INC_

 .def DSS = r22 // desired speed sign

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

  .macro compute_des_speed
 analog_read 0
 ldi r16, 127
 cp r16, DS
 brsh gre
	ldi DSS, 1
	sub DS, r16
 rjmp end4
 gre:
	ldi DSS, 0
	sub DS, r16
	inc r16
	sub r16, DS
	mov DS, r16
 end4:
 lsl DS
 .endmacro

 .macro read_map ;result in r0. reads values from the look_up table map_vals
		mov r16, @0 ;load index
		ldi ZH,high(2*map_vals) ; Load high part of byte address into ZH
		ldi ZL,low(2*map_vals) ; Load low part of byte address into ZL
		add ZL, r16	;add index
		ldi r16, 0
		adc ZH, r16 ;propagate carry
		lpm	;load value from address ZH:ZL in r0
.endmacro

.macro init_regs ;clear registers
	clr MS_DIFH
	clr LAST_MSH
	clr MS_DIFL
	clr LAST_MSL
.endmacro
 #endif
