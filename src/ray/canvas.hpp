#ifndef RAY_CANVAS_HPP
#define RAY_CANVAS_HPP

#include <vector>

#include "colour.hpp"

namespace ray {

class Canvas {
public:
  using Pixels = std::vector<Colour>;

  Canvas() = delete;
  Canvas(int width, int height)
      : width_(width), height_(height), pixels(width * height) {}

  int width() const { return width_; }
  int height() const { return height_; }

  void set_pixel(int row, int column, Colour c);
  Colour get_pixel(int row, int column) const;

  using iterator = Pixels::iterator;
  using const_iterator = Pixels::const_iterator;
  iterator begin() { return pixels.begin(); }
  iterator end() { return pixels.end(); }
  const_iterator begin() const { return pixels.begin(); }
  const_iterator end() const { return pixels.end(); }
  const_iterator cbegin() const { return pixels.cbegin(); }
  const_iterator cend() const { return pixels.cend(); }

private:
  int width_;
  int height_;
  Pixels pixels; // Row-major ordering, top left to bottom right.
  int get_index(int row, int height) const;
};

} // namespace ray

#endif /* RAY_CANVAS_HPP */
