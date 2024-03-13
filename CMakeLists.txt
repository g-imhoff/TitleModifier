cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(TitleModifier)

file(GLOB SOURCES "src/*.c")

set(CMAKE_SYSTEM_NAME Linux)
add_executable(TitleModifier ${SOURCES})
