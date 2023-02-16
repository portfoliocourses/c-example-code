/*******************************************************************************
*
* Program: Single vs. Multiple Recursion Examples
* 
* Description: Examples to illustrate the difference between single recursion 
* and multiple recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0fnHr5gVyvw
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/


#include <stdio.h>

// The function below will calculate the factorial of a non-negative iteger n.
//
// The factorial of n is defined as....
// 
// n! = n * (n-1) * (n-2) * ... * 2 * 1
//
// where zero factorial is...
//
// 0! = 1
//
// So 5! is...
//
// 5! = 5 * 4 * 3 * 2 * 1 = 120

// Recursively calculates the factorial of n.  n == 0 is the vase case, and 
// otherwise we execute a recursive step.
int fact(int n)
{
  if (n == 0) return 1;
  else return n * fact(n-1);
}

// A call to fact() may make at most one new recursive function call.  This 
// is what makes the above function an example of single recursion.  The 
// recursive function calls will form a linear chain of recursive function 
// calls as shown below.  Sometimes we call single recursion "linear recursion".
//
// fact(n)
//   |
//    -----> n * fact(n-1)
//                 |
//                  -----> (n-1) * fact(n-2)
//                                   |
//                                    ------> ....
//
//
//        ..... n recursive function calls .....



//  The Fibonacci Sequence is the sequence of numbers...
//
//  Fn: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
//
//   n: 0  1  2  3  4  5  6  7   8   9   10
//
//  Term n in the sequence is defiend using this recurrence relation, with 
//  initial conditions F0 = 0 and F1 = 1, and further terms in the sequence
//  defined as Fn = Fn-1 + Fn-2.
//
//  F0 = 0
//  F1 = 1
//  Fn = Fn-1 + Fn-2

// Recursively calculates term n in the Fibonacci sequence, essentially directly
// implementing the above recurrence relation. 
int fib(int n)
{
  if (n == 0) return 0;
  else if (n == 1) return 1;
  else return fib(n-1) + fib(n-2);
}

//  Each function call to fib() may make MULTIPLE recursive function calls.  
//  This is what makes this an example of multiple recursion.  Specifically 
//  the recursive step will result in exactly two recursive function calls.
//  This will result in a tree structure of recursive function calls (see 
//  the examples below).  We sometimes call multiple recursion "tree 
//  recursion".  If a multiple recursive function results in at most two 
//  new function calls being created, we may call it "binary recursion".
//
//  The growth in function calls is exponential, as when n increases by 1 
//  it doubles the number of recursive function calls required!  An 
//  exponential algorithm that continues to do this will not be efficient.
//
//
//                   fib(2)                    n = 2
//                  /     \                calls = 2
//              fib(1)    fib(0)
//
//
//
//
//                   fib(3)                    n = 3
//                  /      \               calls = 4
//              fib(2)     fib(1)
//             /     \
//         fib(1)   fib(0)
//
//
//
//
//                     fib(4)                  n = 4
//                    /      \             calls = 8
//              fib(3)        fib(2)
//             /      \      /      \
//       fib(2)    fib(1)  fib(1)    fib(0)
//       /     \
//   fib(1)   fib(0) 


int main()
{
  // test out the factorial function
  printf("fact(5) = %d\n", fact(5));
  
  // test out the Fibonacci function
  printf("fib(8) = %d\n", fib(8));
  
  return 0;
}