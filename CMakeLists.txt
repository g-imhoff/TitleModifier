cmake_minimum_required(VERSION 3.10)
project(NoMorePluggSupply)

include(build/windows_build.cmake)

file(GLOB SOURCES "src/*.c")
add_executable(NoMorePluggSupply ${SOURCES})

