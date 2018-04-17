#include "example.h"
// double Example::rate; // require constexpr declaration, otherwise
// redifinition
double constexpr Example::rate;

std::vector<double> Example::vec(vecSize); // should initialize here