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
CMAKE_SOURCE_DIR = /home/david/oop/lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/oop/lab6

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/test1.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test1.cpp.o: test1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/test1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/test1.cpp.o -c /home/david/oop/lab6/test1.cpp

CMakeFiles/tests.dir/test1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/test1.cpp > CMakeFiles/tests.dir/test1.cpp.i

CMakeFiles/tests.dir/test1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/test1.cpp -o CMakeFiles/tests.dir/test1.cpp.s

CMakeFiles/tests.dir/src/bear.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/bear.cpp.o: src/bear.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/src/bear.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/bear.cpp.o -c /home/david/oop/lab6/src/bear.cpp

CMakeFiles/tests.dir/src/bear.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/bear.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/src/bear.cpp > CMakeFiles/tests.dir/src/bear.cpp.i

CMakeFiles/tests.dir/src/bear.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/bear.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/src/bear.cpp -o CMakeFiles/tests.dir/src/bear.cpp.s

CMakeFiles/tests.dir/src/factory.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/factory.cpp.o: src/factory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/src/factory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/factory.cpp.o -c /home/david/oop/lab6/src/factory.cpp

CMakeFiles/tests.dir/src/factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/factory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/src/factory.cpp > CMakeFiles/tests.dir/src/factory.cpp.i

CMakeFiles/tests.dir/src/factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/factory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/src/factory.cpp -o CMakeFiles/tests.dir/src/factory.cpp.s

CMakeFiles/tests.dir/src/fight.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/fight.cpp.o: src/fight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tests.dir/src/fight.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/fight.cpp.o -c /home/david/oop/lab6/src/fight.cpp

CMakeFiles/tests.dir/src/fight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/fight.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/src/fight.cpp > CMakeFiles/tests.dir/src/fight.cpp.i

CMakeFiles/tests.dir/src/fight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/fight.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/src/fight.cpp -o CMakeFiles/tests.dir/src/fight.cpp.s

CMakeFiles/tests.dir/src/npc.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/npc.cpp.o: src/npc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tests.dir/src/npc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/npc.cpp.o -c /home/david/oop/lab6/src/npc.cpp

CMakeFiles/tests.dir/src/npc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/npc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/src/npc.cpp > CMakeFiles/tests.dir/src/npc.cpp.i

CMakeFiles/tests.dir/src/npc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/npc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/src/npc.cpp -o CMakeFiles/tests.dir/src/npc.cpp.s

CMakeFiles/tests.dir/src/observerConsole.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/observerConsole.cpp.o: src/observerConsole.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tests.dir/src/observerConsole.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/observerConsole.cpp.o -c /home/david/oop/lab6/src/observerConsole.cpp

CMakeFiles/tests.dir/src/observerConsole.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/observerConsole.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/src/observerConsole.cpp > CMakeFiles/tests.dir/src/observerConsole.cpp.i

CMakeFiles/tests.dir/src/observerConsole.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/observerConsole.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/src/observerConsole.cpp -o CMakeFiles/tests.dir/src/observerConsole.cpp.s

CMakeFiles/tests.dir/src/observerFile.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/observerFile.cpp.o: src/observerFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tests.dir/src/observerFile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/observerFile.cpp.o -c /home/david/oop/lab6/src/observerFile.cpp

CMakeFiles/tests.dir/src/observerFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/observerFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/src/observerFile.cpp > CMakeFiles/tests.dir/src/observerFile.cpp.i

CMakeFiles/tests.dir/src/observerFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/observerFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/src/observerFile.cpp -o CMakeFiles/tests.dir/src/observerFile.cpp.s

CMakeFiles/tests.dir/src/orc.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/orc.cpp.o: src/orc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tests.dir/src/orc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/orc.cpp.o -c /home/david/oop/lab6/src/orc.cpp

CMakeFiles/tests.dir/src/orc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/orc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/src/orc.cpp > CMakeFiles/tests.dir/src/orc.cpp.i

CMakeFiles/tests.dir/src/orc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/orc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/src/orc.cpp -o CMakeFiles/tests.dir/src/orc.cpp.s

CMakeFiles/tests.dir/src/squirrel.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/squirrel.cpp.o: src/squirrel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/tests.dir/src/squirrel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tests.dir/src/squirrel.cpp.o -c /home/david/oop/lab6/src/squirrel.cpp

CMakeFiles/tests.dir/src/squirrel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/squirrel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/oop/lab6/src/squirrel.cpp > CMakeFiles/tests.dir/src/squirrel.cpp.i

CMakeFiles/tests.dir/src/squirrel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/squirrel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/oop/lab6/src/squirrel.cpp -o CMakeFiles/tests.dir/src/squirrel.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test1.cpp.o" \
"CMakeFiles/tests.dir/src/bear.cpp.o" \
"CMakeFiles/tests.dir/src/factory.cpp.o" \
"CMakeFiles/tests.dir/src/fight.cpp.o" \
"CMakeFiles/tests.dir/src/npc.cpp.o" \
"CMakeFiles/tests.dir/src/observerConsole.cpp.o" \
"CMakeFiles/tests.dir/src/observerFile.cpp.o" \
"CMakeFiles/tests.dir/src/orc.cpp.o" \
"CMakeFiles/tests.dir/src/squirrel.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/test1.cpp.o
tests: CMakeFiles/tests.dir/src/bear.cpp.o
tests: CMakeFiles/tests.dir/src/factory.cpp.o
tests: CMakeFiles/tests.dir/src/fight.cpp.o
tests: CMakeFiles/tests.dir/src/npc.cpp.o
tests: CMakeFiles/tests.dir/src/observerConsole.cpp.o
tests: CMakeFiles/tests.dir/src/observerFile.cpp.o
tests: CMakeFiles/tests.dir/src/orc.cpp.o
tests: CMakeFiles/tests.dir/src/squirrel.cpp.o
tests: CMakeFiles/tests.dir/build.make
tests: /usr/lib/x86_64-linux-gnu/libgtest.a
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/oop/lab6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests

.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /home/david/oop/lab6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/oop/lab6 /home/david/oop/lab6 /home/david/oop/lab6 /home/david/oop/lab6 /home/david/oop/lab6/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend

