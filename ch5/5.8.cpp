// no code
// when #if > #else
// there is ambiguity about how to match particular else to particular if
// In C++ the ambiguity is resolved by specifying that each else is matched with
// the closest preceding unmatched if.