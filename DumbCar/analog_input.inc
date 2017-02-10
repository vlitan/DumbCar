/*
 * analog_input.inc
 *
 *  Created: 12/11/2016 6:14:26 PM
 *   Author: virgil
 */ 
 #ifndef _ANALOG_INPUT_INC_
 #define _ANALOG_INPUT_INC_

 .include "utils.inc"

 .def DS = r25 // desired speed

 .macro init_adc ;setup the adc
	cb_to_reg_h ADMUX, (1 << REFS0) | (1 << ADLAR); select vref == avcc
	cb_to_reg_h ADCSRA,  (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN) ;set prescaler to 128 and enable adc
.endmacro

.macro analog_read ;8bit result saved in DS
 
	init_adc ; almost sure this is redundant
	;set input channel via multiplexer
	.if @0 == 0
		clear_bit_h ADMUX, 0
		clear_bit_h ADMUX, 1
	.elif @0 == 1
		set_bit_h ADMUX, 0
		clear_bit_h ADMUX, 1
	.elif @0 == 2
		clear_bit_h ADMUX, 0
		set_bit_h ADMUX, 1
	.endif
	;start conversion
	set_bit_h ADCSRA, ADSC
	;wait conversion to end
	wait_adc:  
		lds r16, ADCSRA
		andi r16, (1 << ADSC)
		cpi r16, 0
		brne wait_adc
	;save result
	lds DS, ADCH
.endmacro


 #endif
