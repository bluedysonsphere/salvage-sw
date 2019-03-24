;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.9.0 #5416 (Apr  7 2010) (MINGW32)
; This file was generated Sun Apr 11 14:38:20 2010
;--------------------------------------------------------
	.module abs
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _abs
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
;  ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; overlayable items in  ram 
;--------------------------------------------------------
	.area _OVERLAY
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;../abs.c:23: int abs(int j)
;	---------------------------------
; Function abs
; ---------------------------------
_abs:
	push	ix
	ld	ix,#0
	add	ix,sp
;../abs.c:25: return (j >= 0) ? j : -j;
	ld	a,5 (ix)
	rlca
	and	a,#0x01
	sub	a,#0x01
	ld	a,#0x00
	rla
	or	a,a
	jr	Z,00103$
	ld	c,4 (ix)
	ld	b,5 (ix)
	jr	00104$
00103$:
	xor	a,a
	sbc	a,4 (ix)
	ld	c,a
	ld	a,#0x00
	sbc	a,5 (ix)
	ld	b,a
00104$:
	ld	l,c
	ld	h,b
	pop	ix
ret
	.area _CODE
	.area _CABS
