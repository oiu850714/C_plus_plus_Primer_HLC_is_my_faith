// see 16.29_main.cpp
// note that now we cannot use BlobPtr on Blob, because our SharedPtr cannot
// cooperate with weak_ptr, and Primer says implementing weak_ptr is beyond its
// scope, so you know...