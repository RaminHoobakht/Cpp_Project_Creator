cmake_minimum_required(VERSION 3.5)

set(CMAKE_PROJECT_NAME prjcreator)
set(CMAKE_PROJECT_VERSION 1)
set(CMAKE_PROJECT_VERSION_MAJOR 0)
set(CMAKE_PROJECT_VERSION_MINOR 1)
set(CMAKE_PROJECT_DESCRIPTION "training C++")

project (
        ${CMAKE_PROJECT_NAME}
        VERSION ${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}
        LANGUAGES CXX
        DESCRIPTION ${CMAKE_PROJECT_DESCRIPTION})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_DEFAULT 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++23 -O0 -g3 -pthread -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wconversion ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wcast-align -Wcast-qual -Wdisabled-optimization ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wlogical-op -Wmissing-declarations ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-include-dirs -Wredundant-decls ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow -Wsign-conversion -Wswitch-default ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wundef -Wfloat-equal -fmessage-length=0 ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -fPIC -fPIE -m64 -march=corei7-avx  ")

add_executable(${CMAKE_PROJECT_NAME} src/app/main.cpp
        src/classes/project.cpp
        src/classes/prjexception.cpp
        src/classes/prjexception.hpp
        src/header/filecontents.hpp
        src/header/constants.hpp
        src/header/util.hpp)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")