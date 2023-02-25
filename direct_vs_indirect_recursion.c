/*******************************************************************************
*
* Program: Direct vs. Indirect Recursion
* 
* Description: Examples of direct recursion and indirect recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=RxpxFqGBdwY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int sum_integers(int n);

void countdown(int n);
void print_even(int n);
void print_odd(int n);

int main()
{
  // Call the sum_integers() function and output the return value.  The s
  // sum_integers() function using direct recursion to calculate the sum of the 
  // integers from 1...n, where n is a positive integer.
  int sum = sum_integers(4); 
  printf("sum: %d\n", sum);
  
  // Call the countdown() function, which uses functions print_even() and 
  // print_odd() to begin a series of recursive function calls that output the 
  // integers from n ... 1.  We assume n is a positive integer, and each integer 
  // will have "even" or "odd" placed next to it.  print_even() and print_odd() 
  // use indirect recursion (sometimes called mutual recursion) to achieve this.
  countdown(10);
  
  return 0;
}

// Uses direct recursion to the sum the integers from n ... 1 and return the 
// sum.  The function assumes that it will be passed a positive integer n.  The
// function's base case is when n == 1, and it simply returns 1.  The function's
// recursive case is when n >= 1, and it returns n + sum_integers(n-1).  So if 
// the function is called with 4 we will have "4 + sum_integers(3)" as the 
// return value, where sum_integers(3) will result in "3 + sum_integers(2)" and
// so on, building a chain of additions... 4 + 3 + sum_integers(2), which will 
// stop at the base case n == 1, i.e. 4 + 3 + 2 + 1 = 10.  The function is using
// "direct recursion" because it calls itself.
int sum_integers(int n)
{
  if (n == 1) return 1;
  else return n + sum_integers(n-1);
}

// Countdown outputs a countdown of the integers from n ... 1 where we assume 
// n >= 1.  For n = 10 we will get the countdown:
//
// 10 - even
// 9 - odd
// 8 - even
// 7 - odd
// ... and so on ...
// 1 - odd
//
// The function calls either print_even() if n is even or print_odd() if n is 
// odd to begin a series of recursive function calls to produce the countdown.
// print_even() and print_odd() call each other to solve the problem and are 
// thus an example of indirect recursion (i.e. mutual recursion).
//
// Note that we can check if n is even using n % 2 = 0 because if n is even 
// it will have zero remainder when divided by 2, and the modulus operator % 
// will give the remainder of n divided by 2.
//
void countdown(int n)
{
  if (n % 2 == 0) print_even(n);
  else print_odd(n);
}

// Output the even integer it is given as an argument (n) and then calls 
// print_odd() with n-1 which must be an odd integer.  The function stops 
// recursion when n < 1 by not doing anything in this case.  The function 
// assumes that the integer n it is provided is even.  
//
// The print_odd() function that print_even() calls will also call print_even(),
// making these functions an example of indirect recursion.
//
void print_even(int n)
{
  if (n >= 1)
  {
    printf("%d - even\n", n);
    print_odd(n-1);
  }
}
 
// Output the odd integer it is given as an argument (n) and then calls 
// print_even() with n-1 which must be an even integer.  The function stops 
// recursion when n < 1 by not doing anything in this case.  The function 
// assumes that the integer n it is provided is odd.  
//
// The print_even() function that print_odd() calls will also call print_odd(),
// making these functions an example of indirect recursion.
//
void print_odd(int n)
{
  if (n >= 1)
  {
    printf("%d - odd\n", n);
    print_even(n-1);
  }
}