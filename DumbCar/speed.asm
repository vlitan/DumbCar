/*
 * speed.asm
 *
 *  Created: 1/15/2017 2:22:41 PM
 *   Author: virgil
 */ 

 #ifndef _SPEED_ASM_
 #define _SPEED_ASM_
 
 .include "speed.inc"

 compute_act_speed:; takes 3 arguments in stack (actEnc, lastEnc, lastTH and lastTL), outputs current speed, nowEnc, lastTH, lastTL
/*
	sub nowTL, lastTL ; 5.2.2.3)
	sbc nowTH, lastTH ;  nowTH:nowTL now stores deltaT
	mov r16, nowTL ; 5.2.2.4)
	mov r17, nowTH
	ldi r18, 0x00; 4096 low
	ldi r19, 0x10; 4096 high
	call div16u
	ldi r18, 0
	cp r18, r17
	breq end5 ;  if the actual speed > 255 the result will be 255
		ldi r16, 0xff
	end5: 
	;at this moment the result is stored in r16
	mov lastTL, MSL
	mov lastTH, MSH
	mov lastEnc, actEnc
 /*
 if nowEnc != lastEnc {
 deltaT = nowT - lastT;
 speed = constMM / deltaT
 lastT = nowT
 lastEnc = nowEnc;
 }
 */
 
 ret
 .include "division.asm"
 #endif
