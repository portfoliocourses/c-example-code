/*******************************************************************************
*
* Program: Calculate Factorial Using A Loop (i.e. Imperative Solution)
* 
* Description: Program to calculate the factorial of a number using a loop 
* with C.  Factorial numbers: https://en.wikipedia.org/wiki/Factorial
*
* YouTube Lesson: https://www.youtube.com/watch?v=89aAkG68yoM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// The factorial of a non-negative integer n is the product of all positive 
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

size_t factorial(size_t n);

int main(void)
{
  // Call the function to find the factorial of the integers from 1 ... 30
  for (size_t i = 1; i <= 30; i++)
    printf("%zu! = %zu\n", i, factorial(i));
  
  return 0;
}

// Returns the factorial of the integer n using a loop
size_t factorial(size_t n)
{
  // product variable will be used to build the product one multiplication at a 
  // time, we initialize it to 1 because 1 multiplied by a value just give us 
  // back the value
  size_t product = 1;
  
  // The loop has the counter variable go from i to n incrementing by 1 with 
  // each loop iteration i, setting i to exactly the integers needed as part of
  // the factorial calculation.  We take the integer and multiply it by the 
  // current contents of product and store the result back into product so that
  // by the end of the loop product will contain the product of all the values.
  for (size_t i = 1; i <= n; i++)
    product *= i;
  
  // product will now store the calculated factorial so we return this value
  return product;
}

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
