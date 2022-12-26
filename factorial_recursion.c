/*******************************************************************************
*
* Program: Calculate Factorial Using Recursion
* 
* Description: Program to calculate the factorial of a number using recursion 
* with C.  Factorial numbers: https://en.wikipedia.org/wiki/Factorial
*
* YouTube Lesson: https://www.youtube.com/watch?v=6-XfbfZmOqc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// The factorial of a non-negative integer n is the product of all non-negative 
// integers less than or equal to n.  We express a factorial as n!
// 
// So some example factorials for 3!, 5! and *8!...
//
// 3! = 3 * 2 * 1 = 6
//
// 5! = 5 * 4 * 3 * 2 * 1 = 120
//
// 8! = 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1 = 40,320
//
// And in general we have this pattern to compute a factorial...
//
// n! = n * (n - 1) * (n - 2) * ... * 2 * 1
//
// Factorials of the non-negative integers from 1 ... 21
//
// 1! = 1
// 2! = 2
// 3! = 6
// 4! = 24
// 5! = 120
// 6! = 720
// 7! = 5040
// 8! = 40320
// 9! = 362880
// 10! = 3628800
// 11! = 39916800
// 12! = 479001600
// 13! = 6227020800
// 14! = 87178291200
// 15! = 1307674368000
// 16! = 20922789888000
// 17! = 355687428096000
// 18! = 6402373705728000
// 19! = 121645100408832000
// 20! = 2432902008176640000
// 21! = 51090942171709440000
// 22! = 1124000727777607680000

#include <stdio.h>

int factorial(int n);

int main(void)
{
  // Call the function to find the factorial of the integers from 1 ... 30
  for (int i = 1; i <= 30; i++)
    printf("factorial(%d) = %d\n", i, factorial(i));
  
  return 0;
}

// Returns the factorial of n using recursion, see explanation below
int factorial(int n)
{
  if (n == 1) return 1;
  else return n * factorial(n-1);
}

// A recursive solution to a problem will have a function that calls itself,
// and generally the function will have a 'recursive case' (i.e. recursive
// step) and a 'base case' (i.e. base step).  The function will generally 
// call itself with a smaller version of the same problem.  That is exactly
// how the above function works.
//
// We know that 1! is 1 because the only non-negative integer less than or equal
// to 1 is 1 and so 1! = 1.  We now 'know' that factorial(1) = 1 and so we have 
// the function return 1 if n == 1.  This is our function's base case where 
// recursion will stop.
//
// If we look at the factorials of these numbers we see a pattern:
//
// 1! = 1 
// 2! = 2 * 1
// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2  1
//
// The factorial of a number is that number multiplied by the factorial of the 
// "previous number" (i.e. the number one less than the number).  Because 
//
// 4! = 4 * 3! where 3! = 3 * 2 * 1
//
// And so for our recursive step, when n != 1, the function multiplies the 
// number n by the result of calling itself with n-1!  Eventually recursion 
// will stop when n reaches 1.

// The int type in C can only store positive integers up to a certain range, 
// and the factorial of even "small" numbers like 15 is very large.  At a 
// certain point you may notice that the factorial function fails to return 
// the correct result!  This is because the numbers required are outside the 
// range of the int type.  For me the program failed when n == 13.
//
// The type size_t is able to store much larger non-negative integers, and a 
// version of the program above is given below that uses size_t instead.  You 
// will find that this function all fails to produce the correct result at 
// a certain point, because even size_t cannot store numbers large enough.  
// For me the program failed when n == 21.

/*

#include <stdio.h>

size_t factorial(size_t n);

int main(void)
{
  for (size_t i = 1; i <= 30; i++)
    printf("factorial(%zu) = %zu\n", i, factorial(i));
  
  return 0;
}

size_t factorial(size_t n)
{
  if (n == 1) return 1;
  else return n * factorial(n-1);
}

*/