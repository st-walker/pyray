#include "canvas.hpp"

namespace ray {

void Canvas::set_pixel(int x, int y, Colour colour) {
  auto index = get_index(x, y);
  pixels.at(index) = colour;
}

Colour Canvas::get_pixel(int x, int y) const {
  return pixels.at(get_index(x, y));
}

int Canvas::get_index(int x, int y) const { return width_ * y + x; }

} // namespace ray
