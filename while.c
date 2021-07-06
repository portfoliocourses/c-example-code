/*******************************************************************************
*
* Program: While loop tutorial
* 
* Description: Examples of a while loop in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Ceq7Cq1I0sc
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  
  // initialize a counter variable i to 0
  int i = 0;

  // the body of the while loop will keep executing until i < 5 is false!
  while (i < 5)
  {
    // output i
    printf("i: %d\n", i);

    // we increment i, it will eventually become >= 5 this way
    i++; 
  }

  // when the loop has finished executing control flow will continue beneath it
  printf("Loop is over!\n");

  // an indefinite loop, it will run indefinitely until the user enters 5
  i = 0;
  while (i != 5)
  {
    printf("Enter 5 to quit: ");
    scanf("%d", &i);
  }

  // an infinite loop, it will run forever as the condition will never be true
  i = 0;
  while (i < 5)
  {
    printf("i: %d\n", i);
    i--;
  }

  return 0;
}
