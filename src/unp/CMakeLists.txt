cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${UNPV13E_SOURCE_DIR}/include)

#set(SOURCE_FILES '*.c')
aux_source_directory(. SOURCE_FILES)

set(TRG unp)
add_library(${TRG} SHARED ${SOURCE_FILES})