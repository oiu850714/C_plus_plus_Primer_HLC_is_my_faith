// What happens when a StrBlob object is destroyed? What about a StrBlobPtr?
// StrBlob's sharad_ptr decrements reference count, deletes object it points to
// if count == 0
// StrBlobPtr's weak_ptr do nothing on object it points to