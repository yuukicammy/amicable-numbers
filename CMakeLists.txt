cmake_minimum_required(VERSION 3.1)
project(amicable_numbers)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_COMPILER /usr/local/bin/gcc-9)
#set(CMAKE_CXX_COMPILER /usr/local/bin/g++-9)

add_executable(amicable_numbers main.cpp)

if(MSVC)
    target_compile_options(amicable_numbers PRIVATE /EHsc /MP /bigobj)
    set(CMAKE_EXE_LINKER_FLAGS /MANIFEST:NO)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
    (CMAKE_CXX_COMPILER_ID MATCHES "Intel" AND NOT WIN32))
    target_compile_options(amicable_numbers PRIVATE -march=native -std=c++17 -ftemplate-depth=8000)
endif()
