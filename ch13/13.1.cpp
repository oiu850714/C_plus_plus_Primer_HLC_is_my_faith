// constrcutor, 第一個參數是 reference to class, 之後的參數如果有的話都有
// default value 當你做 copy initailization 一個 class object, 或者傳遞 object/
// return object 時，都會使用到 copy constructor；對 array/aggregate class 做
// brace initialization 時 array/aggregate class 的 element 也會用到 copy
// constructor；還有就是一些標準定義的 function 也會使用 copy constructor
// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch13#exercise-131