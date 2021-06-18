/*******************************************************************************
*
* Program: Recursion tutorial
* 
* Description: Example of using recursion to solve the factorial operation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=STWnc6ZY2fw
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// Recursion is a way of solving a problem where our solution depends on 
// solutions to smaller instances of the same problem
//
// Practically this means we will write functions that call themselves!
//
// Example: factorial problem
//
// The factorial of n denoted by n! is the product of all positive integers <= n 
//
// n! = n * (n-1) * (n-2) ... * 1
//
// 5! = 5 * 4 * 3 * 2 * 1 = 120
//

int factorial(int n);

int main(void)
{
  int n = 0;
  int fact = 1;
  printf("Enter a number: ");
  scanf("%d", &n);

  // iterative solution to computing factorial
  //
  // while (n >= 1)
  // {
  //  fact = n * fact;
  //  n--;
  // }

  // recursive solution

  fact = factorial(n);

  printf("fact: %d\n", fact);

  return 0;
}

// Uses recursion to compute n!
int factorial(int n)
{
  // base case: we stop recursion when n == 1
  if (n == 1) return 1;

  // recursive step: n * factorial(n-1) gives us n * (n - 1) * factorial(n - 2)
  // and on and on until we reach the base step
  return n * factorial(n - 1);
}




