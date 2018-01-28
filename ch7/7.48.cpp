string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn); // explict conversion from string to Sales_data
Sales_data item2("9-999-99999-9"); // one implicit conversion from C string to
                                   // string, and one explicit conversion from
                                   // string to Sales_data, no two consecutive
                                   // implicit conversion, so it's legal
