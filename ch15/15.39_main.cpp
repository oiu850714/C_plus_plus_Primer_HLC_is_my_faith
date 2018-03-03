// compile command: $(CXX) 15.39_main.cpp 15.39.cpp ../ch12/12.33/12.33.cpp

#include "15.39.h"
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {

  Query q = Query("fiery") & Query("bird") | Query("//");
  std::cout << q.rep() << std::endl;
  // assume provide filename and file open success
  std::ifstream is(argv[1]);
  TextQuery tq(is);

  auto result = q.eval(tq);
  print(std::cout, result);
}