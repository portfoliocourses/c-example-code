/*******************************************************************************
*
* Program: Rounding functions demonstration
* 
* Description: Examples of using double value rounding functions in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=FixR9aiVsy4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main(void) 
{
  // try different numbers like -3.5, 3.49, 3.9, 3.1 to see different behaviours
  double x = 3.5;
  
  // round will round away from 0 if the fractional component is .5 or higher
  // so 3.5 will round to 4, and -3.5 rounds to -4.0 because it rounds *away* 
  // from 0!
  printf("round(%.2f) = %.2f\n", x, round(x) );

  // ceil will always round to the next highest integer
  // so 3.5 will round to 4, and -3.5 rounds to -3.0 because -3.0 *is* the next
  // "highest" integer!
  printf("ceil(%.2f) = %.2f\n", x, ceil(x) );

  // floor will always round to the next lowest integer
  // so 3.5 will round to 3, and -3.5 rounds to -4.0 because -4.0 *is* the next 
  // "lowest" integer!
  printf("floor(%.2f) = %.2f\n", x, floor(x) );
  
  // trunc essentially chops off the fractional component and sets it to .0
  // so 3.5 rounds to 3, and -3.5 rounds to -3.0
  // we can say that trunc always rounds *towards* 0!
  printf("trunc(%.2f) = %.2f\n", x, trunc(x) );

  return 0;
}