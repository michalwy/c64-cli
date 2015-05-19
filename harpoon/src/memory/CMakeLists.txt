set(DIR memory)

set(SOURCE_FILES
	memory.cc
	main_memory.cc
	linear_memory.cc
	chunked_memory.cc
	random_access_memory.cc
	read_only_memory.cc
	)

set(INCLUDE_FILES
	address.hh
	address_range.hh
	memory.hh
	main_memory.hh
	linear_memory.hh
	chunked_memory.hh
	random_access_memory.hh
	read_only_memory.hh
	)

add_sources()

add_subdirectory(exception)
