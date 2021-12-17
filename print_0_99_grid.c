/*******************************************************************************
*
* Program: Print Numbers 00-99 
* 
* Description: Example of printing the numbers from 00-99 in a 10x10 grid 
* using C.  The numbers with a single digit from 0-9 are output with a single 
* leading zero.
*
* YouTube Lesson: https://www.youtube.com/watch?v=_2MAktbQO5o   
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  // loop will output numbers from 0-99 by increment the counter variable i 
  // from 0 - 99, one number at a time
  int i = 0;
  while (i <= 99)
  {
    // outputs i followed by a space into a 2 character width field with 0 as 
    // a leading digit... has the effect of outputting "09" instead of "9" 
    // when i=9 for example
    printf("%02d ", i);
    
    // increment i by 1
    i++;

    // outputs a newline after every 10th number as i % 10 will be zero when i 
    // is divisible by 10... i.e. i=10,20,30,...
    if (i % 10 == 0) printf("\n");
  }

  return 0;
}