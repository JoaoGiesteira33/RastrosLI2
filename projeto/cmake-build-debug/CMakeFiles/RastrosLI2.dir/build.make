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
CMAKE_COMMAND = /home/daniel/Desktop/Clion/clion-2019.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/daniel/Desktop/Clion/clion-2019.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daniel/LI2PL8G6/projeto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daniel/LI2PL8G6/projeto/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RastrosLI2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RastrosLI2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RastrosLI2.dir/flags.make

CMakeFiles/RastrosLI2.dir/main.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/LI2PL8G6/projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RastrosLI2.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/main.c.o   -c /home/daniel/LI2PL8G6/projeto/main.c

CMakeFiles/RastrosLI2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniel/LI2PL8G6/projeto/main.c > CMakeFiles/RastrosLI2.dir/main.c.i

CMakeFiles/RastrosLI2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniel/LI2PL8G6/projeto/main.c -o CMakeFiles/RastrosLI2.dir/main.c.s

CMakeFiles/RastrosLI2.dir/logica.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/logica.c.o: ../logica.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/LI2PL8G6/projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/RastrosLI2.dir/logica.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/logica.c.o   -c /home/daniel/LI2PL8G6/projeto/logica.c

CMakeFiles/RastrosLI2.dir/logica.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/logica.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniel/LI2PL8G6/projeto/logica.c > CMakeFiles/RastrosLI2.dir/logica.c.i

CMakeFiles/RastrosLI2.dir/logica.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/logica.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniel/LI2PL8G6/projeto/logica.c -o CMakeFiles/RastrosLI2.dir/logica.c.s

CMakeFiles/RastrosLI2.dir/camadadados.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/camadadados.c.o: ../camadadados.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/LI2PL8G6/projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/RastrosLI2.dir/camadadados.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/camadadados.c.o   -c /home/daniel/LI2PL8G6/projeto/camadadados.c

CMakeFiles/RastrosLI2.dir/camadadados.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/camadadados.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniel/LI2PL8G6/projeto/camadadados.c > CMakeFiles/RastrosLI2.dir/camadadados.c.i

CMakeFiles/RastrosLI2.dir/camadadados.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/camadadados.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniel/LI2PL8G6/projeto/camadadados.c -o CMakeFiles/RastrosLI2.dir/camadadados.c.s

CMakeFiles/RastrosLI2.dir/interface.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/interface.c.o: ../interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/LI2PL8G6/projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/RastrosLI2.dir/interface.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/interface.c.o   -c /home/daniel/LI2PL8G6/projeto/interface.c

CMakeFiles/RastrosLI2.dir/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/interface.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniel/LI2PL8G6/projeto/interface.c > CMakeFiles/RastrosLI2.dir/interface.c.i

CMakeFiles/RastrosLI2.dir/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/interface.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniel/LI2PL8G6/projeto/interface.c -o CMakeFiles/RastrosLI2.dir/interface.c.s

CMakeFiles/RastrosLI2.dir/lista.c.o: CMakeFiles/RastrosLI2.dir/flags.make
CMakeFiles/RastrosLI2.dir/lista.c.o: ../lista.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daniel/LI2PL8G6/projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/RastrosLI2.dir/lista.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RastrosLI2.dir/lista.c.o   -c /home/daniel/LI2PL8G6/projeto/lista.c

CMakeFiles/RastrosLI2.dir/lista.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RastrosLI2.dir/lista.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/daniel/LI2PL8G6/projeto/lista.c > CMakeFiles/RastrosLI2.dir/lista.c.i

CMakeFiles/RastrosLI2.dir/lista.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RastrosLI2.dir/lista.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/daniel/LI2PL8G6/projeto/lista.c -o CMakeFiles/RastrosLI2.dir/lista.c.s

# Object files for target RastrosLI2
RastrosLI2_OBJECTS = \
"CMakeFiles/RastrosLI2.dir/main.c.o" \
"CMakeFiles/RastrosLI2.dir/logica.c.o" \
"CMakeFiles/RastrosLI2.dir/camadadados.c.o" \
"CMakeFiles/RastrosLI2.dir/interface.c.o" \
"CMakeFiles/RastrosLI2.dir/lista.c.o"

# External object files for target RastrosLI2
RastrosLI2_EXTERNAL_OBJECTS =

RastrosLI2: CMakeFiles/RastrosLI2.dir/main.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/logica.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/camadadados.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/interface.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/lista.c.o
RastrosLI2: CMakeFiles/RastrosLI2.dir/build.make
RastrosLI2: CMakeFiles/RastrosLI2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daniel/LI2PL8G6/projeto/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable RastrosLI2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RastrosLI2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RastrosLI2.dir/build: RastrosLI2

.PHONY : CMakeFiles/RastrosLI2.dir/build

CMakeFiles/RastrosLI2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RastrosLI2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RastrosLI2.dir/clean

CMakeFiles/RastrosLI2.dir/depend:
	cd /home/daniel/LI2PL8G6/projeto/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daniel/LI2PL8G6/projeto /home/daniel/LI2PL8G6/projeto /home/daniel/LI2PL8G6/projeto/cmake-build-debug /home/daniel/LI2PL8G6/projeto/cmake-build-debug /home/daniel/LI2PL8G6/projeto/cmake-build-debug/CMakeFiles/RastrosLI2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RastrosLI2.dir/depend

