// When are friends useful? Discuss the pros and cons of using friends.
// friend let nonmember functions that constitute class' interface access class'
// private data members，有時候就很方便
// cons: 你 class 內跟 class 外都要寫一次宣告，增長 code
// 數量；而且這樣就解除封裝，過度濫用的話你的 interface
// 會整個爛掉；如果你有想到更好的方法可以把 nonmember function 變成 member
// function，或者讓 nonmember function 用 class 提供的 setter 或 getter function
// 來存取 private member，這樣的寫法可能都會比直接寫 friend 來的好