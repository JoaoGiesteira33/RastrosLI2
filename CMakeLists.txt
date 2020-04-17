cmake_minimum_required(VERSION 3.15)
project(RastrosLI2 C)

set(CMAKE_C_STANDARD 99)

add_executable(RastrosLI2 main.c logica.c logica.h camadadados.c camadadados.h interface.c interface.h lista.c lista.h)