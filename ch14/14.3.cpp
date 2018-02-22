//(a)
"cobble" ==
    "stone"; // neither, use built-in == on pointer type, SEE:
             // https://stackoverflow.com/questions/2690737/why-does-the-following-not-invoke-the-overloaded-operator-const-string-con
//(b)
svec1[0] == svec2[0]; // operator(string, string)
//(c)
svec1 == svec2; // operator(vector, vector)
//(d)
svec1[0] == "stone"; // operator(string, string)