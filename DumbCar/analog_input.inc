/*
 * analog_input.inc
 *
 *  Created: 12/11/2016 6:14:26 PM
 *   Author: virgil
 */ 
 #ifndef _ANLOG_INPUT_INC_
 #define _ANALOG_INPUT_INC_

 .def DS = r25

 .macro init_adc
	cb_to_reg_h ADMUX, (1 << REFS0) | (1 << ADLAR); select vref == avcc
	cb_to_reg_h ADCSRA,  (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) | (1<<ADEN) ;set prescaler to 128 and enable adc

.endmacro

.macro analog_read //uses r17, not sure if its ok, so i push/pop it
	push r17 
	;init conversion
	lds r16, ADCSRA
	ori r16, (1 << ADSC)
	sts ADCSRA, r16
	;wait for conversion to end
	ldi r17, 0
	lp:
		lds r16, ADCSRA
		andi r16, (1 << ADSC)
		cp r16, r17
		breq end3
		rjmp lp
	end3:
	;store result
	lds DS, ADCH
	pop r17
.endmacro
 #endif
