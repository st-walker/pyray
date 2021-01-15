#ifndef RAY_COLOUR_HPP
#define RAY_COLOUR_HPP

#include "tuple.hpp"

namespace ray {
class Colour {
public:
  Colour() : rgba_(0, 0, 0, 1) {}
  Colour(double r, double g, double b) : rgba_(r, g, b, 1.) {}

  double red() const { return rgba_.x(); }
  double green() const { return rgba_.y(); }
  double blue() const { return rgba_.z(); }

  Colour operator+(Colour const &) const;
  Colour operator-(Colour const &) const;
  Colour operator*(double) const;
  friend Colour operator*(double, Colour const &);
  bool operator==(Colour const&) const;

private:
  Tuple rgba_;
};
} // namespace ray

#endif /* RAY_COLOUR_HPP */
