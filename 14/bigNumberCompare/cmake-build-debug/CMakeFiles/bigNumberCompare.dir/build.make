# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\SILLBOX\C++__Homework\14\bigNumberCompare

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\SILLBOX\C++__Homework\14\bigNumberCompare\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bigNumberCompare.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bigNumberCompare.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bigNumberCompare.dir/flags.make

CMakeFiles/bigNumberCompare.dir/main.cpp.obj: CMakeFiles/bigNumberCompare.dir/flags.make
CMakeFiles/bigNumberCompare.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\SILLBOX\C++__Homework\14\bigNumberCompare\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bigNumberCompare.dir/main.cpp.obj"
	D:\min-gw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\bigNumberCompare.dir\main.cpp.obj -c D:\SILLBOX\C++__Homework\14\bigNumberCompare\main.cpp

CMakeFiles/bigNumberCompare.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bigNumberCompare.dir/main.cpp.i"
	D:\min-gw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\SILLBOX\C++__Homework\14\bigNumberCompare\main.cpp > CMakeFiles\bigNumberCompare.dir\main.cpp.i

CMakeFiles/bigNumberCompare.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bigNumberCompare.dir/main.cpp.s"
	D:\min-gw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\SILLBOX\C++__Homework\14\bigNumberCompare\main.cpp -o CMakeFiles\bigNumberCompare.dir\main.cpp.s

# Object files for target bigNumberCompare
bigNumberCompare_OBJECTS = \
"CMakeFiles/bigNumberCompare.dir/main.cpp.obj"

# External object files for target bigNumberCompare
bigNumberCompare_EXTERNAL_OBJECTS =

bigNumberCompare.exe: CMakeFiles/bigNumberCompare.dir/main.cpp.obj
bigNumberCompare.exe: CMakeFiles/bigNumberCompare.dir/build.make
bigNumberCompare.exe: CMakeFiles/bigNumberCompare.dir/linklibs.rsp
bigNumberCompare.exe: CMakeFiles/bigNumberCompare.dir/objects1.rsp
bigNumberCompare.exe: CMakeFiles/bigNumberCompare.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\SILLBOX\C++__Homework\14\bigNumberCompare\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bigNumberCompare.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bigNumberCompare.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bigNumberCompare.dir/build: bigNumberCompare.exe

.PHONY : CMakeFiles/bigNumberCompare.dir/build

CMakeFiles/bigNumberCompare.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bigNumberCompare.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bigNumberCompare.dir/clean

CMakeFiles/bigNumberCompare.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\SILLBOX\C++__Homework\14\bigNumberCompare D:\SILLBOX\C++__Homework\14\bigNumberCompare D:\SILLBOX\C++__Homework\14\bigNumberCompare\cmake-build-debug D:\SILLBOX\C++__Homework\14\bigNumberCompare\cmake-build-debug D:\SILLBOX\C++__Homework\14\bigNumberCompare\cmake-build-debug\CMakeFiles\bigNumberCompare.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bigNumberCompare.dir/depend
