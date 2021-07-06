/*******************************************************************************
*
* Program: Do-while loop tutorial
* 
* Description: Example of a do-while loop in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=icMFujbidAA
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  
  int i = 6;

  // Notice how the loop body will be executed once despite the fact that 
  // i is > 5!  That is the core difference with a do-while loop... the loop
  // body always executes once. 
  do 
  {
    printf("i: %d\n", i);
    i++;
  } while (i < 5);
  
  return 0;
}
