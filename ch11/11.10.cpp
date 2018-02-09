// We can define vector<int>>::iterator as map's key type because it defines
// operator<.
// Instead cannot define list<int>::iterator as map's key type because it
// doesn't define operator<.