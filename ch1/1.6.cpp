// no code
/*
    The following program fragment is illegal:
    std::cout << "The sum of " << v1; << " and " << v2;
              << " is " << v1 + v2 << std::endl;
    Fix:
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
*/