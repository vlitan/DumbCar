/*
 * analog_input.inc
 *
 *  Created: 12/11/2016 6:14:26 PM
 *   Author: virgil
 */ 
 #ifndef _ANLOG_INPUT_INC_
 #define _ANALOG_INPUT_INC_

 .include "utils.inc"

 .def DS = r25 // desired speed

 .macro init_adc
	cb_to_reg_h ADMUX, (1 << REFS0) | (1 << ADLAR); select vref == avcc
	cb_to_reg_h ADCSRA,  (1<<ADPS2) | (1<<ADPS0) | (1<<ADEN) ;set prescaler to 128 and enable adc

.endmacro

.macro analog_read ;8bit result
	;set input multiplexer
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
	;init conversion
	set_bit_h ADCSRA, ADSC
	;store 8bit result, ignore 2 lsb
	lds DS, ADCH
.endmacro


 #endif
