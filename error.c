/*******************************************************************************
*
* Program: #error Demonstration
*
* Description: Examples of using the #error preprocessor directive in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=sRMMyE3unZU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// The limits.h library includes an constant INT_MAX defining the largest
// value an int can store... this may be different from one system to the next.
#include <limits.h>

// We can cause a compilation error to occur and provide a message with the
// #error directive like this:
#error ERROR MESSAGE GOES HERE!

// If our program depends on some condition in order to function correctly
// and that condition is verifiable by preprocessor directives at compile-time,
// we can use #error to cause a compilation error when that condition is NOT
// met to prevent our program from compiling but functioning incorrectly.  For
// example here we cause a compilation error to occur if INT_MAX does not
// exceed a threshold value.
#if INT_MAX < 2147483648
  #error INT_MAX Not Large Enough!
#endif

int main()
{


  return 0;
}
