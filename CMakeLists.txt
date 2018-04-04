cmake_minimum_required(VERSION 3.10)
project(Antra_uzduotis)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Antra_uzduotis
        generavimas.cpp
        generavimas.h
        isvedimas.cpp
        isvedimas.h
        main.cpp
        mediana.cpp
        mediana.h
        nuskaitymas.cpp
        nuskaitymas.h
        rikiavimas.cpp
        rikiavimas.h
        skirstymas.cpp
        skirstymas.h
        studentas.h
        vidurkis.cpp
        vidurkis.h)
