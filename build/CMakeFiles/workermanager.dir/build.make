# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\build

# Include any dependencies generated for this target.
include CMakeFiles/workermanager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/workermanager.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/workermanager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/workermanager.dir/flags.make

CMakeFiles/workermanager.dir/codegen:
.PHONY : CMakeFiles/workermanager.dir/codegen

CMakeFiles/workermanager.dir/source/system.cpp.obj: CMakeFiles/workermanager.dir/flags.make
CMakeFiles/workermanager.dir/source/system.cpp.obj: C:/Users/WeiYao/Nutstore/1/CppCode/WorkerMangeSystem/source/system.cpp
CMakeFiles/workermanager.dir/source/system.cpp.obj: CMakeFiles/workermanager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/workermanager.dir/source/system.cpp.obj"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/workermanager.dir/source/system.cpp.obj -MF CMakeFiles\workermanager.dir\source\system.cpp.obj.d -o CMakeFiles\workermanager.dir\source\system.cpp.obj -c C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\source\system.cpp

CMakeFiles/workermanager.dir/source/system.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/workermanager.dir/source/system.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\source\system.cpp > CMakeFiles\workermanager.dir\source\system.cpp.i

CMakeFiles/workermanager.dir/source/system.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/workermanager.dir/source/system.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\source\system.cpp -o CMakeFiles\workermanager.dir\source\system.cpp.s

CMakeFiles/workermanager.dir/source/workerManager.cpp.obj: CMakeFiles/workermanager.dir/flags.make
CMakeFiles/workermanager.dir/source/workerManager.cpp.obj: C:/Users/WeiYao/Nutstore/1/CppCode/WorkerMangeSystem/source/workerManager.cpp
CMakeFiles/workermanager.dir/source/workerManager.cpp.obj: CMakeFiles/workermanager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/workermanager.dir/source/workerManager.cpp.obj"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/workermanager.dir/source/workerManager.cpp.obj -MF CMakeFiles\workermanager.dir\source\workerManager.cpp.obj.d -o CMakeFiles\workermanager.dir\source\workerManager.cpp.obj -c C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\source\workerManager.cpp

CMakeFiles/workermanager.dir/source/workerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/workermanager.dir/source/workerManager.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\source\workerManager.cpp > CMakeFiles\workermanager.dir\source\workerManager.cpp.i

CMakeFiles/workermanager.dir/source/workerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/workermanager.dir/source/workerManager.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\source\workerManager.cpp -o CMakeFiles\workermanager.dir\source\workerManager.cpp.s

# Object files for target workermanager
workermanager_OBJECTS = \
"CMakeFiles/workermanager.dir/source/system.cpp.obj" \
"CMakeFiles/workermanager.dir/source/workerManager.cpp.obj"

# External object files for target workermanager
workermanager_EXTERNAL_OBJECTS =

workermanager.exe: CMakeFiles/workermanager.dir/source/system.cpp.obj
workermanager.exe: CMakeFiles/workermanager.dir/source/workerManager.cpp.obj
workermanager.exe: CMakeFiles/workermanager.dir/build.make
workermanager.exe: CMakeFiles/workermanager.dir/linkLibs.rsp
workermanager.exe: CMakeFiles/workermanager.dir/objects1.rsp
workermanager.exe: CMakeFiles/workermanager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable workermanager.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\workermanager.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/workermanager.dir/build: workermanager.exe
.PHONY : CMakeFiles/workermanager.dir/build

CMakeFiles/workermanager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\workermanager.dir\cmake_clean.cmake
.PHONY : CMakeFiles/workermanager.dir/clean

CMakeFiles/workermanager.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\build C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\build C:\Users\WeiYao\Nutstore\1\CppCode\WorkerMangeSystem\build\CMakeFiles\workermanager.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/workermanager.dir/depend

