// 自定義的 copy constructor 不能直接呼叫 shared_ptr 的 copy
// constructor；需要先用 make_shared 創造一份 vector<string> 再把要 copy
// 的舊物件指向的 vector<string> copy 到新物件

// copy assignment 類似

// 不用定義 destructor 的原因是，只要正常使用 shared_ptr，他會自己在 reference
// use_count == 0 時 delete 他指向的物件

// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch13#exercise-1325