cmake_minimum_required(VERSION 3.13)

project(Intervier C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(Alpes)

aux_source_directory(. DIR_SRCS)

add_executable(Intervier ${DIR_SRCS})

target_link_libraries(Intervier libalpes)
