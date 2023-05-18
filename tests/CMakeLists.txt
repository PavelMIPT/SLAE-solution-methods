cmake_minimum_required(VERSION 3.0.0)
project(SLAE)

set(CMAKE_CXX_STANDART 20)

find_package(GTest REQUIRED)

add_executable(Tests Speedest_Grad_Descent._Test.cpp)

add_test(Tests COMMAND Speedest_Grad_Descent._Test.cpp)

target_link_libraries(Tests GTest::gtest_main)
