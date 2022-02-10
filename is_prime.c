/*******************************************************************************
*
* Program: Determine if a number is prime
* 
* Description: An example of a function for determining whether a number is 
* prime or not.
*
* YouTube Lesson: https://www.youtube.com/watch?v=lAqH2dt7g5I 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int number);

int main(void)
{
  // check the numbers between 2-1000 to see which are prime
  for (int i = 2; i <= 1000; i++)
    if (is_prime(i)) printf("%d is prime\n", i);
    else printf("%d is not prime\n", i);
  
  return 0;
}

// returns true if the number is prime, false otherwise
bool is_prime(int number)
{
  // the number cannot be prime if it is <= 1
  if (number <= 1) return false;
  
  // Check to see if the number has a divisor between 2 ... number/2, if this 
  // is the case the number is NOT prime.  We only need to check up until 
  // number/2 because we can't have a divisor between number/2 + 1 up until 
  // number - 1
  for (int i = 2; i <= (number / 2); i++)
    if (number % i == 0) return false;
  
  // if there was no divisor, the number must be prime and we return true
  return true;
}


// A prime number (or a prime) is a natural number
// greater than 1 that is not a product of two smaller
// natural numbers.
//
// Natural numbers: 1, 2, 3, 4, 5, ...
//
//
//
// Is 6 a prime number?
//
// No.
//
// 2 * 3 = 6   - not a prime number
//
//
//
// What about 7?
//
// Can we multiply any two smaller natural numbers together
// to give us 7?
//
// No.  Only 1 * 7 will give us 7.
//
//
//
// Also:
//
// The divisors of a natural number X are the natural
// numbers that divide X evenly (i.e. without a
// remainder).  Every natural number has both 1 and
// itself as a divisor.  If it has any other divisor,
// it cannot be prime.
//
//
//
// 6
//
// 6 / 1 = 6 remainder 0
// 6 / 2 = 3 remainder 0
// 6 / 3 = 2 remainder 0
// 6 / 4 = 1 remainder 2
// 6 / 5 = 1 remainder 1
// 6 / 6 = 1 remainder 0
//
// 1 * 6 = 6
// 2 * 3 = 6
//
//
//
// 7 (prime)
//
// 7 / 1 = 7 remainder 0
// 7 / 2 = 3 remainder 1
// 7 / 3 = 2 remainder 1
// 7 / 4 = 1 remainder 3
// 7 / 5 = 1 remainder 2
// 7 / 6 = 1 remainder 1
// 7 / 7 = 1 remainder 0
//
// 1 * 7 = 7
//
