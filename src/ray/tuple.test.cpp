#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "tuple.hpp"

using namespace testing;
using namespace ray;

TEST(Tuple, PointConstruction) {
  Tuple t(4.3, -4.2, 3.1, 1.0);
  ASSERT_THAT(t.x(), Eq(4.3));
  ASSERT_THAT(t.y(), Eq(-4.2));
  ASSERT_THAT(t.z(), Eq(3.1));
  ASSERT_THAT(t.w(), Eq(1.0));

  ASSERT_TRUE(t.is_point());
  ASSERT_FALSE(t.is_vector());
}

TEST(Tuple, VectorConstruction) {
  Tuple t(4.3, -4.2, 3.1, 0.0);
  ASSERT_THAT(t.x(), Eq(4.3));
  ASSERT_THAT(t.y(), Eq(-4.2));
  ASSERT_THAT(t.z(), Eq(3.1));
  ASSERT_THAT(t.w(), Eq(0.0));

  ASSERT_TRUE(t.is_vector());
  ASSERT_FALSE(t.is_point());
}

TEST(Tuple, PointFactoryFunction) {
  auto p = Tuple::point(0, 1, 2);
  Tuple t(0, 1, 2, 1.0);

  ASSERT_THAT(p, Eq(t));
}

TEST(Tuple, VectorFactoryFunction) {
  auto v = Tuple::vector(0, 1, 2);
  Tuple t(0, 1, 2, 0.0);

  ASSERT_THAT(v, Eq(t));
}

TEST(Tuple, Addition) {
  auto p = Tuple(0, 1, 2, 1);
  auto v = Tuple(1, 2, -1, 0);
  auto sum = p + v;
  ASSERT_THAT(sum, Eq(Tuple(1, 3, 1, 1)));
}

TEST(Tuple, Subtraction) {
  auto p = Tuple(0, 1, 2, 1);
  auto v = Tuple(1, 2, -1, 0);
  auto sub = p - v;
  ASSERT_THAT(sub, Eq(Tuple(-1, -1, 3, 1)));
}

TEST(Tuple, Negation) {
  auto p = Tuple(0, 1, 2, 1);
  auto negation = -p;
  ASSERT_THAT(negation, Eq(Tuple(0, -1, -2, -1)));
}

TEST(Tuple, ScalePreMultiply) {
  auto p = Tuple(0, 1, 2, 1);
  auto scaled = 5 * p;
  ASSERT_THAT(scaled, Eq(Tuple(0, 5, 10, 5)));
}

TEST(Tuple, ScalePostMultiply) {
  auto p = Tuple(0, 1, 2, 1);
  auto scaled = p * 5;
  ASSERT_THAT(scaled, Eq(Tuple(0, 5, 10, 5)));
}

TEST(Tuple, ScalePostDivide) {
  auto p = Tuple(0, 1, 2, 1);
  auto scaled = p / 2;
  ASSERT_THAT(scaled, Eq(Tuple(0, 0.5, 1, 0.5)));
}

TEST(Tuple, Magnitude) {
  auto v = Tuple::vector(1, 1, 2);
  ASSERT_THAT(magnitude(v), DoubleEq(std::sqrt(6)));
}

TEST(Tuple, Unit) {
  auto v = Tuple::vector(1, 1, 2);
  auto u = unit(v);
  auto mag = magnitude(v);
  ASSERT_THAT(u.x(), DoubleEq(v.x() / mag));
  ASSERT_THAT(u.y(), DoubleEq(v.y() / mag));
  ASSERT_THAT(u.z(), DoubleEq(v.z() / mag));
  ASSERT_THAT(u.w(), DoubleEq(v.w() / mag));
  ASSERT_THAT(magnitude(u), DoubleEq(1));
}

TEST(Tuple, DotProduct) {
  Tuple t1(1, 2, -1, 1);
  Tuple t2(0, 1, -1, 0);

  auto t1t2 = dot(t1, t2);

  ASSERT_THAT(t1t2, Eq(3));
}

TEST(Tuple, CrossProduct) {
  auto v1 = Tuple::vector(1, 2, 3);
  auto v2 = Tuple::vector(3, 4, 5);

  auto v1v2 = cross(v1, v2);

  ASSERT_THAT(v1v2, Eq(Tuple::vector(-2, 4, -2)));
}
