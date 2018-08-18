cmake_minimum_required(VERSION 2.8)

# Project Name and start working in project scope (some things just work until now, some just work after this command)
project(modular)

# Add conan dependencies (our c++ dependency manager)
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)


# Error if paths aren't set well
get_filename_component(MAINDIR "${CMAKE_SOURCE_DIR}" REALPATH)  # Main inexor folder
get_filename_component(BINDIR "${CMAKE_BINARY_DIR}" REALPATH)   # Where it generates the projects into
if(${MAINDIR} STREQUAL ${BINDIR})
    message(FATAL_ERROR "Keep your directories clean, don't generate the project-files in the main directory! ${MAINDIR} ${BINDIR}")
endif()

set(sources "tutorial_1.c")
add_executable(modular ${sources} ${ALL_HEADERS})

