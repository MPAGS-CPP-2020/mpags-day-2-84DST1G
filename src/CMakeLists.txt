cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)


set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(mpags-cipher 
mpags-cipher.cpp
MPAGSCIPHER/TransformChar.cpp
MPAGSCIPHER/processCommandLine.cpp
)

target_include_directories(mpags-cipher
PRIVATE MPAGSCIPHER
)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

set(CMAKE_CXX_STANDARD 14)

target_compile_features(mpags-cipher
PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
)