set(DIR cpu)

set(SOURCE_FILES
	mos_6510.cc
	mos_6510_decoder.cc
	)

set(INCLUDE_FILES
	mos_6510.hh
	mos_6510_decoder.hh
	)

add_sources()

add_subdirectory(instructions)
