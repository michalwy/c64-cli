set(DIR instructions)

set(SOURCE_FILES
	)

set(INCLUDE_FILES
	mos_6510_instruction.hh
	mos_6510.hh
	and.hh
	beq.hh
	bne.hh
	cld.hh
	cmp.hh
	dex.hh
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
	)

add_sources()
