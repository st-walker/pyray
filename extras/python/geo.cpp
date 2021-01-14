#include <pybind11/pybind11.h>
#include <fmt/core.h>

#include "ray/tuple.hpp"

namespace py = pybind11;

using namespace ray;

PYBIND11_MODULE(geo, m) {
  m.doc() = "geo module documentation!";

  py::class_<Tuple>(m, "Tuple")
      .def(py::init<double, double, double, double>())

      .def_property("x", py::overload_cast<>(&Tuple::x, py::const_),
                    py::overload_cast<double>(&Tuple::x))
      .def_property("y", py::overload_cast<>(&Tuple::y, py::const_),
                    py::overload_cast<double>(&Tuple::y))
      .def_property("z", py::overload_cast<>(&Tuple::z, py::const_),
                    py::overload_cast<double>(&Tuple::z))
      .def_property("w", py::overload_cast<>(&Tuple::w, py::const_),
                    py::overload_cast<double>(&Tuple::w))

      .def("__repr__",
           [](const Tuple &t) {
             std::string message = fmt::format("<Tuple: ({}, {}, {}, {})>",
                                               t.x(), t.y(), t.z(), t.w());
             return message;
           })

      ;
}
