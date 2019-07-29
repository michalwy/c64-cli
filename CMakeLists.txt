cmake_minimum_required(VERSION 3.9)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(C64-cli_MAJOR_VERSION 0)
set(C64-cli_MINOR_VERSION 1)
set(C64-cli_PATCH_VERSION 0)
set(C64-cli_VERSION
  ${C64-cli_MAJOR_VERSION}.${C64-cli_MINOR_VERSION}.${C64-cli_PATCH_VERSION})

project(C64-cli LANGUAGES CXX C VERSION ${C64-cli_VERSION})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Boost COMPONENTS program_options regex REQUIRED)
find_package(Harpoon_C64-hw REQUIRED)

add_executable(c64-cli
	src/main.cc
	src/console_log.cc
	src/console_log.hh
	src/load_argument.hh
	src/integer.hh
	src/counted_breakpoint_argument.hh
)

target_compile_features(c64-cli
	PRIVATE
		cxx_lambdas
		cxx_range_for
)

target_link_libraries(c64-cli
	Threads::Threads
	Boost::program_options
	Boost::regex
	Harpoon::c64-hw
)

install(TARGETS c64-cli
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
