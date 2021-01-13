

pybind11_add_module(geo geo.cpp)

target_include_directories(geo
  PUBLIC
  ${PROJECT_SOURCE_DIR}/src/ray
  )

target_link_libraries(geo
  PUBLIC ray
  PRIVATE fmt
  )
