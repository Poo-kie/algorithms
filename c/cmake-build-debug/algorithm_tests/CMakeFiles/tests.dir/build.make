# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pookie/Projects/algorithms/c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pookie/Projects/algorithms/c/cmake-build-debug

# Include any dependencies generated for this target.
include algorithm_tests/CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include algorithm_tests/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include algorithm_tests/CMakeFiles/tests.dir/flags.make

algorithm_tests/CMakeFiles/tests.dir/algorithm_tests.c.o: algorithm_tests/CMakeFiles/tests.dir/flags.make
algorithm_tests/CMakeFiles/tests.dir/algorithm_tests.c.o: ../algorithm_tests/algorithm_tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pookie/Projects/algorithms/c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object algorithm_tests/CMakeFiles/tests.dir/algorithm_tests.c.o"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tests.dir/algorithm_tests.c.o   -c /Users/pookie/Projects/algorithms/c/algorithm_tests/algorithm_tests.c

algorithm_tests/CMakeFiles/tests.dir/algorithm_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tests.dir/algorithm_tests.c.i"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/pookie/Projects/algorithms/c/algorithm_tests/algorithm_tests.c > CMakeFiles/tests.dir/algorithm_tests.c.i

algorithm_tests/CMakeFiles/tests.dir/algorithm_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tests.dir/algorithm_tests.c.s"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/pookie/Projects/algorithms/c/algorithm_tests/algorithm_tests.c -o CMakeFiles/tests.dir/algorithm_tests.c.s

algorithm_tests/CMakeFiles/tests.dir/munit/munit.c.o: algorithm_tests/CMakeFiles/tests.dir/flags.make
algorithm_tests/CMakeFiles/tests.dir/munit/munit.c.o: ../algorithm_tests/munit/munit.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pookie/Projects/algorithms/c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object algorithm_tests/CMakeFiles/tests.dir/munit/munit.c.o"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tests.dir/munit/munit.c.o   -c /Users/pookie/Projects/algorithms/c/algorithm_tests/munit/munit.c

algorithm_tests/CMakeFiles/tests.dir/munit/munit.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tests.dir/munit/munit.c.i"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/pookie/Projects/algorithms/c/algorithm_tests/munit/munit.c > CMakeFiles/tests.dir/munit/munit.c.i

algorithm_tests/CMakeFiles/tests.dir/munit/munit.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tests.dir/munit/munit.c.s"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/pookie/Projects/algorithms/c/algorithm_tests/munit/munit.c -o CMakeFiles/tests.dir/munit/munit.c.s

algorithm_tests/CMakeFiles/tests.dir/data_structures_tests.c.o: algorithm_tests/CMakeFiles/tests.dir/flags.make
algorithm_tests/CMakeFiles/tests.dir/data_structures_tests.c.o: ../algorithm_tests/data_structures_tests.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pookie/Projects/algorithms/c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object algorithm_tests/CMakeFiles/tests.dir/data_structures_tests.c.o"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tests.dir/data_structures_tests.c.o   -c /Users/pookie/Projects/algorithms/c/algorithm_tests/data_structures_tests.c

algorithm_tests/CMakeFiles/tests.dir/data_structures_tests.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tests.dir/data_structures_tests.c.i"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/pookie/Projects/algorithms/c/algorithm_tests/data_structures_tests.c > CMakeFiles/tests.dir/data_structures_tests.c.i

algorithm_tests/CMakeFiles/tests.dir/data_structures_tests.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tests.dir/data_structures_tests.c.s"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/pookie/Projects/algorithms/c/algorithm_tests/data_structures_tests.c -o CMakeFiles/tests.dir/data_structures_tests.c.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/algorithm_tests.c.o" \
"CMakeFiles/tests.dir/munit/munit.c.o" \
"CMakeFiles/tests.dir/data_structures_tests.c.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

algorithm_tests/tests: algorithm_tests/CMakeFiles/tests.dir/algorithm_tests.c.o
algorithm_tests/tests: algorithm_tests/CMakeFiles/tests.dir/munit/munit.c.o
algorithm_tests/tests: algorithm_tests/CMakeFiles/tests.dir/data_structures_tests.c.o
algorithm_tests/tests: algorithm_tests/CMakeFiles/tests.dir/build.make
algorithm_tests/tests: lib/libpkealgorithms.dylib
algorithm_tests/tests: algorithm_tests/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pookie/Projects/algorithms/c/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable tests"
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
algorithm_tests/CMakeFiles/tests.dir/build: algorithm_tests/tests

.PHONY : algorithm_tests/CMakeFiles/tests.dir/build

algorithm_tests/CMakeFiles/tests.dir/clean:
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : algorithm_tests/CMakeFiles/tests.dir/clean

algorithm_tests/CMakeFiles/tests.dir/depend:
	cd /Users/pookie/Projects/algorithms/c/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pookie/Projects/algorithms/c /Users/pookie/Projects/algorithms/c/algorithm_tests /Users/pookie/Projects/algorithms/c/cmake-build-debug /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests /Users/pookie/Projects/algorithms/c/cmake-build-debug/algorithm_tests/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : algorithm_tests/CMakeFiles/tests.dir/depend

