# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /home/ubuntu/miniconda3/lib/python3.11/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/ubuntu/miniconda3/lib/python3.11/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build

# Include any dependencies generated for this target.
include CMakeFiles/Analysis_of_time_series_problems.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Analysis_of_time_series_problems.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Analysis_of_time_series_problems.dir/flags.make

CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/flags.make
CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o: /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/main.cpp
CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o -MF CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o.d -o CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o -c /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/main.cpp

CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/main.cpp > CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.i

CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/main.cpp -o CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.s

CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/flags.make
CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o: /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/analysis/timing_Analysis.cpp
CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o -MF CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o.d -o CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o -c /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/analysis/timing_Analysis.cpp

CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/analysis/timing_Analysis.cpp > CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.i

CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/analysis/timing_Analysis.cpp -o CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.s

CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/flags.make
CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o: /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/common/DataHanding.cpp
CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o -MF CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o.d -o CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o -c /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/common/DataHanding.cpp

CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/common/DataHanding.cpp > CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.i

CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/common/DataHanding.cpp -o CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.s

CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/flags.make
CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o: /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/file/io.cpp
CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o -MF CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o.d -o CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o -c /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/file/io.cpp

CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/file/io.cpp > CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.i

CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/file/io.cpp -o CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.s

CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/flags.make
CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o: /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/common/Cli.cpp
CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o -MF CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o.d -o CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o -c /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/common/Cli.cpp

CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/common/Cli.cpp > CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.i

CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/common/Cli.cpp -o CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.s

CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/flags.make
CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o: /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/test/case.cpp
CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o -MF CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o.d -o CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o -c /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/test/case.cpp

CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/test/case.cpp > CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.i

CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/test/case.cpp -o CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.s

CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/flags.make
CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o: /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/file/line.cpp
CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o -MF CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o.d -o CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o -c /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/file/line.cpp

CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/file/line.cpp > CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.i

CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/file/line.cpp -o CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.s

CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/flags.make
CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o: /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/analysis/ThreadPool.cpp
CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o: CMakeFiles/Analysis_of_time_series_problems.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o -MF CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o.d -o CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o -c /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/analysis/ThreadPool.cpp

CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/analysis/ThreadPool.cpp > CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.i

CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/analysis/ThreadPool.cpp -o CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.s

# Object files for target Analysis_of_time_series_problems
Analysis_of_time_series_problems_OBJECTS = \
"CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o" \
"CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o" \
"CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o" \
"CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o" \
"CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o" \
"CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o" \
"CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o" \
"CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o"

# External object files for target Analysis_of_time_series_problems
Analysis_of_time_series_problems_EXTERNAL_OBJECTS =

Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/main.cpp.o
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/analysis/timing_Analysis.cpp.o
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/common/DataHanding.cpp.o
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/file/io.cpp.o
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/common/Cli.cpp.o
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/test/case.cpp.o
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/file/line.cpp.o
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/analysis/ThreadPool.cpp.o
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/build.make
Analysis_of_time_series_problems: CMakeFiles/Analysis_of_time_series_problems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Analysis_of_time_series_problems"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Analysis_of_time_series_problems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Analysis_of_time_series_problems.dir/build: Analysis_of_time_series_problems
.PHONY : CMakeFiles/Analysis_of_time_series_problems.dir/build

CMakeFiles/Analysis_of_time_series_problems.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Analysis_of_time_series_problems.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Analysis_of_time_series_problems.dir/clean

CMakeFiles/Analysis_of_time_series_problems.dir/depend:
	cd /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build /home/ubuntu/menghanstudio/cpp_dev/EDA/questionsFour/Analysis_of_time_series_problems/build/CMakeFiles/Analysis_of_time_series_problems.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Analysis_of_time_series_problems.dir/depend

