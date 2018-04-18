cmake_minimum_required(VERSION 3.10)
project(Antra_uzduotis_clone)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Antra_uzduotis_clone
        funkcijos.cpp
        funkcijos.h
        main.cpp
        studentas.h)
