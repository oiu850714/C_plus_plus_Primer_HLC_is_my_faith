replace(beg, end, old_val, new_val);
// Replace old_val in the range [begin, end) with new_val
replace_if(beg, end, pred, new_val);
// Replace element in the range [begin, end) for which pred returns true with
// new_val
replace_copy(beg, end, dest, old_val, new_val);
// Copies the elements in the range [begin, end) to the range beginning at
// dest, replacing the appearances of old_value by new_val.
replace_copy_if(beg, end, dest, pred, new_val);
// Copies the elements in the range [begin, end) to the range beginning at
// dest, replacing the element for which pred returns true by new_val