// If call by value, save and remove will change the copy(by using addMsg and
// remMsg), not the original, so it must pass by reference.
// And addMsg and remMsg in theory will change Folder object, so reference
// cannot be const