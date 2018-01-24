
//(a)
int ff(int a, int b = 0, int c = 0); // legal
//(b)
char *init(int ht = 24, int wd, char bckgrnd); // illegal: when give ht defalut
                                               // argument, all parameters after
                                               // ht must have default argument