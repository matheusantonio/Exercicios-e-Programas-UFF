# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/T2PAQ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/T2PAQ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/T2PAQ.dir/flags.make

CMakeFiles/T2PAQ.dir/main.c.obj: CMakeFiles/T2PAQ.dir/flags.make
CMakeFiles/T2PAQ.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/T2PAQ.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\T2PAQ.dir\main.c.obj   -c "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\main.c"

CMakeFiles/T2PAQ.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/T2PAQ.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\main.c" > CMakeFiles\T2PAQ.dir\main.c.i

CMakeFiles/T2PAQ.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/T2PAQ.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\main.c" -o CMakeFiles\T2PAQ.dir\main.c.s

CMakeFiles/T2PAQ.dir/main.c.obj.requires:

.PHONY : CMakeFiles/T2PAQ.dir/main.c.obj.requires

CMakeFiles/T2PAQ.dir/main.c.obj.provides: CMakeFiles/T2PAQ.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\T2PAQ.dir\build.make CMakeFiles/T2PAQ.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/T2PAQ.dir/main.c.obj.provides

CMakeFiles/T2PAQ.dir/main.c.obj.provides.build: CMakeFiles/T2PAQ.dir/main.c.obj


CMakeFiles/T2PAQ.dir/fila.c.obj: CMakeFiles/T2PAQ.dir/flags.make
CMakeFiles/T2PAQ.dir/fila.c.obj: ../fila.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/T2PAQ.dir/fila.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\T2PAQ.dir\fila.c.obj   -c "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\fila.c"

CMakeFiles/T2PAQ.dir/fila.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/T2PAQ.dir/fila.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\fila.c" > CMakeFiles\T2PAQ.dir\fila.c.i

CMakeFiles/T2PAQ.dir/fila.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/T2PAQ.dir/fila.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\fila.c" -o CMakeFiles\T2PAQ.dir\fila.c.s

CMakeFiles/T2PAQ.dir/fila.c.obj.requires:

.PHONY : CMakeFiles/T2PAQ.dir/fila.c.obj.requires

CMakeFiles/T2PAQ.dir/fila.c.obj.provides: CMakeFiles/T2PAQ.dir/fila.c.obj.requires
	$(MAKE) -f CMakeFiles\T2PAQ.dir\build.make CMakeFiles/T2PAQ.dir/fila.c.obj.provides.build
.PHONY : CMakeFiles/T2PAQ.dir/fila.c.obj.provides

CMakeFiles/T2PAQ.dir/fila.c.obj.provides.build: CMakeFiles/T2PAQ.dir/fila.c.obj


CMakeFiles/T2PAQ.dir/arvore.c.obj: CMakeFiles/T2PAQ.dir/flags.make
CMakeFiles/T2PAQ.dir/arvore.c.obj: ../arvore.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/T2PAQ.dir/arvore.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\T2PAQ.dir\arvore.c.obj   -c "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\arvore.c"

CMakeFiles/T2PAQ.dir/arvore.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/T2PAQ.dir/arvore.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\arvore.c" > CMakeFiles\T2PAQ.dir\arvore.c.i

CMakeFiles/T2PAQ.dir/arvore.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/T2PAQ.dir/arvore.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\arvore.c" -o CMakeFiles\T2PAQ.dir\arvore.c.s

CMakeFiles/T2PAQ.dir/arvore.c.obj.requires:

.PHONY : CMakeFiles/T2PAQ.dir/arvore.c.obj.requires

CMakeFiles/T2PAQ.dir/arvore.c.obj.provides: CMakeFiles/T2PAQ.dir/arvore.c.obj.requires
	$(MAKE) -f CMakeFiles\T2PAQ.dir\build.make CMakeFiles/T2PAQ.dir/arvore.c.obj.provides.build
.PHONY : CMakeFiles/T2PAQ.dir/arvore.c.obj.provides

CMakeFiles/T2PAQ.dir/arvore.c.obj.provides.build: CMakeFiles/T2PAQ.dir/arvore.c.obj


# Object files for target T2PAQ
T2PAQ_OBJECTS = \
"CMakeFiles/T2PAQ.dir/main.c.obj" \
"CMakeFiles/T2PAQ.dir/fila.c.obj" \
"CMakeFiles/T2PAQ.dir/arvore.c.obj"

# External object files for target T2PAQ
T2PAQ_EXTERNAL_OBJECTS =

T2PAQ.exe: CMakeFiles/T2PAQ.dir/main.c.obj
T2PAQ.exe: CMakeFiles/T2PAQ.dir/fila.c.obj
T2PAQ.exe: CMakeFiles/T2PAQ.dir/arvore.c.obj
T2PAQ.exe: CMakeFiles/T2PAQ.dir/build.make
T2PAQ.exe: CMakeFiles/T2PAQ.dir/linklibs.rsp
T2PAQ.exe: CMakeFiles/T2PAQ.dir/objects1.rsp
T2PAQ.exe: CMakeFiles/T2PAQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable T2PAQ.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\T2PAQ.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/T2PAQ.dir/build: T2PAQ.exe

.PHONY : CMakeFiles/T2PAQ.dir/build

CMakeFiles/T2PAQ.dir/requires: CMakeFiles/T2PAQ.dir/main.c.obj.requires
CMakeFiles/T2PAQ.dir/requires: CMakeFiles/T2PAQ.dir/fila.c.obj.requires
CMakeFiles/T2PAQ.dir/requires: CMakeFiles/T2PAQ.dir/arvore.c.obj.requires

.PHONY : CMakeFiles/T2PAQ.dir/requires

CMakeFiles/T2PAQ.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\T2PAQ.dir\cmake_clean.cmake
.PHONY : CMakeFiles/T2PAQ.dir/clean

CMakeFiles/T2PAQ.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ" "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ" "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\cmake-build-debug" "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\cmake-build-debug" "C:\Users\Matheus Antonio\Documents\Dev\Exercicios-e-Programas-UFF\PAQ\T2PAQ\cmake-build-debug\CMakeFiles\T2PAQ.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/T2PAQ.dir/depend
