/*******************************************************************************
*
* Program: Find a square root using sqrt() sqrtf() sqrtl()
*
* Description: Examples of using the square root functions sqrt() sqrtf() and
* sqrtl() in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=2CuCMO0bT6s
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
  // sqrt() accepts a double value as an argument and returns the square root
  // of that number as a double
  double result1 = sqrt(9);
  printf("sqrt(9) = %f\n", result1);

  // If we pass sqrt() a negative number we will get back nan (a special value
  // meaning Not A Number), as there are no real square roots of negative
  // numbers.
  double result2 = sqrt(-9);
  printf("sqrt(-9) = %f\n", result2);

  // sqrtf() works like sqrt() except it accepts a float value as an argument
  // and returns a float
  float x1 = 2.0;
  float result3 = sqrtf(x1);
  printf("sqrt(2.0) = %.15f\n", result3);

  // sqrtl() works like sqrt() except it accepts a long double value as an
  // argument and it returns a long double value
  long double x2 = 2.0;
  long double result4 = sqrtl(x2);
  printf("sqrt(2.0) = %.15Lf\n", result4);

  // doubles and long doubles can store numbers of greater range and with more
  // accuracy than floats, so in the last two examples where we output the
  // numbers with 15 decimal digits of precision, we should find that the
  // long double output matches the real result (below) more than the float
  // output...
  //
  //  1.414213562373095

  return 0;
}