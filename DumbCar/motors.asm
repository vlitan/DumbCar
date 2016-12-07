/*
 * motors.asm
 *
 *  Created: 12/6/2016 9:40:59 PM
 *   Author: virgil
 */ 
 #ifndef _MOTORS_ASM_
 #define _MOTORS_ASM_

 go_left:
	ldi r16, 0
	cp SL, r16
	breq else ;if SL != 1 (forward)
			disable_channel_2B
			enable_channel_2A
			set_match_2A VL
	rjmp end
	else: ; else if SL == 1 (backwards)
		disable_channel_2A
		enable_channel_2B
		set_match_2B VL
	end:
ret

 go_right:
	ldi r16, 0
	cp SR, r16
	breq els ;if SR != 1 (forward)
			disable_channel_0B
			enable_channel_0A
			set_match_0A VR
	rjmp en
	els: ; else if SR == 1 (backwards)
		disable_channel_0A
		enable_channel_0B
		set_match_0B VR
	en:
ret

 #endif
