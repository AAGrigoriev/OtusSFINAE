cmake_minimum_required(VERSION 3.10)

project(print_main)

SET(HEADER_WAY "inc/")
SET(SOURCE_WAY "src/")

add_executable(print ${SOURCE_WAY}/main.cpp)

target_include_directories(print 
PRIVATE
 "inc/")

