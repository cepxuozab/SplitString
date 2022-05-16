cmake_minimum_required(VERSION 3.21)
project(SplitString)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)
add_executable(SplitString_run ${SOURCE_FILES})
include_directories(StringLib)
add_subdirectory(StringLib)


target_link_libraries(SplitString_run splitlib_lib)
set (BENCHMARK_ENABLE_TESTING OFF)
add_subdirectory(BenchSplit)
