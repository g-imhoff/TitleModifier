cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(NoMorePluggSupply)

file(GLOB SOURCES "src/*.c")

if(UNIX AND NOT APPLE)
    set(CMAKE_SYSTEM_NAME Linux)
    add_executable(NoMorePluggSupply ${SOURCES})
elseif(WIN32)
    set(CMAKE_SYSTEM_NAME Windows)
    add_executable(NoMorePluggSupply WIN32 ${SOURCES})
endif()
