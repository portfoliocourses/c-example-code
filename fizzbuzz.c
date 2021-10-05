/*******************************************************************************
*
* Program: Fizz Buzz Solution
* 
* Description: Example of solving the Fizz Buzz problem in C.
*
* Fizz Buzz Wikipedia article - https://en.wikipedia.org/wiki/Fizz_buzz
*
* YouTube Lesson: https://www.youtube.com/watch?v=qeAwnZ5xQAU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  // output the fizz buzz sequence from 1 to 100
  for (int i = 1; i <= 100; i++)
  {
    // output Fizz Buzz if the number is divisible by 3 AND 5
    if ( (i % 3 == 0) && (i % 5 == 0) )
      printf("Fizz Buzz\n");    
    // output Fizz if the number is divisible by 3
    else if (i % 3 == 0)
      printf("Fizz\n");
    // output Buzz if the number is divisible by 5
    else if (i % 5 == 0)
      printf("Buzz\n");
    // otherwise output the number
    else
      printf("%d\n", i);
  }
  
  return 0;
}

// The Fizz Buzz sequence from 1 - 17:
//
//  1
//  2
//  Fizz       (3 % 3 == 0)
//  4
//  Buzz       (5 % 5 == 0)
//  Fizz       (6 % 3 == 0)
//  7
//  8
//  Fizz       (9 % 3 == 0)
//  Buzz       (10 % 5 == 0)
//  11
//  Fizz       (12 % 3 == 0)
//  13
//  14
//  Fizz Buzz  (15 % 3 == 0 AND 15 % 5 == 0)
//  16
//  17
//  ...
