# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig

# Include any dependencies generated for this target.
include CMakeFiles/conf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/conf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/conf.dir/flags.make

CMakeFiles/conf.dir/conf.c.o: CMakeFiles/conf.dir/flags.make
CMakeFiles/conf.dir/conf.c.o: conf.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/conf.dir/conf.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/conf.dir/conf.c.o   -c /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig/conf.c

CMakeFiles/conf.dir/conf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/conf.dir/conf.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig/conf.c > CMakeFiles/conf.dir/conf.c.i

CMakeFiles/conf.dir/conf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/conf.dir/conf.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig/conf.c -o CMakeFiles/conf.dir/conf.c.s

CMakeFiles/conf.dir/conf.c.o.requires:
.PHONY : CMakeFiles/conf.dir/conf.c.o.requires

CMakeFiles/conf.dir/conf.c.o.provides: CMakeFiles/conf.dir/conf.c.o.requires
	$(MAKE) -f CMakeFiles/conf.dir/build.make CMakeFiles/conf.dir/conf.c.o.provides.build
.PHONY : CMakeFiles/conf.dir/conf.c.o.provides

CMakeFiles/conf.dir/conf.c.o.provides.build: CMakeFiles/conf.dir/conf.c.o

# Object files for target conf
conf_OBJECTS = \
"CMakeFiles/conf.dir/conf.c.o"

# External object files for target conf
conf_EXTERNAL_OBJECTS =

conf: CMakeFiles/conf.dir/conf.c.o
conf: CMakeFiles/conf.dir/build.make
conf: /usr/lib/x86_64-linux-gnu/libcurses.so
conf: /usr/lib/x86_64-linux-gnu/libform.so
conf: libzconf.a
conf: CMakeFiles/conf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable conf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/conf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/conf.dir/build: conf
.PHONY : CMakeFiles/conf.dir/build

CMakeFiles/conf.dir/requires: CMakeFiles/conf.dir/conf.c.o.requires
.PHONY : CMakeFiles/conf.dir/requires

CMakeFiles/conf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/conf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/conf.dir/clean

CMakeFiles/conf.dir/depend:
	cd /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig /home/baiyibing/code/crismison/project_rm/Code/tools/menuconfig/CMakeFiles/conf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/conf.dir/depend

