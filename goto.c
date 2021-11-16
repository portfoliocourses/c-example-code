/*******************************************************************************
*
* Program: Goto Statement Tutorial
* 
* Description: Example of using the goto statement in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Vg0R2UeYMkw  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  printf("Statement 1\n");
  
  // execution of the program will jump to the end label below!
  goto end;
  
  printf("Statement 2\n");
  
  end:
  
  printf("Statement 3\n");
  
  // Generally speaking, we should never use goto statements in our code.  But 
  // there are some people that argue they can be useful in some specific 
  // circumstances, see: https://softwareengineering.stackexchange.com/q/566
  // 
  // So there is an argument that it is more pragmatic to just use a goto to 
  // break out of many nested loops, such as below, because using the break 
  // statement will only break execution out of one loop but not all of them.
  //
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      for (int k = 0; k < 5; k++)
      {
        k++;
        if (k == 5)
        {
          printf("goto statement jumping\n");
          goto end_loop;
        }
      }
  
  end_loop:
  
  printf("The End\n");
  
  return 0;
}
