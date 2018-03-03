BinaryQuery a = Query("fiery") & Query("bird");
// illegal because BinaryQuery is abstract base class, cannot define objects

AndQuery b = Query("fiery") & Query("bird");
// illegal operator& return Query object, which cannot be converted to AndQuery

OrQuery c = Query("fiery") & Query("bird");
// illegal operator& return Query object, which cannot be converted to OrQuery
