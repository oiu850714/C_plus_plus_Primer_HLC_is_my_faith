namespace mathLib {
namespace MatrixLib {
class matrix { /* ... */
};
matrix operator*(const matrix &, const matrix &);
// ...
} // namespace MatrixLib
} // namespace mathLib

// somthing shitty like this
auto mathLib::MatrixLib::operator*(const matrix &, const matrix &) -> matrix {
  /* ... */
  return matrix();
}
