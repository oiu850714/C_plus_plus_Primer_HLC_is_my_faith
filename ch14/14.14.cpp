// 如果用 += 實作，這時 += 不會額外創造物件，+ 會創造一個物件，兩個 function
// 總共一個物件 如果用 + 實作 +=，+ 會創造一個物件，而 += 會呼叫 +
// 所以也創造一個物件，兩個 function 總共兩個物件。
// SEE:
// https://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the