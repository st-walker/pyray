#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "canvas.hpp"

using namespace testing;
using namespace ray;

TEST(Canvas, Construction) {
  Canvas canvas(10, 20);

  ASSERT_THAT(canvas.width(), Eq(10));
  ASSERT_THAT(canvas.height(), Eq(20));

  Colour black(0, 0, 0);
  for (const auto& pixel: canvas) {
    ASSERT_THAT(black, Eq(pixel));
  }
}

TEST(Canvas, CanvasColouring) {
  Canvas canvas(10, 20);
  Colour colour(1, 0.5, 0.5);

  canvas.set_pixel(5, 10, colour);
  auto got_colour = canvas.get_pixel(5, 10);

  ASSERT_THAT(colour, Eq(got_colour));
}
