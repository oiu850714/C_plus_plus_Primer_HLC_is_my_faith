// Same reason for my ex 12.2's remider, it will be legal to add const version's
// push_back and pop_back because they will not change the StrBlob object's
// member. the data it changes is the object that "data" points to.
void push_back(const std::string &t) const { data->push_back(t); }

void StrBlob::pop_back() const {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}
// Logically, however, user code should not push or pop element on a const
// StrBlob object, because by just looking the StrBlob' interface, it seems like
// we can change a const StrBlob object(actually the data object's member points
// to) using push_back and pop_back, it doesn't make sense.
// SEE this:
// https://github.com/Mooophy/Cpp-Primer/tree/master/ch12#exercise-123
