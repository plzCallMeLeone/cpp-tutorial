cmake_minimum_required(VERSION 3.10)

project(graphics)
add_executable(graphics src/main.cxx src/Lines.cxx)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

target_link_libraries(graphics sfml-graphics sfml-window sfml-system)