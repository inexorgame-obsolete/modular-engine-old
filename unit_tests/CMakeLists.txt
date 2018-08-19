set(TEST_BINARY unit_tests CACHE INTERNAL "")
set(sources "main.cpp")

# This needs to come before the target, sigh
link_directories(${GTEST_LIB_DIR})

add_executable(${TEST_BINARY} ${sources} ${ALL_HEADERS})
target_link_libraries(${TEST_BINARY} CONAN_PKG::gtest)
