# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/exame.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/exame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exame.dir/flags.make

CMakeFiles/exame.dir/main.cpp.obj: CMakeFiles/exame.dir/flags.make
CMakeFiles/exame.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exame.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\exame.dir\main.cpp.obj -c C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\main.cpp

CMakeFiles/exame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exame.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\main.cpp > CMakeFiles\exame.dir\main.cpp.i

CMakeFiles/exame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exame.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\main.cpp -o CMakeFiles\exame.dir\main.cpp.s

# Object files for target exame
exame_OBJECTS = \
"CMakeFiles/exame.dir/main.cpp.obj"

# External object files for target exame
exame_EXTERNAL_OBJECTS =

exame.exe: CMakeFiles/exame.dir/main.cpp.obj
exame.exe: CMakeFiles/exame.dir/build.make
exame.exe: CMakeFiles/exame.dir/linklibs.rsp
exame.exe: CMakeFiles/exame.dir/objects1.rsp
exame.exe: CMakeFiles/exame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exame.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\exame.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exame.dir/build: exame.exe
.PHONY : CMakeFiles/exame.dir/build

CMakeFiles/exame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\exame.dir\cmake_clean.cmake
.PHONY : CMakeFiles/exame.dir/clean

CMakeFiles/exame.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\cmake-build-debug C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\cmake-build-debug C:\Users\clfma\Desktop\Faculdade\Y2S2\DA\preparacaoExame\exame\cmake-build-debug\CMakeFiles\exame.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exame.dir/depend

