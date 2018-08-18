cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME "modular")

# Project Name and start working in project scope (some things just work until now, some just work after this command)
project(${PROJECT_NAME})

# Add conan dependencies (our c++ dependency manager)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(CMAKE_CXX_STANDARD 14)

# Error if paths aren't set well
get_filename_component(MAINDIR "${CMAKE_SOURCE_DIR}" REALPATH)  # Main inexor folder
get_filename_component(BINDIR "${CMAKE_BINARY_DIR}" REALPATH)   # Where it generates the projects into
if(${MAINDIR} STREQUAL ${BINDIR})
    message(FATAL_ERROR "Keep your directories clean, don't generate the project-files in the main directory! ${MAINDIR} ${BINDIR}")
endif()

include_directories("googlefruit/include")
set(sources "main.cpp" "module1/module1.cpp" "module2/module2.cpp")
add_executable(${PROJECT_NAME} ${sources} ${ALL_HEADERS})

target_link_libraries(${PROJECT_NAME} CONAN_PKG::fruit)

