// 三次呼叫 f 的結果都會不一樣，因為宣告 b 跟 c 時會使用到 copy
// constructor，所以 a, b, c 內的 unique serial number 就會不同；而將 a, b, c
// 傳入 f 時，f 的 parameter 又會呼叫 copy constructor，又得到額外三個不同的
// numbered objects，這三個 objects 的 unique serial number 也都不一樣，而且跟
// a, b, c 的也不一樣