// 這樣的 constructor 會對自己無限遞迴，而且也無法編譯

class foo {
public:
  foo(foo);
}