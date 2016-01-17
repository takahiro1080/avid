
#*************************************************************************************************
#
#	avid/CMakeLists.txt
#
#*************************************************************************************************


# version required
cmake_minimum_required(VERSION 3.4.1)


# project
set(project_name avid)
project(${project_name} CXX)
message("add project --- " ${project_name})


# include directories
include_directories(src/)


# option
option(AVID_OPTION_ENABLE_UNIT_TESTS "enable unit tests." OFF)
option(AVID_OPTION_ENABLE_FRAMEWORK_TESTS "enable framework tests." OFF)
option(AVID_OPTION_BUILD_SHARED_LIBS "build shared libraries." OFF)
#option(AVID_OPTION_BUILD_MSVC_WITH_CLANG "build MSVC with Clang." OFF)


# property setting
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# compiler and linker settings
include(cmake/internal_utils.cmake)
config_compiler_and_linker()


# add sub directories
add_subdirectory(src/)
add_subdirectory(third_party/)


# enable unit test
if(AVID_OPTION_ENABLE_UNIT_TESTS)
	enable_testing()
	message("enable unit test.")
endif()


# add testing targets
if(AVID_OPTION_ENABLE_UNIT_TESTS OR AVID_OPTION_ENABLE_FRAMEWORK_TESTS)
	message("add testing targets.")
	add_subdirectory(test/)
endif()


