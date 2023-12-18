cmake_minimum_required(VERSION 3.24)
project(projektMacierze)

set(CMAKE_CXX_STANDARD 17)

add_executable(projektMacierze main.cpp MetodaGaussa/MetodaGaussa.h GaussWyborKolumny/GaussWyborKolumny.h GaussPodstawowy/GaussPodstawowy.h GaussPelnyWybor/GaussPelnyWybor.h GaussWyborKolumny/GaussWyborKolumny.cpp GaussPelnyWybor/GaussPelnyWybor.cpp GaussPodstawowy/GaussPodstawowy.cpp MetodaGaussa/MetodaGaussa.cpp)
