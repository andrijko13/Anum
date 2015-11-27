cmake_minimum_required (VERSION 2.6)
project (ANUM)
set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(src)
add_subdirectory(src)
file(GLOB SRC RELATIVE "src" "*.cpp")
add_executable(sample_usage ${SRC} sample_usage.cpp)
target_link_libraries(sample_usage anum)
