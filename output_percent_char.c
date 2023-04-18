/*******************************************************************************
*
* Program: Output The % Percent Character With printf()
* 
* Description: Demonstration of how to output the % percent character in C 
* using printf(), fprintf(), sprintf() and related functions.
*
* YouTube Lesson: https://www.youtube.com/watch?v=O8o4M2xYyC0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // Does not print '90%' because % is a special character for printf() normally
  // used for placeholders to output things such as ints with %d or 
  // floating-point numbers with %f.
  printf("average: 90%\n");

  // But if we have %% then printf() will output a % character and we will have
  // that '90%' is output!
  printf("average: 90%%\n");
  
  return 0;
}