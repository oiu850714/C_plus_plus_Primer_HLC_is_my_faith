// 如果 f 參數是 const numbered &，那 a, b, c 傳入 f 時就不會再呼叫 copy
// constructor，但是呼叫三次 f 印出來的值都會不一樣，不過他們就是 a, b, c 各自的
// unique serial number