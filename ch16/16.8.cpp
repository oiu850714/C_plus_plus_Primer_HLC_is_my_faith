// Because all iterator types support operator!=, but only RandomAccessIterator
// supports operator<.
// By routinely using iterators and !=, we don’t have to worry about the precise
// type of container we’re processing.