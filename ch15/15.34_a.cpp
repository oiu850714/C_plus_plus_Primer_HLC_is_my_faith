// Query q   =   Query("fiery")    &   Query("bird")    |   Query("wind");
//               ^Query("fiery")       ^Query("bird")
//               ^WordQuery("fiery")   ^WordQuery("bird")
//               Query(string) calls WordQuery(string)
//
//                                 ^AndQuery(lhs, rhs)
//                                 ^BinaryQuery(lhs, rhs)
//                                 ^Query(shared_ptr)
//                          operator& calls AndQuert(lhs, rhs)
//                          which calls BinaryQuery(lhs, rhs);
//                          and operator& returns shared_ptr,
//                          which will be converted to Query object
//
//                                                          ^Query("wind")
//                                                          ^WordQuery("wind")
//                                         Query(string) calls WordQuery(string)
//
//                                                      ^OrQuery(lhs, rhs)
//                                                      ^BinaryQuery(lhs, rhs)
//                                                      ^Query(shared_ptr)
//                                              operator& calls AndQuert(lhs,
//                                              rhs) which calls
//                                              BinaryQuery(lhs, rhs); and
//                                              operator& returns shared_ptr,
//                                              which will be converted to Query
//                                              object
//
//           ^Query(Query&)
//           synthesized copy ctor
//
// this exercise... need to trace code
