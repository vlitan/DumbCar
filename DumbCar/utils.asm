/*
 * utils.asm
 *
 *  Created: 12/5/2016 11:27:24 AM
 *   Author: virgil
 */ 

 #ifndef _UTILS_ASM_
 #define _UTILS_ASM_

delay_ms: ;should be 1ms (clock @ 16MHz)
	ldi  r19, 1
    ldi  r18, 12
    ldi  r20, 128
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
ret

 #endif

