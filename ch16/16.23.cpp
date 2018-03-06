// SEE:
// https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch16/16.23.md

// My answer(based on my code)
// When you type "q", runQueries will exit and TextQuery object tq will be
// destroyed, which caused data pointed by shared_ptr be deleted using
// DebugDelete.