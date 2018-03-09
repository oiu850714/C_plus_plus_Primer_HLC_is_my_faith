// This solution refers to
// https://github.com/Mooophy/Cpp-Primer/blob/master/ch16/ex16.28/delete.hpp

#ifndef _DELETER_H_
#define _DELETER_H_

class Deleter {
public:
  template <typename T> void operator()(T *p) const { delete p; }
};

#endif