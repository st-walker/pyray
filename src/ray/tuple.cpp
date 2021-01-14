#include "tuple.hpp"

#include <cmath>

namespace ray {

Tuple Point(double x, double y, double z) { return Tuple(x, y, z, 1.0); }

Tuple Vector(double x, double y, double z) { return Tuple(x, y, z, 0.); }

double magnitude(Tuple const &t) {
  return std::sqrt(t.x() * t.x() + t.y() * t.y() + t.z() * t.z() +
                   t.w() * t.w());
}

Tuple unit(Tuple const &t) { return t / magnitude(t); }

double dot(Tuple const &a, Tuple const &b) {
  return a.x() * b.x() + a.y() * b.y() + a.z() * b.z() + a.w() * b.w();
}

Tuple cross(Tuple const &a, Tuple const &b) {
  return Vector(a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
                a.x() * b.y() - a.y() * b.x());
}

bool Tuple::operator==(Tuple const &other) const {
  return x() == other.x() && y() == other.y() && z() == other.z() &&
         w() == other.w();
}

Tuple Tuple::operator+(Tuple const &other) const {
  return Tuple(x() + other.x(), y() + other.y(), z() + other.z(),
               w() + other.w());
}

Tuple Tuple::operator-(Tuple const &other) const {
  return Tuple(x() - other.x(), y() - other.y(), z() - other.z(),
               w() - other.w());
}

Tuple Tuple::operator-() const { return Tuple(-x(), -y(), -z(), -w()); }

Tuple Tuple::operator*(double c) const {
  return Tuple(c * x(), c * y(), c * z(), c * w());
}

Tuple operator*(double c, Tuple const &t) { return t * c; }

Tuple Tuple::operator/(double c) const { return *this * (1 / c); }

std::ostream &operator<<(std::ostream &os, const Tuple &t) {
  return os << "<Tuple: (" << t.x() << ", " << t.y() << ", " << t.z() << ", "
            << t.w() << ")>";
}
} // namespace ray
