#include <iostream>
int main() {
  // currValis the number we’re counting; we’ll read new values into val
  int currVal = 0, val = 0;
  // read first number and ensure that we have data to process
  if (std::cin >> currVal) {
    int cnt = 1; // store the count for the current value we’re processing
    while (std::cin >> val) { // read the remaining numbers
      if (val == currVal)     // if the values are the same
        ++cnt;
      // add 1 to cnt
      else { // otherwise, print the count for the previous value
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
        currVal = val; // remember the new value cnt = 1;
                       // reset the counter
      }
    }
    // while loop ends here
    // remember to print the count for the last value in the file
    std::cout << currVal << " occurs " << cnt << " times" << std::endl;
  } // outermost if statement ends here
  return 0;
}

/*
 * If the input values are all equal, it will print a line which shows the count
 * of the number you input.
 *
 * If there are no duplicated values, when different values input, a new line
 * will be printed if you click Enter.
 * QUOTE FROM https://github.com/chihyang/CPP_Primer/tree/master/chap01 Exercise
 * 1.17
 */
