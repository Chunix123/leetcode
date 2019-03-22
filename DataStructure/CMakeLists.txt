cmake_minimum_required(VERSION 3.13)

project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(BinaryTree)

aux_source_directory(. DIR_SRCS)

add_executable(DataStructure ${DIR_SRCS} BinaryTree/binaryTree.c BinaryTree/binaryTree.h)

target_link_libraries(DataStructure LibBinaryTree)