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
  /*7.28: return plain object*/ inline Screen move(pos r, pos c);
  inline Screen &set(char ch) {
    contents[cursor] = ch;
    return *this;
  }
  /*7.28: return plain object*/ inline Screen set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
  }
  /*7.28: return plain object*/ inline Screen display(std::ostream &os) {
    do_display(os);
    return *this;
  }
  /*7.28: return plain object*/ inline const Screen
  display(std::ostream &os) const {
    do_display(os);
    return *this;
  }

private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  void do_display(std::ostream &os) const { os << contents; }
};

/*7.28: return plain object*/ inline Screen
Screen::move(pos r,
             pos c) {  // we can specify inline on the definition
  pos row = r * width; // compute the row location
  cursor = row + c;    // move cursor to the column within that row
  return *this;
  // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const // declared as inlinein the class
{
  pos row = r * width;      // compute row location
  return contents[row + c]; // return character at a given column
}

using std::cout;

int main() {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(cout);
  cout << "\n";
  myScreen.display(cout); // 7.28: this line will print contents with 5*5 'X'
  cout << "\n";
}