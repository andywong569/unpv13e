cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${UNPV13E_SOURCE_DIR}/include)

set(SRC_LIST .)

set(TRG unp)
add_library(${TRG} SHARED ${SRC_LIST})