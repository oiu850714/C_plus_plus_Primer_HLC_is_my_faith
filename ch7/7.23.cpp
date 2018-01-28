#include <iostream>
#include <string>
#include <vector>

class Screen {
public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  inline Screen &move(pos r, pos c);

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

inline Screen &Screen::move(pos r,
                            pos c) { // we can specify inline on the definition
  pos row = r * width;               // compute the row location
  cursor = row + c; // move cursor to the column within that row
  return *this;
  // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const // declared as inlinein the class
{
  pos row = r * width;      // compute row location
  return contents[row + c]; // return character at a given column
}

int main() {}