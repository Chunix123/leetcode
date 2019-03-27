cmake_minimum_required(VERSION 3.13)

project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(BinaryTree)
add_subdirectory(String)
add_subdirectory(Utils)

aux_source_directory(. DIR_SRCS)

add_executable(DataStructure ${DIR_SRCS})

target_link_libraries(DataStructure LibBinaryTree)
target_link_libraries(DataStructure LibString)
target_link_libraries(DataStructure LibUtils)
