/*******************************************************************************
*
* Program: Break and continue tutorial
* 
* Description: Examples of using break and continue in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=02ZCvvC2GME
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int i = 0;

  printf("loop start\n");

  // normall the loop will print numbers from 1-10
  while (i < 10)
  {
    i++;

    // when i is 5, the continue statement will skip over the rest of the loop
    // body, and so i: 5 will never print!  uncomment the line to see the
    // effect
    // if (i == 5) continue;

    printf("i: %d\n", i);
    
    // when i is 5, the break statement will execute, causing the execution 
    // of the loop to termine.  uncomment the line to see the effect
    // if (i == 5) break;

  }

  printf("loop end\n");

  return 0;
}
