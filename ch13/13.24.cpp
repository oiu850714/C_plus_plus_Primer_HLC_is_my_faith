// if using synthesized destructor: memory leak
// if using synthesized copy constructor: HasPtr will behave like pointer type
// LOL, that is, the new object's underlying pointer will point to the same data
// of the old object.