char *init(int ht, int wd = 80, char bckgrnd = ' ');
//(a)
init(); // illegal: init shoud be given at least one argument
//(b)
init(24, 10); // legal
//(c)
init(14, '*'); // legal, but wd will be given the '*'s numeric value, which may
               // not be the programmer's intent
               // it should be: init(14, 80, '*');