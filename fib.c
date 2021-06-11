/*******************************************************************************
*
* Program: Fibonacci sequence
* 
* Description: An example of how to compute the Fibonacci sequence both 
* iteratively and recursively.
*
* YouTube Lesson: https://www.youtube.com/watch?v=07rT0g_N5eY
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

/*
  Fibonacci sequence: the sequence of 
  numbers created by the sum of the two
  previous numbers, starting with 0 
  and 1.

  F_0 = 0
  F_1 = 1
  F_2 = 1
  F_3 = 2
  F_4 = 3
  F_5 = 5

  Sequence: 0, 1, 1, 2, 3, 5, 8, 13, ...

  Fib_n = Fib_n-1 + Fib_n-2
  F_0 = 0
  F_1 = 1
  F_2 = 1 + 0 = 1

*/

int fib(int n);

int main(void)
{
  // term1 and term 2 represent previous terms in the sequence
  int term1 = 0;
  int term2 = 1;

  // fibn represents the current term in the sequence 
  int fibn = 0;

  // the length of the sequence to compute
  int length = 0;

  // ask the user for a length >= 3 of the sequence to compute
  do 
  {
    printf("Enter sequence length: ");
    scanf("%d", &length);
    if (length < 3)
      printf("Length must be >=3\n");
  } while (length < 3);

  printf("\nIterative solution\n");
  printf("%d,%d,", term1, term2);
  for (int i = 2; i < length; i++)
  {
    // compute the current number in the sequence using the previous terms
    fibn = term1 + term2;
    printf("%d", fibn);

    // update term1 and term2 which represent the previous two terms
    term1 = term2;
    term2 = fibn;

    // print out the list separated by characters, except the last number
    if ( i != (length - 1)) printf(",");
    else printf("\n");
  }

  printf("\nRecursive solution\n");
  for (int i = 0; i < length; i++)
  {
    // each number in the sequence is computed individually
    printf("%d", fib(i));

    // print out the list separated by characters, except the last number   
    if ( i != (length - 1)) printf(",");
    else printf("\n");  
  }

  return 0;
}

// Computes the nth Fibonacci number recursively by calling itself to find 
// the two previous numbers in the sequence (except base cases 0 and 1 where 
// recursion will stop.
int fib(int n)
{
  if (n > 1) return fib(n-1) + fib(n-2);
  else if (n == 1) return 1;
  else if (n == 0) return 0;
  else 
  {
    printf("Error: n must be >= 0\n");
    return -1;
  }
}
