cmake_minimum_required(VERSION 3.20)
project(comgate LANGUAGES CXX)

# Generate compile command.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++ 20 Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
  -Wall
  -Wextra
  -Wpedantic
  # -Werror
  -Wconversion
  -Wsign-conversion
  # security flags
  -fstack-protector-strong
  -D_FORTIFY_SOURCE=2)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,now,-z,relro")

add_executable(comgate src/main.cpp) # src/other.cpp)
target_include_directories(comgate PRIVATE include)
