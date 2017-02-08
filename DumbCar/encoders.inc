/*
 * encoders.inc
 *
 *  Created: 12/10/2016 6:41:16 PM
 *   Author: virgil
 */

 

 #ifndef _ENCODERS_INC_
 #define _ENCODERS_INC_

 #define TL 70
 #define TH 120

 .def ENC_VALS = r24
 .def ENC_EDGE = r23

 .macro init_encoders
	/*cbi DDRD, PD0 ; use as input
	cbi DDRD, PD1 ; use as input
	sbi PORTD, PD0 ; set internal pull-up
	sbi PORTD, PD1 ; set internal pull-up*/
	clr ENC_VALS
	clr ENC_EDGE
	/*analog_read 1
	ldi r16, TH
	cp r16, DS
	brlo g1
		ori ENC_VALS, 1;enc = H
	g1:
	analog_read 2
	ldi r16, TH
	cp r16, DS
	brlo g2
		ori ENC_VALS, 2 ;enc = H
	g2:*/
 .endmacro

  .macro read_encoder /*1 or 2*/;hysteresis
	analog_read @0
	/*if enc==h and val < tl enc = l, edge = 1*/
	ldi r16, TL
	cp r16, DS
	brlo no_neg_edge@0
		sbrs ENC_VALS, @0  
			rjmp no_neg_edge@0 ;if the bit is 0 this jump will be made
		;enc == H and val < TL
		andi ENC_VALS, ~(1 << @0) ;enc = L
		ori ENC_EDGE, (1 << @0) ;edge = 1
		rjmp end_read@0
	no_neg_edge@0:
		andi ENC_EDGE, ~(1 << @0) ;edge = 0

	/*if enc==l and val > th enc = h, edge = 1*/
	ldi r16, TH
	cp  DS, r16
	brlo no_pos_edge@0;val > th
		sbrc ENC_VALS, @0  
			rjmp no_pos_edge@0 ;if the bit is 1 this jump will be made*/
		;enc == L and val > TH
		ori ENC_VALS, (1 << @0) ;enc = H
		ori ENC_EDGE, (1 << @0) ;edge = 1
		rjmp end_read@0
	no_pos_edge@0:
		andi ENC_EDGE, ~(1 << @0) ;edge = 0

	end_read@0:
.endmacro

 #endif
