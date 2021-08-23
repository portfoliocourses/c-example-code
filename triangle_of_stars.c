/*******************************************************************************
*
* Program: Triangle of stars output example
* 
* Description: Example of outputting a triangle of stars in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=LkmH8etAVWA
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

/*
  
  The below code will output a triangle of stars like this:

  *
  **
  ***
  ****
  *****
  ******
  *******
  ********
  *********
  **********

*/

int main(void) 
{
  // the outer loop will output each line, including the new line character
  for (int i = 1; i <= 10; i++)
  {
    // the inner loop will output the stars on each line... notice how it uses 
    // the counter variable i of the outer loop to determine how many stars 
    // to output, as j is incremented from 1 up until and including i 
    for (int j = 1; j <= i; j++)
    {
      printf("*");
    }
    printf("\n"); 
  }

  return 0;
}
