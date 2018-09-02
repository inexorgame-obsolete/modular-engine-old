cmake_minimum_required (VERSION 3.0)
project (lmdb C CXX)

set (SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lmdb/libraries/liblmdb")

set (SOURCE_FILES
    ${SOURCE_PATH}/mdb.c
    ${SOURCE_PATH}/lmdb.h
    ${SOURCE_PATH}/midl.h
    ${SOURCE_PATH}/midl.c
    ${CMAKE_CURRENT_SOURCE_DIR}/mdb.def
    )

set (CMAKE_DEBUG_POSTFIX "d")
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

set (CMAKE_LINK_DEF_FILE_FLAG "/DEF:\"${CMAKE_CURRENT_SOURCE_DIR}/mdb.def\"")
add_library (lmdb ${SOURCE_FILES})

#add_executable (mdb_copy ${SOURCE_PATH}/mdb_copy.c)
#add_executable (mdb_stat ${SOURCE_PATH}/mdb_stat.c)
#add_executable (mdb_dump ${SOURCE_PATH}/mdb_dump.c)
#add_executable (mdb_load ${SOURCE_PATH}/mdb_load.c)

#target_link_libraries (mdb_copy lmdb)
#target_link_libraries (mdb_stat lmdb)
#target_link_libraries (mdb_dump lmdb)
#target_link_libraries (mdb_load lmdb)

if (WIN32)
    if (MSVC)
        include_directories (${CMAKE_CURRENT_SOURCE_DIR}/win32/stubs ${CMAKE_CURRENT_SOURCE_DIR}/win32/real)
    endif ()

    target_link_libraries (lmdb ntdll)
    #target_link_libraries (mdb_copy ntdll)
    #target_link_libraries (mdb_stat ntdll)
    #target_link_libraries (mdb_dump ntdll)
    #target_link_libraries (mdb_load ntdll)
endif ()
