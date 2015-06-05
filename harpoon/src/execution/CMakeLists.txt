set(DIR execution)

set(SOURCE_FILES
	processing_unit.cc
	execution_unit.cc
	up_execution_unit.cc
	basic_register.cc
	)

set(INCLUDE_FILES
	cycle.hh
	instruction.hh
	instruction_decoder.hh
	instruction_invoker.hh
	processing_unit.hh
	execution_unit.hh
	up_execution_unit.hh
	basic_register.hh
	)

add_sources()

add_subdirectory(exception)
