set(DIR instructions)

set(SOURCE_FILES
	)

set(INCLUDE_FILES
	mos_6510_instruction.hh
	mos_6510.hh
	and.hh
	bcc.hh
	bcs.hh
	beq.hh
	bne.hh
	bpl.hh
	clc.hh
	cld.hh
	cmp.hh
	dex.hh
	dey.hh
	inc.hh
	inx.hh
	iny.hh
	jmp.hh
	jsr.hh
	lda.hh
	ldx.hh
	ldy.hh
	nop.hh
	ora.hh
	rol.hh
	ror.hh
	rts.hh
	sei.hh
	sta.hh
	stx.hh
	sty.hh
	tax.hh
	tay.hh
	txa.hh
	txs.hh
	tya.hh
	)

add_sources()
