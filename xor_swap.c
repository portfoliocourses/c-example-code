/*******************************************************************************
*
* Program: Swap Two Variables Without A Temporary Variable
* 
* Description: Swaps two variables without using a temporary variable in C.
* See: https://en.wikipedia.org/wiki/XOR_swap_algorithm
*
* YouTube Lesson: https://www.youtube.com/watch?v=DExMskdAPO4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  int x = 25;
  int y = 35;
  
  // swaps the values of x and y by applying xor bitwise operator, see 
  // explanation for how it works below
  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
  
  // confirm variable values have been swapped
  printf("x: %d, y: %d\n", x, y);
 
  return 0;
}

// Numbers like 25 and 35 are ultimately represented as binary numbers in a 
// computer:
//
//   25 = 00011001
//   35 = 00100011
//
// The XOR operator ^ works on pairs of bits at each index in two numbers, 
// with these rules:
//
//   1 XOR 1 = 0
//   1 XOR 0 = 1
//   0 XOR 1 = 1
//   0 XOR 0 = 0
//
// So for example, 25 XOR 35 results in:
//
//   25 = 00011001
//   35 = 00100011
//  XOR = 00111010
//
//
// How does applying XOR operators in this sequence swap X and Y?  Let's 
// breakdown the algorithm into 3 steps, and keep in mind which bits (x or y 
// bits) may change at each step.
//
//   1) x = x ^ y    - x bits may change
//   2) y = x ^ y    - y bits may change
//   3) x = x ^ y    - x bits may change
//
// Knowing that the XOR operator works on each bit individually in X and Y, 
// let's see the effect of the 4 possible combinations of X and Y values 
// after applying each step of the algorithm:
//
//      X:0  Y:0
//   1) X:0  Y:0
//   2) X:0  Y:0
//   3) X:0  Y:0
//
//      X:1  Y:1
//   1) X:0  Y:1
//   2) X:0  Y:1
//   3) X:1  Y:1
//
//      X:0  Y:1
//   1) X:1  Y:1
//   2) X:1  Y:0
//   3) X:1  Y:0
//
//      X:1  Y:0
//   1) X:1  Y:0
//   2) X:1  Y:1
//   3) X:0  Y:1
//
// In all cases, X and Y end up swapping values (at the level of each bit)! 
// Then applying this to all bits ends up swapping the entire values.


