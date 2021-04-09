#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "matrix.hpp"

using namespace testing;
using namespace ray;

TEST(Matrix, Assign4D) {
  Matrix<4, 4> m;

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(0, 3) = 4;
  m(1, 0) = 5;
  m(1, 1) = 6;
  m(1, 2) = 7;
  m(1, 3) = 8;
  m(2, 0) = .1;
  m(2, 1) = .2;
  m(2, 2) = .3;
  m(2, 3) = .4;
  m(3, 0) = .5;
  m(3, 1) = .6;
  m(3, 2) = .7;
  m(3, 3) = .8;

  ASSERT_THAT(m(0, 0), Eq(1));
  ASSERT_THAT(m(0, 1), Eq(2));
  ASSERT_THAT(m(0, 2), Eq(3));
  ASSERT_THAT(m(0, 3), Eq(4));
  ASSERT_THAT(m(1, 0), Eq(5));
  ASSERT_THAT(m(1, 1), Eq(6));
  ASSERT_THAT(m(1, 2), Eq(7));
  ASSERT_THAT(m(1, 3), Eq(8));
  ASSERT_THAT(m(2, 0), Eq(.1));
  ASSERT_THAT(m(2, 1), Eq(.2));
  ASSERT_THAT(m(2, 2), Eq(.3));
  ASSERT_THAT(m(2, 3), Eq(.4));
  ASSERT_THAT(m(3, 0), Eq(.5));
  ASSERT_THAT(m(3, 1), Eq(.6));
  ASSERT_THAT(m(3, 2), Eq(.7));
  ASSERT_THAT(m(3, 3), Eq(.8));
}

TEST(Matrix, Assign2D) {
  Matrix<2, 2> m;

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(1, 0) = 3;
  m(1, 1) = 4;

  ASSERT_THAT(m(0, 0), Eq(1));
  ASSERT_THAT(m(0, 1), Eq(2));
  ASSERT_THAT(m(1, 0), Eq(3));
  ASSERT_THAT(m(1, 1), Eq(4));
}

TEST(Matrix, Assign3D) {
  Matrix<3, 3> m;

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 5;
  m(1, 1) = 6;
  m(1, 2) = 7;
  m(2, 0) = .1;
  m(2, 1) = .2;
  m(2, 2) = .3;

  ASSERT_THAT(m(0, 0), Eq(1));
  ASSERT_THAT(m(0, 1), Eq(2));
  ASSERT_THAT(m(0, 2), Eq(3));
  ASSERT_THAT(m(1, 0), Eq(5));
  ASSERT_THAT(m(1, 1), Eq(6));
  ASSERT_THAT(m(1, 2), Eq(7));
  ASSERT_THAT(m(2, 0), Eq(.1));
  ASSERT_THAT(m(2, 1), Eq(.2));
  ASSERT_THAT(m(2, 2), Eq(.3));
}

TEST(Matrix, TestEquality) {
  Matrix<2, 2> m1;
  Matrix<2, 2> m2;

  m1(0, 0) = m2(0, 0) = 1;
  m1(0, 1) = m2(0, 1) = 2;
  m1(1, 0) = m2(1, 0) = 3;
  m1(1, 1) = m2(1, 1) = 4;

  ASSERT_THAT(m1, Eq(m2));
}
