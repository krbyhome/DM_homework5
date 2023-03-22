cmake_minimum_required(VERSION 3.18)

project(
        DM_HW5
        LANGUAGES CXX
)

add_subdirectory(bin)
add_subdirectory(lib)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)