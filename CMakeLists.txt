cmake_minimum_required(VERSION 2.6)

include(cmake/functions.cmake)

project(harpoon)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(harpoon)
add_subdirectory(examples)

