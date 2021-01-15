#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <fmt/core.h>

#include "canvas.hpp"
#include "ppm.hpp"

using namespace testing;
using namespace ray;

TEST(PPM, HeaderConstruction) {
  Canvas c(10, 20);
  std::string expected = fmt::format("P3\n{} {}\n255\n", 10, 20);
  ASSERT_THAT(ppm_header(c), StrEq(expected));
}

TEST(PPM, PixelToString) {
  auto p1 = ppm_pixel(Colour(-0.5, 0, 0), 255);
  auto p2 = ppm_pixel(Colour(1.5, 0, 1.5), 255);
  auto p3 = ppm_pixel(Colour(1.0, -0.5, 0), 255);
  ASSERT_THAT(p1, StrEq("0 0 0"));
  ASSERT_THAT(p2, StrEq("255 0 255"));
  ASSERT_THAT(p3, StrEq("255 0 0"));
}

TEST(PPM, BodyConstruction) {
  Canvas c(2, 2);
  Colour c1(1.5, 0, 0);
  Colour c2(0, 0.5, 0);

  c.set_pixel(0, 0, c1);
  c.set_pixel(1, 1, c2);

  auto body_string = ppm_body(c);
  ASSERT_THAT(body_string, StrEq("255 0 0 0 0 0 0 0 0 0 127.5 0\n"));
}

TEST(PPM, LineBreaking) {
  Canvas c(6, 1);
  Colour c1(1, 1, 1);
  for (auto &pixel : c)
    pixel = c1;

  auto body_string = ppm_body(c);
  // Long line is broken, body ends with newline.:
  ASSERT_THAT(body_string, StrEq("255 255 255 255 255 255 255 255 255 255 255 "
                                 "255 255 255 255\n255 255 255\n"));
}
