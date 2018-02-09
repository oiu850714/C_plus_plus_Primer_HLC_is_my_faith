while (cin >> word)
  ++word_count.insert({word, 0}).first->second;
// it always increments the value of the element whose key == word

// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch11#exercise-1121
// https://github.com/huangmingchuan/Cpp_Primer_Answers/tree/master/ch11#%E7%BB%83%E4%B9%A01121