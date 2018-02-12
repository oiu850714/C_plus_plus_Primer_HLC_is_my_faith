class Point {};
Point global;
Point foo_bar(Point arg) { // argument arg will call copy cstr
  Point local = arg,
        *heap = new Point(global); // both local and heap will call copy cstr
  *heap = local; // heap will call "copy assignment, not copy cstr"
  Point pa[4] = {local, *heap}; // pa[0], pa[1] will call copy cstr
  return *heap;                 // return value will call copy cstr
}