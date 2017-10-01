cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${UNPV13E_SOURCE_DIR}/bin)

include_directories(${UNPV13E_SOURCE_DIR}/include)
link_directories(${UNPV13E_SOURCE_DIR}/lib)

aux_source_directory(. SOURCE_FILES)

set(TRG udpserver)
add_executable(${TRG} ${SOURCE_FILES})
target_link_libraries(${TRG} unp)