#include <iostream>
#include <string>

template <unsigned w, unsigned h> class Screen;

// ex 16.15
template <unsigned w, unsigned h>
std::ostream &operator<<(std ::ostream &os, const Screen<w, h> &s);
template <unsigned w, unsigned h>
std::istream &operator>>(std ::istream &is, Screen<w, h> &s);

template <unsigned w, unsigned h> class Screen {
  friend std::ostream &operator<<<w, h>(std ::ostream &os,
                                        const Screen<w, h> &);
  friend std::istream &operator>><w, h>(std ::istream &is, Screen<w, h> &s);
  // ex 16.15: above friend declarations are one to one friendship

public:
  using pos = typename std::string::size_type;
  Screen() = default;
  Screen(char background = ' ') : pixel_array(w * h, background) {}
  char get() const { return pixel_array[cursor]; }
  char get(pos cur) const { return pixel_array[cur]; }

private:
  pos cursor = 0;
  pos height = h, width = w;
  std::string pixel_array;
};

// ex 16.15
template <unsigned w, unsigned h>
std::ostream &operator<<(std ::ostream &os, const Screen<w, h> &s) {
  for (auto row = 0; row != h; ++row) {
    os << s.pixel_array.substr(row * w, w) << std::endl;
  }
  return os;
}

// ex 16.15
template <unsigned w, unsigned h>
std::istream &operator>>(std ::istream &is, Screen<w, h> &s) {
  char background;
  is >> background;
  pixel_array = std::string(widen * height, background);
  return is;
}

int main() {
  Screen<87, 40> s('8');
  operator<<(std::cout, s);
}