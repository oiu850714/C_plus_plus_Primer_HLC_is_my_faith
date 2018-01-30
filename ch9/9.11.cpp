#include <string>
#include <vector>

using std::vector;
using std::string;

int main() {
  vector<int> vec1;         // empty container
  vector<int> vec2(94);     // 94 個 0's
  vector<int> vec3(94, 87); // 94 個 87
  vector<string> vec4{"I", "love",
                      "hsilu"}; // 有三個 string，value 是 "I", "love", "hsilu"
  auto vec5(vec4);
  // auto vec6(vec4.begin(), vec4.end());
  vector<string> vec6(vec4.begin(), vec4.end()); // 跟 vec4 一樣
}