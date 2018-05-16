cmake_minimum_required(VERSION 3.9)
project(hashcode)

set(CMAKE_CXX_STANDARD 11)

add_executable(hashcode
        includes/hashcode.h
        libft/includes/libft.h
        srcs/main.c)

include_directories(${CMAKE_HOME_DIRECTORY}/includes)
include_directories(${CMAKE_HOME_DIRECTORY}/libft/includes)
target_link_libraries(hashcode ${CMAKE_SOURCE_DIR}/libft/libft.a)