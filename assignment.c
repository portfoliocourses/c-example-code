/*******************************************************************************
*
* Program: Assignment operator examples
* 
* Description: Examples of how to use assignment operators in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int a;

  // standard assignmen operator assigns 5 to a
  a = 5;
  printf("a: %d\n", a);
 
  // adds 2 to a
  a += 2;
  printf("a: %d\n", a);
  
  // subtracts 2 from a
  a -= 2;
  printf("a: %d\n", a);

  // multiples a by 2
  a *= 2;
  printf("a: %d\n", a);
  
  // divides a by 2
  a /= 2;
  printf("a: %d\n", a);

  // sets a to the remainder of a divided by 2
  a %= 2;
  printf("a: %d\n", a);

  return 0;
}
