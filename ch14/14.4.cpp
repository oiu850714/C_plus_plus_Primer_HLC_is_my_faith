% ;
// arithmetic and symmetric(see Primer p. 555), defined as nonmember
%= ;
// compound assignment, "ought" to be member
++;
// change object state, defined as member
->;
// must be member
<< ;
// if used for output, it must be nonmember because lhs is stream type
&&;
// arithmetic and symmetric, defined as nonmember
== ;
// relational and symmetric, defined as nonmember
();
// must be member