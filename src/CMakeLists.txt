

add_compile_options(-Wall -Wextra -Wpedantic)

add_library(ray STATIC
  ray/tuple.cpp)


if (cppray_BUILD_TESTS)
  message(STATUS "Configuring tests")
  enable_testing()
  include(GoogleTest)
  add_executable(
    unit_tests
    ray/tuple.test.cpp)

  target_link_libraries(
    unit_tests
    gtest
    gmock_main
    ray)

  gtest_discover_tests(unit_tests)
endif()
