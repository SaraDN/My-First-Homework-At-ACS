# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/diana/CLionProjects/Tema

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/diana/CLionProjects/Tema/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Problema4.c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Problema4.c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Problema4.c.dir/flags.make

CMakeFiles/Problema4.c.dir/Problema4.c.o: CMakeFiles/Problema4.c.dir/flags.make
CMakeFiles/Problema4.c.dir/Problema4.c.o: ../Problema4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/diana/CLionProjects/Tema/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Problema4.c.dir/Problema4.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Problema4.c.dir/Problema4.c.o   -c /mnt/c/Users/diana/CLionProjects/Tema/Problema4.c

CMakeFiles/Problema4.c.dir/Problema4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Problema4.c.dir/Problema4.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/diana/CLionProjects/Tema/Problema4.c > CMakeFiles/Problema4.c.dir/Problema4.c.i

CMakeFiles/Problema4.c.dir/Problema4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Problema4.c.dir/Problema4.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/diana/CLionProjects/Tema/Problema4.c -o CMakeFiles/Problema4.c.dir/Problema4.c.s

# Object files for target Problema4.c
Problema4_c_OBJECTS = \
"CMakeFiles/Problema4.c.dir/Problema4.c.o"

# External object files for target Problema4.c
Problema4_c_EXTERNAL_OBJECTS =

Problema4.c: CMakeFiles/Problema4.c.dir/Problema4.c.o
Problema4.c: CMakeFiles/Problema4.c.dir/build.make
Problema4.c: CMakeFiles/Problema4.c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/diana/CLionProjects/Tema/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Problema4.c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Problema4.c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Problema4.c.dir/build: Problema4.c

.PHONY : CMakeFiles/Problema4.c.dir/build

CMakeFiles/Problema4.c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Problema4.c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Problema4.c.dir/clean

CMakeFiles/Problema4.c.dir/depend:
	cd /mnt/c/Users/diana/CLionProjects/Tema/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/diana/CLionProjects/Tema /mnt/c/Users/diana/CLionProjects/Tema /mnt/c/Users/diana/CLionProjects/Tema/cmake-build-debug /mnt/c/Users/diana/CLionProjects/Tema/cmake-build-debug /mnt/c/Users/diana/CLionProjects/Tema/cmake-build-debug/CMakeFiles/Problema4.c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Problema4.c.dir/depend

