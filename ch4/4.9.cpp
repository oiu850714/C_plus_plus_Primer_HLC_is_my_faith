int main()

{
  const char *cp = "Hello World";
  if (cp && *cp)
    ;
  // if first check whether cp points to a valid object,
  // only if cp points to a valid object dose cp get dereferenced
}