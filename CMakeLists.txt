cmake_minimum_required(VERSION 3.27)
project(POO_Lab_2_4 C)

set(CMAKE_C_STANDARD 11)

set(PROJECT_HEADERS
        header/mylist.h
        header/participant.h
        header/service.h
)
set(PROJECT_SOURCES
        main.c
        src/mylist.c
        src/participant.c
        src/service.c
)

add_executable(POO_Lab_2_4 ${PROJECT_SOURCES} ${PROJECT_HEADERS})
