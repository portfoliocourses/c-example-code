/*******************************************************************************
*
* Program: If statement tutorial
* 
* Description: Examples of if-statements in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Qoq7-GKSEz0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // try modifying the value of x and see the result!
  int x = 4;

  // if statement example complete with else if and else cases!
  if (x == 2)
  {
    printf("x is equal to 2!\n");
  }
  else if (x == 3)
  {
    printf("x is equal to 3!\n");
  }
  else if (x == 4) printf("x equals 4!\n");
  else 
  {
    printf("x does not equal 2 or 3!\n");
  }

  // control flow will continue down here once one of the branches of the 
  // if-statement has completed executing
  printf("first if done!\n");

  printf("\n\n");

  // Another example if-statement with < operator
  if (x < 4) printf("1st cond!\n");
  else if (x < 5) printf("2nd cond!\n");
  else if (x < 6) printf("3rd cond!\n");
  else if (x < 7) printf("4th cond!\n");
  else printf("else case!\n");

  printf("second if done!\n");

  return 0;
}
