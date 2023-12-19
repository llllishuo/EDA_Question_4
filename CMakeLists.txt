cmake_minimum_required(VERSION 3.24)
project(Analysis_of_time_series_problems)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(
        Analysis_of_time_series_problems
        main.cpp
        include/DataHanding.h
        analysis/timing_Analysis.cpp include/timing_Analysis.h
        common/DataHanding.cpp
        file/io.cpp include/io.h
        include/DataStructure.h
        common/Cli.cpp include/Cli.h
        test/case.cpp include/case.h
        file/line.cpp include/line.h
        analysis/ThreadPool.cpp include/ThreadPool.h
        )

add_executable(main main.cpp)
find_package(Threads REQUIRED)
target_link_libraries(Analysis_of_time_series_problems Threads::Threads)



