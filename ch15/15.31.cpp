//(a)
Query(s1) | Query(s2) & ~Query(s3);
// WordQuery, NotQuery, AndQuery, OrQuery

//(b)
Query(s1) | (Query(s2) & ~Query(s3));
// the same as previous one

//(c)
(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));
// the same as previous one except NotQuery