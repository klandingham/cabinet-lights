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
CMAKE_COMMAND = /home/kip/bin/clion-2020.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/kip/bin/clion-2020.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kip/Projects/cabinet-lights

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kip/Projects/cabinet-lights/cmake-build-debug

# Utility rule file for Production.

# Include the progress variables for this target.
include CMakeFiles/Production.dir/progress.make

CMakeFiles/Production:
	cd /home/kip/Projects/cabinet-lights && platformio -c clion run -eDebug

Production: CMakeFiles/Production
Production: CMakeFiles/Production.dir/build.make

.PHONY : Production

# Rule to build all files generated by this target.
CMakeFiles/Production.dir/build: Production

.PHONY : CMakeFiles/Production.dir/build

CMakeFiles/Production.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Production.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Production.dir/clean

CMakeFiles/Production.dir/depend:
	cd /home/kip/Projects/cabinet-lights/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kip/Projects/cabinet-lights /home/kip/Projects/cabinet-lights /home/kip/Projects/cabinet-lights/cmake-build-debug /home/kip/Projects/cabinet-lights/cmake-build-debug /home/kip/Projects/cabinet-lights/cmake-build-debug/CMakeFiles/Production.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Production.dir/depend

