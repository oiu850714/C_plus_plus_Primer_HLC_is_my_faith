// 如果 map 內已經存在給定的 key 的 element，則 insert 不會插入新的 pair，所以
// element 內的 value 不會改變。
// 而如果是用 subscript 且 map 內已經存在給定的 key 的 element，則 element 的
// value 會被覆蓋。
// 所以其實可以用這兩種方式決定你要保留最新的還是最舊的 value。
// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch11#exercise-1135
