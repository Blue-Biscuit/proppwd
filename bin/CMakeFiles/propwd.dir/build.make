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
CMAKE_SOURCE_DIR = /home/andrewh/git/proppwd/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrewh/git/proppwd/bin

# Include any dependencies generated for this target.
include CMakeFiles/propwd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/propwd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/propwd.dir/flags.make

CMakeFiles/propwd.dir/main.c.o: CMakeFiles/propwd.dir/flags.make
CMakeFiles/propwd.dir/main.c.o: /home/andrewh/git/proppwd/src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewh/git/proppwd/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/propwd.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/propwd.dir/main.c.o -c /home/andrewh/git/proppwd/src/main.c

CMakeFiles/propwd.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/propwd.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrewh/git/proppwd/src/main.c > CMakeFiles/propwd.dir/main.c.i

CMakeFiles/propwd.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/propwd.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrewh/git/proppwd/src/main.c -o CMakeFiles/propwd.dir/main.c.s

CMakeFiles/propwd.dir/c_interface.c.o: CMakeFiles/propwd.dir/flags.make
CMakeFiles/propwd.dir/c_interface.c.o: /home/andrewh/git/proppwd/src/c_interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewh/git/proppwd/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/propwd.dir/c_interface.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/propwd.dir/c_interface.c.o -c /home/andrewh/git/proppwd/src/c_interface.c

CMakeFiles/propwd.dir/c_interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/propwd.dir/c_interface.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrewh/git/proppwd/src/c_interface.c > CMakeFiles/propwd.dir/c_interface.c.i

CMakeFiles/propwd.dir/c_interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/propwd.dir/c_interface.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrewh/git/proppwd/src/c_interface.c -o CMakeFiles/propwd.dir/c_interface.c.s

CMakeFiles/propwd.dir/helpers.c.o: CMakeFiles/propwd.dir/flags.make
CMakeFiles/propwd.dir/helpers.c.o: /home/andrewh/git/proppwd/src/helpers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewh/git/proppwd/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/propwd.dir/helpers.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/propwd.dir/helpers.c.o -c /home/andrewh/git/proppwd/src/helpers.c

CMakeFiles/propwd.dir/helpers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/propwd.dir/helpers.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrewh/git/proppwd/src/helpers.c > CMakeFiles/propwd.dir/helpers.c.i

CMakeFiles/propwd.dir/helpers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/propwd.dir/helpers.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrewh/git/proppwd/src/helpers.c -o CMakeFiles/propwd.dir/helpers.c.s

CMakeFiles/propwd.dir/account.c.o: CMakeFiles/propwd.dir/flags.make
CMakeFiles/propwd.dir/account.c.o: /home/andrewh/git/proppwd/src/account.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewh/git/proppwd/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/propwd.dir/account.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/propwd.dir/account.c.o -c /home/andrewh/git/proppwd/src/account.c

CMakeFiles/propwd.dir/account.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/propwd.dir/account.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrewh/git/proppwd/src/account.c > CMakeFiles/propwd.dir/account.c.i

CMakeFiles/propwd.dir/account.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/propwd.dir/account.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrewh/git/proppwd/src/account.c -o CMakeFiles/propwd.dir/account.c.s

CMakeFiles/propwd.dir/obscure_str.c.o: CMakeFiles/propwd.dir/flags.make
CMakeFiles/propwd.dir/obscure_str.c.o: /home/andrewh/git/proppwd/src/obscure_str.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewh/git/proppwd/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/propwd.dir/obscure_str.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/propwd.dir/obscure_str.c.o -c /home/andrewh/git/proppwd/src/obscure_str.c

CMakeFiles/propwd.dir/obscure_str.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/propwd.dir/obscure_str.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrewh/git/proppwd/src/obscure_str.c > CMakeFiles/propwd.dir/obscure_str.c.i

CMakeFiles/propwd.dir/obscure_str.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/propwd.dir/obscure_str.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrewh/git/proppwd/src/obscure_str.c -o CMakeFiles/propwd.dir/obscure_str.c.s

CMakeFiles/propwd.dir/tester.c.o: CMakeFiles/propwd.dir/flags.make
CMakeFiles/propwd.dir/tester.c.o: /home/andrewh/git/proppwd/src/tester.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewh/git/proppwd/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/propwd.dir/tester.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/propwd.dir/tester.c.o -c /home/andrewh/git/proppwd/src/tester.c

CMakeFiles/propwd.dir/tester.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/propwd.dir/tester.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrewh/git/proppwd/src/tester.c > CMakeFiles/propwd.dir/tester.c.i

CMakeFiles/propwd.dir/tester.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/propwd.dir/tester.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrewh/git/proppwd/src/tester.c -o CMakeFiles/propwd.dir/tester.c.s

# Object files for target propwd
propwd_OBJECTS = \
"CMakeFiles/propwd.dir/main.c.o" \
"CMakeFiles/propwd.dir/c_interface.c.o" \
"CMakeFiles/propwd.dir/helpers.c.o" \
"CMakeFiles/propwd.dir/account.c.o" \
"CMakeFiles/propwd.dir/obscure_str.c.o" \
"CMakeFiles/propwd.dir/tester.c.o"

# External object files for target propwd
propwd_EXTERNAL_OBJECTS =

propwd: CMakeFiles/propwd.dir/main.c.o
propwd: CMakeFiles/propwd.dir/c_interface.c.o
propwd: CMakeFiles/propwd.dir/helpers.c.o
propwd: CMakeFiles/propwd.dir/account.c.o
propwd: CMakeFiles/propwd.dir/obscure_str.c.o
propwd: CMakeFiles/propwd.dir/tester.c.o
propwd: CMakeFiles/propwd.dir/build.make
propwd: CMakeFiles/propwd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrewh/git/proppwd/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable propwd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/propwd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/propwd.dir/build: propwd

.PHONY : CMakeFiles/propwd.dir/build

CMakeFiles/propwd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/propwd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/propwd.dir/clean

CMakeFiles/propwd.dir/depend:
	cd /home/andrewh/git/proppwd/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrewh/git/proppwd/src /home/andrewh/git/proppwd/src /home/andrewh/git/proppwd/bin /home/andrewh/git/proppwd/bin /home/andrewh/git/proppwd/bin/CMakeFiles/propwd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/propwd.dir/depend

