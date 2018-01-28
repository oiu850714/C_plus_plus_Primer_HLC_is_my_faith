i.combine(s); // i is Sales_data, s is std::string

//(a)
Sales_data &
    combine(Sales_data); // legal: implicit conversion from string to Sales_data
//(b)
Sales_data &combine(Sales_data &);
// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch07#exercise-749
//(c)
Sales_data &combine(const Sales_data &) const;
// accoring to reference above, it's illegal because the combine cannot be const
// function
