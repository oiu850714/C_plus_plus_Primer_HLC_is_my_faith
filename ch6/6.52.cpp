void manip(int, int);
double dobj;

int main() {
  //(a)
  manip('a', 'z'); // promotion, rank 3
  //(b)
  manip(55.4, dobj); // conversion, rank 4
}