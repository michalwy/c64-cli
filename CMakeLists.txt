cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

include(functions)

project(harpoon)

set(CMAKE_CLANG_CXX_FLAGS
	-std=c++11
	-Werror
	-Weverything
	-Wno-c++98-compat
	-Wno-c++98-compat-pedantic
	-Wno-padded
	)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	string(REGEX REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CLANG_CXX_FLAGS}")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(harpoon)
add_subdirectory(examples)

