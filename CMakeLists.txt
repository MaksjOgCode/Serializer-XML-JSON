cmake_minimum_required(VERSION 3.10)

project(serializer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
  src/cpp/main.cpp
  src/cpp/serializer.cpp
  src/cpp/vehicle.cpp
)

add_executable(main.out ${SOURCES})

target_include_directories(main.out PRIVATE src/hpp)
