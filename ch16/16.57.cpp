// error_msg in 6.2.6 can only print varying number arguments of the same type
// but it's easy to write(can use range for loop to process arguments, more
// straightforward)

// errorMsg can deal with different types of varying number of arguments, but it
// needs variadic template...