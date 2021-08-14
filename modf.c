/*******************************************************************************
*
* Program: modf demonstration
* 
* Description: Example of using the modf function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zBQBOSod0e8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main(void) 
{
  double x = 2.75;
  double frac = 0;
  double integral = 0;
  
  // the modf function will store the integral component of the number x into 
  /// integral and return the fractional component (which will be assigned to
  // the varable frac)
  frac = modf(x, &integral);
  
  // frac will be 0.75 and integral will be 2.0
  printf("frac: %f\n", frac);
  printf("integral: %f\n", integral);

  return 0;
}