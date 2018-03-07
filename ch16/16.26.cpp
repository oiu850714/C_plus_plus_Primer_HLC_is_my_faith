// No, because all members of vector<NoDefault>, including
// vector<NoDefault>::vector() which use NoDefault's default constructor which
// doesn't exist, are instantiated when we explicitly instantiate
// vector<NoDefault>

// Or SEE:
// https://stackoverflow.com/questions/21525169/while-explicitly-instantiating-vectorsometype-what-is-the-sometype-default-co