cmake_minimum_required(VERSION 3.28)

project(chip-8)
set(chip-8 VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)
FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-3.2.28
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL
  SYSTEM
)
FetchContent_MakeAvailable(SDL3)


file(GLOB_RECURSE CHIP8_SOURCES "src/*.hpp" "src/*.cpp")

add_executable(chip-8 ${CHIP8_SOURCES})

target_link_libraries(chip-8 PRIVATE SDL3::SDL3)
