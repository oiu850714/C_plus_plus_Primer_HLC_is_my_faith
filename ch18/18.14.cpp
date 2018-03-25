namespace mathLib {
namespace MatrixLib {
class matrix { /* ... */
};
matrix operator*(const matrix &, const matrix &);
// ...
} // namespace MatrixLib
} // namespace mathLib

// somthing shitty like this
mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*(const matrix &,
                                                         const matrix &) {
  /* ... */
  return matrix();
}
