set(CMAKE_CXX_COMPILER_WORKS 1)
cmake_minimum_required(VERSION 2.8.12)
project(spdlogger CXX)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS NO_OUTPUT_DIRS)

set(CMAKE_CXX_STANDARD 14)
include_directories("../..")

add_library(spdlogger 
  "spd_logger.cpp")

target_link_libraries(spdlogger ${CONAN_LIBS})

