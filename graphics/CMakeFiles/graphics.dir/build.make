# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aurora/projects/cpp/graphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aurora/projects/cpp/graphics

# Include any dependencies generated for this target.
include CMakeFiles/graphics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graphics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphics.dir/flags.make

CMakeFiles/graphics.dir/src/main.cxx.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/main.cxx.o: src/main.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aurora/projects/cpp/graphics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphics.dir/src/main.cxx.o"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/main.cxx.o -c /home/aurora/projects/cpp/graphics/src/main.cxx

CMakeFiles/graphics.dir/src/main.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/main.cxx.i"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aurora/projects/cpp/graphics/src/main.cxx > CMakeFiles/graphics.dir/src/main.cxx.i

CMakeFiles/graphics.dir/src/main.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/main.cxx.s"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aurora/projects/cpp/graphics/src/main.cxx -o CMakeFiles/graphics.dir/src/main.cxx.s

CMakeFiles/graphics.dir/src/Lines.cxx.o: CMakeFiles/graphics.dir/flags.make
CMakeFiles/graphics.dir/src/Lines.cxx.o: src/Lines.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aurora/projects/cpp/graphics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphics.dir/src/Lines.cxx.o"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphics.dir/src/Lines.cxx.o -c /home/aurora/projects/cpp/graphics/src/Lines.cxx

CMakeFiles/graphics.dir/src/Lines.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphics.dir/src/Lines.cxx.i"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aurora/projects/cpp/graphics/src/Lines.cxx > CMakeFiles/graphics.dir/src/Lines.cxx.i

CMakeFiles/graphics.dir/src/Lines.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphics.dir/src/Lines.cxx.s"
	/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aurora/projects/cpp/graphics/src/Lines.cxx -o CMakeFiles/graphics.dir/src/Lines.cxx.s

# Object files for target graphics
graphics_OBJECTS = \
"CMakeFiles/graphics.dir/src/main.cxx.o" \
"CMakeFiles/graphics.dir/src/Lines.cxx.o"

# External object files for target graphics
graphics_EXTERNAL_OBJECTS =

graphics: CMakeFiles/graphics.dir/src/main.cxx.o
graphics: CMakeFiles/graphics.dir/src/Lines.cxx.o
graphics: CMakeFiles/graphics.dir/build.make
graphics: CMakeFiles/graphics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aurora/projects/cpp/graphics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable graphics"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphics.dir/build: graphics

.PHONY : CMakeFiles/graphics.dir/build

CMakeFiles/graphics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphics.dir/clean

CMakeFiles/graphics.dir/depend:
	cd /home/aurora/projects/cpp/graphics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aurora/projects/cpp/graphics /home/aurora/projects/cpp/graphics /home/aurora/projects/cpp/graphics /home/aurora/projects/cpp/graphics /home/aurora/projects/cpp/graphics/CMakeFiles/graphics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graphics.dir/depend

