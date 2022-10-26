cmake_minimum_required(VERSION 3.20)
project(ece_city_1_c C)

set(CMAKE_C_STANDARD 11)

add_executable(ece_city_1_c
        main.c main.h)

target_link_libraries(ece_city_1_c -lmingw32 -lallegro-5.0.10-monolith-md-debug)
