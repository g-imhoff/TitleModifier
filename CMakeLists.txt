cmake_minimum_required(VERSION 3.10)
project(NoMorePluggSupply)

file(GLOB SOURCES "src/*.c")

if(UNIX AND NOT APPLE)
    add_executable(NoMorePluggSupply ${SOURCES})
elseif(WIN32)
    add_executable(NoMorePluggSupply WIN32 ${SOURCES})
endif()



