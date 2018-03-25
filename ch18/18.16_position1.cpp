namespace Exercise {
int ivar = 0;
double dvar = 0;
const int limit = 1000;
} // namespace Exercise
int ivar = 0;

// position 1
using Exercise::ivar; // this using declaration conflicts member in current
                      // scope (::ivar)
using Exercise::dvar;
using Exercise::limit;

void manip() {

  double dvar = 3.1416; // mapip::dvar hides Exercise::dvar
  int iobj = limit + 1; // refer to Exercise::limit
  ++ivar;
  ++::ivar; // both are meaningless because the name "ivar" conflicts
}