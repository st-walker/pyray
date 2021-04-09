

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(ray STATIC
  ray/tuple.cpp
  ray/colour.cpp
  ray/canvas.cpp
  ray/ppm.cpp
  ray/matrix.cpp
  )

target_link_libraries(ray
  PRIVATE fmt)


if (cppray_BUILD_TESTS)
  message(STATUS "Configuring tests")
  enable_testing()
  include(GoogleTest)
  add_executable(
    unit_tests
    ray/tuple.test.cpp
    ray/colour.test.cpp
    ray/canvas.test.cpp
    ray/ppm.test.cpp
    ray/matrix.test.cpp
    )

  target_link_libraries(
    unit_tests
    PUBLIC
    gtest
    gmock_main
    ray
    PRIVATE
    fmt
    )

  gtest_discover_tests(unit_tests)
endif()
