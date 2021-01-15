#include <algorithm>
#include <fstream>

#include "ppm.hpp"

namespace ray {

std::string ppm_header(Canvas const &canvas) {
  return fmt::format("P3\n{} {}\n255\n", canvas.width(), canvas.height());
}

std::string ppm_pixel(Colour const &colour, double max_channel) {
  std::string out = fmt::format(
      "{} {} {}", std::clamp(colour.red() * max_channel, 0., max_channel),
      std::clamp(colour.green() * max_channel, 0., max_channel),
      std::clamp(colour.blue() * max_channel, 0., max_channel));
  return out;
}

std::string ppm_body(Canvas const &canvas) {
  std::string result;
  result.reserve((3 * 3 + 2) * canvas.width() * canvas.height() + 1);

  auto current_line_length = 0;
  for (auto piter = std::begin(canvas); piter != std::end(canvas); ++piter) {
    auto pixel = *piter;
    auto pixel_string = ppm_pixel(pixel, 255);
    auto pixel_length = pixel_string.size();

    if (pixel_length + current_line_length > 69) {
      result += '\n';
      current_line_length = 0;
    } else if (piter == std::begin(canvas)) {
      current_line_length += pixel_length;
    } else {
      result += ' ';
      current_line_length += pixel_length + 1;
    }
    result += pixel_string;
  }
  result += '\n';
  result.shrink_to_fit();
  return result;
}

void write_ppm(std::string const &filename, Canvas const &canvas) {
  std::ofstream out(filename);
  out << ppm_header(canvas);
  out << ppm_body(canvas);
}

} // namespace ray
