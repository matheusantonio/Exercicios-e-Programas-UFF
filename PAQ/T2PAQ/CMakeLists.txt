cmake_minimum_required(VERSION 3.10)
project(T2PAQ C)

set(CMAKE_C_STANDARD 99)

add_executable(T2PAQ main.c fila.h fila.c arvore.c arvore.h)