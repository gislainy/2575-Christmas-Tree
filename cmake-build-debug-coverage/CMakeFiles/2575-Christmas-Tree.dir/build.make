# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /opt/clion-2020.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gislainy/Personal/2575-Christmas-Tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gislainy/Personal/2575-Christmas-Tree/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/2575-Christmas-Tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2575-Christmas-Tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2575-Christmas-Tree.dir/flags.make

CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.o: CMakeFiles/2575-Christmas-Tree.dir/flags.make
CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gislainy/Personal/2575-Christmas-Tree/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.o -c /home/gislainy/Personal/2575-Christmas-Tree/src/main.cpp

CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gislainy/Personal/2575-Christmas-Tree/src/main.cpp > CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.i

CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gislainy/Personal/2575-Christmas-Tree/src/main.cpp -o CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.s

# Object files for target 2575-Christmas-Tree
2575__Christmas__Tree_OBJECTS = \
"CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.o"

# External object files for target 2575-Christmas-Tree
2575__Christmas__Tree_EXTERNAL_OBJECTS =

2575-Christmas-Tree: CMakeFiles/2575-Christmas-Tree.dir/src/main.cpp.o
2575-Christmas-Tree: CMakeFiles/2575-Christmas-Tree.dir/build.make
2575-Christmas-Tree: CMakeFiles/2575-Christmas-Tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gislainy/Personal/2575-Christmas-Tree/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2575-Christmas-Tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2575-Christmas-Tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2575-Christmas-Tree.dir/build: 2575-Christmas-Tree

.PHONY : CMakeFiles/2575-Christmas-Tree.dir/build

CMakeFiles/2575-Christmas-Tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2575-Christmas-Tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2575-Christmas-Tree.dir/clean

CMakeFiles/2575-Christmas-Tree.dir/depend:
	cd /home/gislainy/Personal/2575-Christmas-Tree/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gislainy/Personal/2575-Christmas-Tree /home/gislainy/Personal/2575-Christmas-Tree /home/gislainy/Personal/2575-Christmas-Tree/cmake-build-debug-coverage /home/gislainy/Personal/2575-Christmas-Tree/cmake-build-debug-coverage /home/gislainy/Personal/2575-Christmas-Tree/cmake-build-debug-coverage/CMakeFiles/2575-Christmas-Tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2575-Christmas-Tree.dir/depend

