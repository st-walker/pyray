#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "colour.hpp"

using namespace testing;
using namespace ray;

TEST(Colour, DefaultConstruction) {
  Colour c;
  ASSERT_THAT(c.red(), Eq(0.0));
  ASSERT_THAT(c.green(), Eq(0.0));
  ASSERT_THAT(c.blue(), Eq(0.0));
}

TEST(Colour, ColourConstruction) {
  Colour c(1, 0.4, 3);

  ASSERT_THAT(c.red(), Eq(1));
  ASSERT_THAT(c.blue(), Eq(0.4));
  ASSERT_THAT(c.green(), Eq(3));
}

TEST(Colour, ColourAddition) {
  Colour c1(1, 0.4, 3);
  Colour c2(0.4, 0.6, 3);

  auto sum = c1 + c2;

  ASSERT_THAT(sum.red(), DoubleEq(1.4));
  ASSERT_THAT(sum.green(), DoubleEq(1.0));
  ASSERT_THAT(sum.blue(), DoubleEq(6.0));
}

TEST(Colour, ColourSubtraction) {
  Colour c1(1, 0.4, 3);
  Colour c2(0.4, 0.6, 3);

  auto sub = c1 - c2;

  ASSERT_THAT(sub.red(), DoubleEq(0.6));
  ASSERT_THAT(sub.green(), DoubleEq(-0.2));
  ASSERT_THAT(sub.blue(), DoubleEq(0.0));
}

TEST(Colour, ColourScale) {
  Colour c1(1, 0.4, 3);

  auto scale1 = c1 * 2;
  auto scale2 = 2 * c1;

  ASSERT_THAT(scale1.red(), DoubleEq(2));
  ASSERT_THAT(scale1.blue(), DoubleEq(0.8));
  ASSERT_THAT(scale1.green(), DoubleEq(6));

  ASSERT_THAT(scale2.red(), DoubleEq(2));
  ASSERT_THAT(scale2.blue(), DoubleEq(0.8));
  ASSERT_THAT(scale2.green(), DoubleEq(6));
}

TEST(Colour, Equality) {
  Colour c1(1, 0.4, 3);
  Colour c2(1, 0.4, 3);

  ASSERT_THAT(c1, Eq(c2));
}
