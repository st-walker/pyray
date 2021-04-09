#ifndef RAY_MATRIX_HPP
#define RAY_MATRIX_HPP

#include <array>
#include <cstddef>
#include <initializer_list>
#include <type_traits>

namespace ray {

// struct idx {
//   std::size_t row
//   std::size_t col;
// }

template <std::size_t rowsize, std::size_t colsize> class Matrix {
public:
  Matrix<std::size_t, std::size_t>() = default;

  double const &operator()(std::size_t row, std::size_t col) const {
    return array_[rowsize * row + col];
  }

  double &operator()(std::size_t row, std::size_t col) {
    return array_[rowsize * row + col];
  }

  template <typename std::size_t rows, std::size_t cols>
  friend bool operator==(Matrix<rows, cols> const &,
                         Matrix<rows, cols> const &);

private:
  std::array<double, rowsize * colsize> array_;
  // size_type row
};

template <typename std::size_t rows, std::size_t cols>
bool operator==(Matrix<rows, cols> const &mat1,
                Matrix<rows, cols> const &mat2) {
  auto it1 = std::begin(mat1.array_);
  auto it2 = std::begin(mat2.array_);

  for (std::size_t i = 0; i < mat1.array_.size(); ++i) {
    if (*it1++ != *it2++)
      return false;
  }
  return true;
}

} // namespace ray

#endif /* RAY_MATRIX_HPP */
