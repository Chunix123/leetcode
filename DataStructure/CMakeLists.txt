cmake_minimum_required(VERSION 3.13)

project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(LinkList)
add_subdirectory(BinaryTree)
add_subdirectory(Sort)
add_subdirectory(String)
add_subdirectory(Utils)

aux_source_directory(. DIR_SRCS)

add_executable(DataStructure ${DIR_SRCS})

target_link_libraries(DataStructure liblinklist)
target_link_libraries(DataStructure libbinarytree)
target_link_libraries(DataStructure libsort)
target_link_libraries(DataStructure libstring)
target_link_libraries(DataStructure libutils)
