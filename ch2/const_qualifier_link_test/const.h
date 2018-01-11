extern const int c;

/*
 * 傳統作法是，
 * 某個const，很多 .cpp 都會用到，
 * 那我就寫一個 header 來 extern const 這個變數
 * 然後所有 include 這個 header 的 .cpp，只會有一份有 definition(Primer 說這個
 * definition 也要加 extern) 這樣編譯那些 .cpp 要 link 的時候，就只會存在一份
 * definition
 */