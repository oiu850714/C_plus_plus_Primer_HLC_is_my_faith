#include "13.36.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Folder f1, f2;
  Message m1("m1"), m2("m2"), m3("m3");

  cout << "initial:\n";
  cout << "f1:\n";
  f1.print_debug();
  cout << "f2:\n";
  f2.print_debug();

  cout << "m1:\n";
  m1.print_debug();
  cout << "m2:\n";
  m2.print_debug();
  cout << "m3:\n";
  m3.print_debug();

  cout << "save m1 to f1:\n";
  m1.save(f1);
  cout << "f1:\n";
  f1.print_debug();
  cout << "save m2 to f1:\n";
  m2.save(f1);
  cout << "f1:\n";
  f1.print_debug();

  cout << "assign f2 to f1:\n";
  f2 = f1;
  cout << "f2:\n";
  f2.print_debug();

  cout << "remove m1 from f2(change f2 but not f1):\n";

  m1.remove(f2);
  cout << "f1:\n";
  f1.print_debug();
  cout << "f2:\n";
  f2.print_debug();

  cout << "assign m2 to m3\n";
  m3 = m2;
  cout << "m3:\n";
  m3.print_debug();
  cout << "m2:\n";
  m2.print_debug();

  cout << "f1:\n";
  f1.print_debug();
  cout << "f2:\n";
  f2.print_debug();

  cout << "copy construct m4 from m3:\n";
  Message m4(m3);
  cout << "m4:\n";
  m4.print_debug();

  cout << "f1:\n";
  f1.print_debug();
  cout << "f2:\n";
  f2.print_debug();

  {
    cout << "in nested scope:\n";
    cout << "create m5:\n";
    Message m5("m5");
    cout << "m5:\n";
    m5.print_debug();
    cout << "save m5 to f1:\n";
    m5.save(f1);
    cout << "f1:\n";
    f1.print_debug();
    cout << "f2:\n";
    f2.print_debug();
  }
  cout << "exit nested scope:\n";
  cout << "f1:\n";
  f1.print_debug();
  cout << "f2:\n";
  f2.print_debug();
}