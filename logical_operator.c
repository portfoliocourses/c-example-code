/*******************************************************************************
*
* Program: Logical operator tutorial
* 
* Description: Examples of logical operators in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=r0OuA1Q8jOo
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// Logical operator truth tables tell us what operands produce what value
//
// or operator
//
// X      Y      X || Y    
// True   True   True
// True   False  True
// False  True   True
// False  False  False
//
//
// and operator
//
// X      Y      X && Y
// True   True   True
// True   False  False
// False  True   False
// False  False  False
//
//
// not operator
//
// X      !X
// True   False
// False  True
//

int main(void)
{
  // try playing around with these values to see the effect it has on the output
  int year = 2020;
  int price = 19000;

  // and operator example
  if (year >= 2019 && price <= 20000)
    printf("OK!\n");
  else 
    printf("Not OK!\n");

  // or operator example
  if (year >= 2019 || price <= 20000)
    printf("OK!\n");
  else 
    printf("Not OK!\n");

  // not operator example
  if (!(year <= 2019)) printf("OK!\n");
  else printf("Not OK!\n");

  return 0;
}



