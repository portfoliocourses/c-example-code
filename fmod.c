/*******************************************************************************
*
* Program: fmod() function demonstration
* 
* Description: Examples of using the fmod() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=FebH-34EQ30 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main(void) 
{
  double num = 10.4;
  double denom = 3.9;

  // fmod returns the remainder of num divided by denom, like the % modulus 
  // operator but for double values
  double result = fmod(num, denom);
  printf("result: %f\n", result);

  return 0;
}