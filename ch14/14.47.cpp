struct Integral {
  operator const int(); // conver to const int, may change object's state(it
                        // should not change state though)
  operator int() const; // conver to int, doesn't change object's state
};