/*******************************************************************************
*
* Program: Check If A Number Is Prime Or Not Using Recursion
*
* Description: Functions to check if a number is prime or not using recursion.
*
* YouTube Lesson: https://www.youtube.com/watch?v=BUNzco2GkBA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// Prime numbers are natural numbers greater than 1 divisible only by 1 and the 
// number itself.
//
// A number is divisible by another if the remainder after division is zero.
//
// 5 is a prime number
//
// 5 / 2 = 2 remainder 1
// 5 / 3 = 1 remainder 2
// 5 / 4 = 1 remainder 1
//
// 6 is not a prime number
//
// 6 / 2 = 3 remainder 0
// 6 / 3 = 2 remainder 0
// 6 / 4 = 1 remainder 2
// 6 / 5 = 1 remainder 1
//
// Our recursive functions will check if the number is divisible by any 
// divisor between 1 and the number itself.  Notably, we can stop checking
// for numbers greater than n/2 as it is not possible for n to be divisible
// by these numbers.

#include <stdio.h>
#include <stdbool.h>

bool primeChecker(int n, int i);
bool primeChecker2(int n, int stop, int i);
bool isPrime(int n);

int main(void)
{
  // Test the primeChecker() function to see if 7 is prime or not, we notably
  // must supply 2 as the initial 2nd argument
  if (primeChecker(7, 2))
  {
    printf("7 is prime.\n");
  }
  else 
  {
    printf("7 is not prime.\n");
  }
  
  // Check if 7 is prime using the alternative solution which uses a wrapper 
  // function called isPrime() which only requires us to pass the number we 
  // are checking to see whether it is prime or not.
  if (isPrime(7))
  {
    printf("7 is prime.\n");
  }
  else 
  {
    printf("7 is not prime.\n");
  }
  
  return 0;
}

// Returns true if n is prime and false otherwise.  It is intended to be called
// with an initial 2nd i argument of 2, and the function will call itself with 
// i + 1 as the 2nd argument until i reaches or exceeds n/2.  
// 
// The function returns false if n <= 1 because n is not prime by definition if 
// this is true, and the function returns true if n == 2 because 2 is a special 
// prime number (it is the only even prime number, and is only divisible by 1 
// and 2).  Otherwise the function checks if n is divisible by i, if it is n 
// must not be prime and the function returns false.  If i has reached or 
// exceeded n/2 then n must be prime and the function returns true.  Otherwise
// the function calls itself again with i + 1 to check if n is divisible by 
// the next possible number.
//
bool primeChecker(int n, int i)
{
  if (n <= 1) return false;
  else if (n == 2) return true;
  else if (n % i == 0) return false;
  else if (i >= n/2) return true;
  else return primeChecker(n, i + 1);
}


// The above is a recursive solution to determine if a number is prime, but the
// function requires us to pass an initial 2nd argument of 2 rather than simply
// providing the integer n as an argument to check whether it is prime or not.
// The function will also check if n <= 1 or n == 2 each time it is called, even
// though if neither of these are true on the first call they will not be true
// on subsequent calls.  The function will also repeatedly divide n by 2 each 
// time it is called.
//
// The below solution uses a "wrapper function" isPrime() to address these
// issues.  

// Returns true if n is prime and false otherwise.
bool isPrime(int n)
{
  // If n is <= 1 the function returns false because n is not prime by 
  // defintion.  If n == 2 we have the special case of the only even prime 
  // number and the function returns true.  Otherwise the function calls 
  // primeChecker2 to recursively determine if n is prime.  We pass 
  // primeChecker2 the integer n that we wish to determine whether it is 
  // prime or not, as well as the "halfway number" n/2, and i == 2, the 
  // initial number that n may be divisible by.
  if (n <= 1) return false;
  else if (n == 2) return true;
  else return primeChecker2(n, n/2, 2);
}

// Returns true if n is prime and false otherwise.  Should only be called by
// the wrapper function isPrime() which provides the correct stop (n/2) and 
// initial i argument (2) values. 
bool primeChecker2(int n, int stop, int i)
{
  // Checks to see if n is divisible by i, if it is then n is not prime and
  // the function returns false.  Otherwise if i has reached or exceeded 
  // the "stop value" (n/2) then n must be prime the function returns true.
  // Otherwise if neither of these is the case the function calls itself 
  // again with the same n and stop values, but with i + 1, to check the 
  // next possible number that n may be divisible by.
  if (n % i == 0) return false;
  else if (i >= stop) return true;
  else return primeChecker2(n, stop, i + 1);
}