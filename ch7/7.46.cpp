//(a) A class must provide at least one constructor.
// Nntrue, if we don't provide any constructor, compiler will automatically
// provide synthesized default constructor

//(b) A default constructor is a constructor with an empty parameter list.
// Not really, a constructor with an non empty parameter list with all
// parameters given a default initializer is default constructor

//(c) If there are no meaningful default values for a class, the class should
// not provide a default constructor.
// in practice it's not true

//(d) If a class does not define a default
// constructor, the compiler generates one that initializes each data member to
// the default value of its associated type.
// untrue, if class provide any constructor, the compiler will not provide
// synthesized default constructor