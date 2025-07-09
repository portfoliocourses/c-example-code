/*******************************************************************************
*
* Program: Power Function
* 
* Description: A power function implementation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Qi1HNFszzZE
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

// Returns the power of the base to the exponent
//
// - Assumes base == 0 and exponent = 0 does not occur but defaults returning 1
//   if this is the case
//
// - Assumes base is an integer and that exponent is a non-negative integer
// 
int power(int base, int exponent)
{
  int result = 1;

  for (int i = 0; i < exponent; i++)
  {
    result *= base; 
  }
  
  return result;
}

int main(void)
{
  // test the function

  // result should be 8
  printf("%d\n", power(2, 3));

  // result should be 0
  printf("%d\n", power(2, 0));

  return 0;
}