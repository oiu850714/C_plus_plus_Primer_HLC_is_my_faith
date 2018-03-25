namespace Exercise {
int ivar = 0;
double dvar = 0;
const int limit = 1000;
} // namespace Exercise
int ivar = 0;

void manip() {
  // position 2
  using Exercise::ivar;
  using Exercise::dvar;
  using Exercise::limit;

  double dvar = 3.1416; // this declaration conflicts using declaration using
  // Exercise::dvar
  int iobj = limit + 1; // Exercise::limit
  ++ivar;               // refer to Exercise::ivar
  ++::ivar;             // refer to ivar in global scope
}

int main() {}