// you can refer to:
// https://github.com/Mooophy/Cpp-Primer/blob/master/ch15/ex15.12.13.14/main.cpp

#include <string>

class built_in {
public:
  built_in(const std::string &name) : type_name(name) {}
  virtual void set_value(char *value) = 0;

private:
  std::string type_name;

protected:
  char *value; // allocate memory to store value
};

class Int_32 : public built_in {
public:
  Int_32() : built_in("Int_32") {}
  virtual void set_value(char *value) {
    // blablabla
  }
};

class Int_64 : public built_in {
public:
  Int_64() : built_in("Int_64") {}
  virtual void set_value(char *value) {
    // blablabla
  }
};

class Float : public built_in {
public:
  Float() : built_in("Float") {}
  virtual void set_value(char *value) {
    // blablabla
  }
};

class Double : public built_in {
public:
  Double() : built_in("Double") {}
  virtual void set_value(char *value) {
    // blablabla
  }
};