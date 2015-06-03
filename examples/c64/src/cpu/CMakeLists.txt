set(DIR cpu)

set(SOURCE_FILES
	mos_6502.cc
	mos_6502_decoder.cc
	)

set(INCLUDE_FILES
	mos_6502.hh
	mos_6502_decoder.hh
	)

add_sources()

add_subdirectory(instructions)
