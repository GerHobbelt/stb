cmake_minimum_required(VERSION 3.13)
project(STB VERSION 1.0.0 LANGUAGES C)

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
