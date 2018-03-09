// dunno...
// it seems compiler will inline "delete ptr;" in the unique_ptr's dtor and
// members that will call deleter
class DebugDelete {
  std::ostream &os;

public:
  DebugDelete(std::ostream &io = std::cerr) : os(io) {}
  template <class T> void operator()(T *ptr) {
    os << "DebugDelete!!!";
    delete ptr;
  }
};