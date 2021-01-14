#include "colour.hpp"

namespace ray {

Colour Colour::operator+(Colour const &other) const {
  return Colour(red() + other.red(), green() + other.green(),
                blue() + other.blue());
}

Colour Colour::operator-(Colour const &other) const {
  return Colour(red() - other.red(), green() - other.green(),
                blue() - other.blue());
}

Colour Colour::operator*(double scalar) const {
  return Colour(red() * scalar, blue() * scalar, green() * scalar);
}

Colour operator*(double scalar, Colour const &colour) {
  return colour * scalar;
}

bool Colour::operator==(Colour const &other) const {
  return red() == other.red() && green() == other.green() &&
         blue() == other.blue();
}

} // namespace ray
