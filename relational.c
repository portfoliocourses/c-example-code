/*******************************************************************************
*
* Program: Relational operator examples
* 
* Description: Examples of relational operators in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // we can test out the relational operators by modifying a and b, the operator
  // will return 0 (false) or 1 (true)
  int a = 5;
  int b = 5;

  // equality check
  printf("%d == %d -> %d\n", a, b, a == b);

  // does not equal comparison
  printf("%d != %d -> %d\n", a, b, a != b);

  // greater than
  printf("%d > %d -> %d\n", a, b, a > b);

  // greater than or equal to
  printf("%d >= %d -> %d\n", a, b, a >= b);

  // less than 
  printf("%d < %d -> %d\n", a, b, a < b);

  // less than or equal to
  printf("%d <= %d -> %d\n", a, b, a <= b);

  // a practical/common use for relational operators is as part of a 
  // condition in an if-statement or while loop
  if (a > b) printf("Something\n");
  else printf("Something else!\n");

  return 0;
}
