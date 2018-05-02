// refer to:
// https://github.com/Mooophy/Cpp-Primer/blob/master/ch17/ex17_11_12_13.cpp

#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>

// ex 17.11
template <size_t n> class Quiz {
public:
  Quiz() {}
  Quiz(const std::string &str) : answer(str) {}

  friend size_t grade(const Quiz<n> &quiz, const Quiz<n> &ans) {
    size_t ret = 0;
    for (size_t i = 0; i < quiz.answer.size(); i++) {
      ret += (quiz.answer[i] == ans.answer[i]);
    }
    return ret;
  }

  // ex 17.12
  void update_answer(size_t pos, bool ans) {
    answer[answer.size() - 1 - pos] = ans;
  }
  friend std::ostream &operator<<(std::ostream &os, const Quiz<n> &ans) {
    os << "Answer: ";

    // trace bitset in reverse order, because the bit order in bitset is reverse
    // to ctor's bit string you know...
    for (int i = ans.answer.size() - 1; i >= 0; i--) {
      if (ans.answer[i] == true)
        os << "true, ";
      else
        os << "false, ";
    }
    return os;
  }

private:
  std::bitset<n> answer;
};

int main() {
  Quiz<20> quiz_1("11001100110011001100");
  Quiz<20> answer("11110000111100001100");
  std::cout << grade(quiz_1, answer) << std::endl;
  std::cout << answer << std::endl;

  // ex 17.12
  answer.update_answer(10, false);
  std::cout << grade(quiz_1, answer) << std::endl;
  std::cout << answer << std::endl;
}