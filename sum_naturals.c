/*******************************************************************************
*
* Program: Sum The First N Natural Numbers demonstration
* 
* Description: Example of summing the first N natural numbers using recursion
* in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=6wucO5fbiQo  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int sum(int n);

int main() 
{     
  // Natural numbers: 1, 2, 3, 4, 5, 6, ...
  // Sum of the first two natural numbers:   1 + 2 = 3
  // Sum of the first three natural numbers: (1 + 2) + 3 = 6
  // Sum of the first four natural numbers:  (1 + 2 + 3) + 4 = 10
  //
  // Notice how the solution to the sum of the first 4 natural numbers 
  // effectively contains the solution (in the brackets) to the sum of the 
  // first 3 natural numbers?  We can solve this smaller problem (the sum of
  // the first 3 natural numbers) to help us solve the bigger problem (the sum
  // of the first 4 natural numbers).  And the sum of the first 3 natural 
  // numbers contains the solution (agan in brackets) to the sum of the first 
  // 2 natural numbers.  We'll use recursion to solve smaller subproblems to 
  // help us solve the larger problem!
  
  printf("%d\n", sum(5) );
  
  return 0;
}

// computes the sum of the first n natural numbers recursively
int sum(int n)
{
  // adds the current natural number n to the sum of first n-1 natural numbers
  // so if we pass the function 4 for example, we get this pattern:
  //   sum(4) = 4 + sum(3)
  //          = 4 + 3 + sum(2)
  //          = 4 + 3 + 2 + sum(1)
  //          = 4 + 3 + 2 + 1 + sum(0)
  //          = 4 + 3 + 2 + 1 + 0
  // Once we reach 0 there are no more natural numbers and the recursion should
  // stop.  We call the if case below the 'recursive step' and the else case 
  // below the 'base case'.
  if (n > 0) return n + sum(n-1);
  else return 0;
}
