/*
 * encoders.inc
 *
 *  Created: 12/10/2016 6:41:16 PM
 *   Author: virgil
 */

 #ifndef _ENCODERS_INC_
 #define _ENCODERS_INC_
 .macro init_encoders
	cbi DDRD, PD0 ; use as input
	cbi DDRD, PD1 ; use as input
	sbi PORTD, PD0 ; set internal pull-up
	sbi PORTD, PD1 ; set internal pull-up
 .endmacro
 #endif
