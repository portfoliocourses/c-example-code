/*******************************************************************************
*
* Program: Absolute Value Functions abs() And fabs()
*
* Description: Examples of finding the absolute value of a number using the
* abs() and fabs() functions in C.  See the Wikipedia article on absolute
* value: https://en.wikipedia.org/wiki/Absolute_value.
*
* YouTube Lesson: https://www.youtube.com/watch?v=_GTWRamAQ0s
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// We can think of the absolute value of a number as the non-negative value
// of that number, without regard to its sign.  Or we can think of it as the
// "distance" of that number from 0.  The absolute values (denoted by |value|)
// of 5, -5, 0 and -2.5 are given below:
//
// |5| = 5
// |-5| = 5
// |0| = 0
// |-2.5| = 2.5

#include <stdio.h>

// the abs() function is in the stdlib.h library so we must include it to use it
#include <stdlib.h>

// the fabs() function is in the math.h library so we must include it to use it
#include <math.h>

int main(void)
{
  // Declare and initialize an int variable x to -5
  int x = -5;

  // abs() will accept an int value as an argument and return the absolute
  // value of that int, so here we store the absolute value of x returned by
  // abs() into the abs_x varible we have declared
  int abs_x = abs(x);

  // Output the absolute value of x that is stored into the abs_x variable
  printf("abs(x): %d\n", abs_x);


  // Declare and initialize a double variable y to -2.5
  double y = -2.5;

  // fabs() will allow us to find the absolute values of double/float values,
  // as with abs() we pass the number as an argument to the function and the
  // function will return the absolute value of that number.  So here we
  // have fabs() return the absolute value of y and we store it into the
  // fabs_y double type variable we have declared.
  double fabs_y = fabs(y);

  // Output the absolute value of y that is stored in the abs_y variable
  printf("fabs(y): %f\n", fabs_y);

  return 0;
}