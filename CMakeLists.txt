cmake_minimum_required(VERSION 3.22)

project(Progonka)

set(CMAKE_CXX_STANDART 22)

file(GLOB_RECURSE SOURCES *.h *.cpp)

add_library(Matrix INTERFACE  ${SOURCES})
