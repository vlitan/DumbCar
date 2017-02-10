/*
 * encoders.inc
 *
 *  Created: 12/10/2016 6:41:16 PM
 *   Author: virgil
 */

 

 #ifndef _ENCODERS_INC_
 #define _ENCODERS_INC_

 .include "analog_input.inc"
 
 #define TL 70	;low treshold
 #define TH 120 ;high treshold

 .def ENC_VALS = r24 ;stores current values of the ecoders
 .def ENC_EDGE = r23 ;stores if there was an positive/negative edge

 .macro init_encoders ;clear registers
	clr ENC_VALS
	clr ENC_EDGE
 .endmacro

  .macro read_encoder	;arg0: 1 or 2. hysteresis involed
	analog_read @0		;read current value
	/*if enc==h and val < tl enc = l, edge = 1*/
	cpi r16, TL ;
	brlo no_neg_edge@0
		sbrs ENC_VALS, @0  
			rjmp no_neg_edge@0 ;if the bit is 0 this jump will be made
		andi ENC_VALS, ~(1 << @0) ;enc = L
		ori ENC_EDGE, (1 << @0) ;edge = 1
		rjmp end_read@0
	no_neg_edge@0:
		andi ENC_EDGE, ~(1 << @0) ;edge = 0

	/*if enc==l and val > th enc = h, edge = 1*/
	cpi  DS, TH
	brlo no_pos_edge@0
		sbrc ENC_VALS, @0  
			rjmp no_pos_edge@0 ;if the bit is 1 this jump will be made*/
		ori ENC_VALS, (1 << @0) ;enc = H
		ori ENC_EDGE, (1 << @0) ;edge = 1
		rjmp end_read@0
	no_pos_edge@0:
		andi ENC_EDGE, ~(1 << @0) ;edge = 0
	end_read@0:
.endmacro

 #endif
