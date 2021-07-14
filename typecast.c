/*******************************************************************************
*
* Program: Type casting
* 
* Description: Example of how to use type casting in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=xKOPZ4mEH3I  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int a = 5;
  int b = 2;

  // a is casted (converted) to a double first because type conversion has 
  // higher precedence than division, then b is implicitly "promoted" to a 
  // double for a division with two doubles to occur
  double c = (double) a / b;
  
  // if both a and b are ints then int division will occur, if as above one of 
  // the operands is a double the other operand will be promoted to a double 
  printf("%d / %d = %d\n", a, b, a / b);

  // in this case we have division between two doubles and so the result is
  // a double
  printf("%d / %d = %f\n", a, b, c);

  // try playing around with the types of x, y and z to see how implicit 
  // promotion of types for operations occurs, including "demotion" when we 
  // assign a double value to an int
  int x = 2;
  double y = 5;

  // here x gets promoted to a double for the operation to take place, but then 
  // we store the result into an int, and so C will implicitly convert the 
  // value to an int to assign it to z
  int z = y / x;

  printf("z: %d\n", z);

  return 0;
}
