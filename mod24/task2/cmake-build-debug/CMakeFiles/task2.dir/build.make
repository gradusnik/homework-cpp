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
CMAKE_SOURCE_DIR = D:\SKILLBOX\C++__Homework\mod24\task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\SKILLBOX\C++__Homework\mod24\task2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task2.dir/flags.make

CMakeFiles/task2.dir/main.cpp.obj: CMakeFiles/task2.dir/flags.make
CMakeFiles/task2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\SKILLBOX\C++__Homework\mod24\task2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task2.dir/main.cpp.obj"
	D:\min-gw\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\task2.dir\main.cpp.obj -c D:\SKILLBOX\C++__Homework\mod24\task2\main.cpp

CMakeFiles/task2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task2.dir/main.cpp.i"
	D:\min-gw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\SKILLBOX\C++__Homework\mod24\task2\main.cpp > CMakeFiles\task2.dir\main.cpp.i

CMakeFiles/task2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task2.dir/main.cpp.s"
	D:\min-gw\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\SKILLBOX\C++__Homework\mod24\task2\main.cpp -o CMakeFiles\task2.dir\main.cpp.s

# Object files for target task2
task2_OBJECTS = \
"CMakeFiles/task2.dir/main.cpp.obj"

# External object files for target task2
task2_EXTERNAL_OBJECTS =

task2.exe: CMakeFiles/task2.dir/main.cpp.obj
task2.exe: CMakeFiles/task2.dir/build.make
task2.exe: CMakeFiles/task2.dir/linklibs.rsp
task2.exe: CMakeFiles/task2.dir/objects1.rsp
task2.exe: CMakeFiles/task2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\SKILLBOX\C++__Homework\mod24\task2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\task2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task2.dir/build: task2.exe

.PHONY : CMakeFiles/task2.dir/build

CMakeFiles/task2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\task2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/task2.dir/clean

CMakeFiles/task2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\SKILLBOX\C++__Homework\mod24\task2 D:\SKILLBOX\C++__Homework\mod24\task2 D:\SKILLBOX\C++__Homework\mod24\task2\cmake-build-debug D:\SKILLBOX\C++__Homework\mod24\task2\cmake-build-debug D:\SKILLBOX\C++__Homework\mod24\task2\cmake-build-debug\CMakeFiles\task2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task2.dir/depend

