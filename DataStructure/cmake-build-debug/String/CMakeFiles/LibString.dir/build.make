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
CMAKE_SOURCE_DIR = /home/zyc/Documents/leetcode/DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug

# Include any dependencies generated for this target.
include String/CMakeFiles/LibString.dir/depend.make

# Include the progress variables for this target.
include String/CMakeFiles/LibString.dir/progress.make

# Include the compile flags for this target's objects.
include String/CMakeFiles/LibString.dir/flags.make

String/CMakeFiles/LibString.dir/string.c.o: String/CMakeFiles/LibString.dir/flags.make
String/CMakeFiles/LibString.dir/string.c.o: ../String/string.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object String/CMakeFiles/LibString.dir/string.c.o"
	cd /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/String && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LibString.dir/string.c.o   -c /home/zyc/Documents/leetcode/DataStructure/String/string.c

String/CMakeFiles/LibString.dir/string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LibString.dir/string.c.i"
	cd /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/String && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zyc/Documents/leetcode/DataStructure/String/string.c > CMakeFiles/LibString.dir/string.c.i

String/CMakeFiles/LibString.dir/string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LibString.dir/string.c.s"
	cd /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/String && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zyc/Documents/leetcode/DataStructure/String/string.c -o CMakeFiles/LibString.dir/string.c.s

# Object files for target LibString
LibString_OBJECTS = \
"CMakeFiles/LibString.dir/string.c.o"

# External object files for target LibString
LibString_EXTERNAL_OBJECTS =

String/libLibString.a: String/CMakeFiles/LibString.dir/string.c.o
String/libLibString.a: String/CMakeFiles/LibString.dir/build.make
String/libLibString.a: String/CMakeFiles/LibString.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libLibString.a"
	cd /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/String && $(CMAKE_COMMAND) -P CMakeFiles/LibString.dir/cmake_clean_target.cmake
	cd /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/String && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LibString.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
String/CMakeFiles/LibString.dir/build: String/libLibString.a

.PHONY : String/CMakeFiles/LibString.dir/build

String/CMakeFiles/LibString.dir/clean:
	cd /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/String && $(CMAKE_COMMAND) -P CMakeFiles/LibString.dir/cmake_clean.cmake
.PHONY : String/CMakeFiles/LibString.dir/clean

String/CMakeFiles/LibString.dir/depend:
	cd /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyc/Documents/leetcode/DataStructure /home/zyc/Documents/leetcode/DataStructure/String /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/String /home/zyc/Documents/leetcode/DataStructure/cmake-build-debug/String/CMakeFiles/LibString.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : String/CMakeFiles/LibString.dir/depend

