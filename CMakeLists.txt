cmake_minimum_required(VERSION 3.2)

project(chip-8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE CHIP8_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(chip-8 ${CHIP8_SOURCES})