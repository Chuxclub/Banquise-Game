cmake_minimum_required(VERSION 3.9)
project(Banquise C)

set(CMAKE_C_STANDARD 99)

add_executable(Banquise main.c banquise.h banquise.c)