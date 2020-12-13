cmake_minimum_required(VERSION 3.17)
project(CS2301_HW6_Battleship C)

set(CMAKE_C_STANDARD 99)

add_executable(CS2301_HW6_Battleship src/battleship.c src/battleship.h src/board.c src/board.h src/production.c src/production.h src/tests.c src/tests.h src/CS2301_HW6_Battleship.c)