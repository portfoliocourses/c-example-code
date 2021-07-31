/*******************************************************************************
*
* Program: Ternary operator example
* 
* Description: Examples of how to use the ternary operator in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int a = 5;
  int b = 5;
  int c = 0;

  // we could use an if-else to determine what assignment to make
  // if (a == b) c = 10;
  // else c = 5;

  // or we could use a ternary operator, which checks the boolean expression 
  // preceeding the ? and then returns 5 if it is true and 10 if it is false
  c = ( a == b ) ? 5 : 10;

  printf("c: %d\n", c);

  int result = 0;

  // We can use a ternary operator in the middle of an expression such as this!
  result = 10 * ((a == c) ? 2 : 1);

  printf("result: %d\n", result);
 
  return 0;
}


