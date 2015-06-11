set(DIR src)
set(BASE_INCLUDE_DIR src)

set(SOURCE_FILES
	c64.cc
	main.cc
	)

set(INCLUDE_FILES
	c64.hh
	)

add_sources()

add_subdirectory(cpu)
add_subdirectory(memory)
add_subdirectory(ui)
