cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME "modular")

# Project Name and start working in project scope (some things just work until now, some just work after this command)
project(${PROJECT_NAME})

# Add conan dependencies (our c++ dependency manager)
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
else()
    message(FATAL_ERROR "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()


# Error if paths aren't set well
get_filename_component(MAINDIR "${CMAKE_SOURCE_DIR}" REALPATH)  # Main inexor folder
get_filename_component(BINDIR "${CMAKE_BINARY_DIR}" REALPATH)   # Where it generates the projects into
if(${MAINDIR} STREQUAL ${BINDIR})
    message(FATAL_ERROR "Keep your directories clean, don't generate the project-files in the main directory! ${MAINDIR} ${BINDIR}")
endif()

# Set the build definitions
set(CMAKE_CXX_STANDARD 14)

# Dep management
include_directories("googlefruit/include" "app" "logger" "logger/nulllogger" "logger/spdlogger" "sound" "sound/openal")


set(sources "main.cpp" "app/app.cpp" "sound/openal/openal_sound.cpp" "logger/nulllogger/null_logger.cpp" "logger/spdlogger/spd_logger.cpp")
add_executable(${PROJECT_NAME} ${sources} ${ALL_HEADERS})

# Dep management
target_link_libraries(${PROJECT_NAME} CONAN_PKG::fruit CONAN_PKG::spdlog)
