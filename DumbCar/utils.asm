/*
 * utils.asm
 *
 *  Created: 12/5/2016 11:27:24 AM
 *   Author: virgil
 */ 

 #ifndef _UTILS_ASM_
 #define _UTILS_ASM_

delay_half_sec: ;(clock at 16MHz)
    ldi  r18, 3;41
    ldi  r19, 3;150
    ldi  r20, 5;128
L1: dec  r20
    brne L1
    dec  r19
    brne L1
    dec  r18
    brne L1
ret

 #endif

