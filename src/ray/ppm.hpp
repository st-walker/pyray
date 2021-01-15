#ifndef RAY_PPM_HPP
#define RAY_PPM_HPP

#include <string>

#include <fmt/core.h>

#include "canvas.hpp"

namespace ray {

std::string ppm_header(Canvas const &canvas);
std::string ppm_pixel(Colour const &colour, double max_channel);
std::string ppm_body(Canvas const &);
void write_ppm(std::string const &filename, Canvas const &);

} // namespace ray
#endif /* RAY_PPM_HPP */
