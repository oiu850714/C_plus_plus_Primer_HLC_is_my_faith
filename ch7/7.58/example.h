#include <vector>
class Example {
public:
  // static double rate = 6.5; // need constexpr
  static constexpr double rate = 6.5;

  static const int vecSize = 20;
  static std::vector<double> vec; // cannot provide in-class initializer here
};