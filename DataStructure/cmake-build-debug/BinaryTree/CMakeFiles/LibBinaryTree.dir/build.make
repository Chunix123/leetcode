# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/zyc/Downloads/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zyc/Downloads/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zyc/Documents/Project/leetcode/DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug

# Include any dependencies generated for this target.
include BinaryTree/CMakeFiles/LibBinaryTree.dir/depend.make

# Include the progress variables for this target.
include BinaryTree/CMakeFiles/LibBinaryTree.dir/progress.make

# Include the compile flags for this target's objects.
include BinaryTree/CMakeFiles/LibBinaryTree.dir/flags.make

BinaryTree/CMakeFiles/LibBinaryTree.dir/binaryTree.c.o: BinaryTree/CMakeFiles/LibBinaryTree.dir/flags.make
BinaryTree/CMakeFiles/LibBinaryTree.dir/binaryTree.c.o: ../BinaryTree/binaryTree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object BinaryTree/CMakeFiles/LibBinaryTree.dir/binaryTree.c.o"
	cd /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/BinaryTree && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LibBinaryTree.dir/binaryTree.c.o   -c /home/zyc/Documents/Project/leetcode/DataStructure/BinaryTree/binaryTree.c

BinaryTree/CMakeFiles/LibBinaryTree.dir/binaryTree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LibBinaryTree.dir/binaryTree.c.i"
	cd /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/BinaryTree && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zyc/Documents/Project/leetcode/DataStructure/BinaryTree/binaryTree.c > CMakeFiles/LibBinaryTree.dir/binaryTree.c.i

BinaryTree/CMakeFiles/LibBinaryTree.dir/binaryTree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LibBinaryTree.dir/binaryTree.c.s"
	cd /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/BinaryTree && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zyc/Documents/Project/leetcode/DataStructure/BinaryTree/binaryTree.c -o CMakeFiles/LibBinaryTree.dir/binaryTree.c.s

# Object files for target LibBinaryTree
LibBinaryTree_OBJECTS = \
"CMakeFiles/LibBinaryTree.dir/binaryTree.c.o"

# External object files for target LibBinaryTree
LibBinaryTree_EXTERNAL_OBJECTS =

BinaryTree/libLibBinaryTree.a: BinaryTree/CMakeFiles/LibBinaryTree.dir/binaryTree.c.o
BinaryTree/libLibBinaryTree.a: BinaryTree/CMakeFiles/LibBinaryTree.dir/build.make
BinaryTree/libLibBinaryTree.a: BinaryTree/CMakeFiles/LibBinaryTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libLibBinaryTree.a"
	cd /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/BinaryTree && $(CMAKE_COMMAND) -P CMakeFiles/LibBinaryTree.dir/cmake_clean_target.cmake
	cd /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/BinaryTree && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LibBinaryTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
BinaryTree/CMakeFiles/LibBinaryTree.dir/build: BinaryTree/libLibBinaryTree.a

.PHONY : BinaryTree/CMakeFiles/LibBinaryTree.dir/build

BinaryTree/CMakeFiles/LibBinaryTree.dir/clean:
	cd /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/BinaryTree && $(CMAKE_COMMAND) -P CMakeFiles/LibBinaryTree.dir/cmake_clean.cmake
.PHONY : BinaryTree/CMakeFiles/LibBinaryTree.dir/clean

BinaryTree/CMakeFiles/LibBinaryTree.dir/depend:
	cd /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyc/Documents/Project/leetcode/DataStructure /home/zyc/Documents/Project/leetcode/DataStructure/BinaryTree /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/BinaryTree /home/zyc/Documents/Project/leetcode/DataStructure/cmake-build-debug/BinaryTree/CMakeFiles/LibBinaryTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : BinaryTree/CMakeFiles/LibBinaryTree.dir/depend
