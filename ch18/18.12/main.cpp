// I just package code in Chapter 15 into namespace
// and this main.cpp only use Query class

#include "Query.h"
#include "Quote.h"

#include <iostream>

int main(int argc, char **argv) {
  chapter_15::Query q = chapter_15::Query("Query") & chapter_15::Query("&") |
                        chapter_15::Query("|"); // just find this line
  std::cout << q.rep() << std::endl;
  // assume provide filename and file open success
  std::ifstream is(argv[1]);
  chapter_15::TextQuery tq(is);

  auto result = q.eval(tq);
  print(std::cout, result);
}