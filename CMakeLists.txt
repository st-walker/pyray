cmake_minimum_required(VERSION 3.19)

option(cppray_BUILD_TESTS "Build the cppray unit tests" ON)
option(cppray_BUILD_PYTHON_BINDINGS "Build the Python bindings" ON)

project(cppray
  VERSION 0.1
  DESCRIPTION "A Raytracer written in C++ for fun"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

add_subdirectory("src")
add_subdirectory(external/fmt)

if (cppray_BUILD_TESTS)
  add_subdirectory(external/googletest)
endif()
if (cppray_BUILD_PYTHON_BINDINGS)
  add_subdirectory(external/pybind11)
endif()
