// Because first_free points to the position after the last element, so object
// should be constructed at position pointed by first_free.
// If using prefix++, object will be constructed at position after the old
// first_free.

// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch13#exercise-1341
// ,which has an illustration