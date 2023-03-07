/*******************************************************************************
*
* Program: Head vs Tail Recursion 
* 
* Description: Examples of head and tail recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=l3qIbfuAhCw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

// Returns the sum of the integers from 1 ... n using recursion.  So if n = 5
// then we expect the function to return 5 + 4 + 3 + 2 + 1 = 15.  The function
// continually returns n + sum(n-1), which means if we call the function with 
// sum(5) we'll have 5 + sum(4) which leads to 5 + 4 + sum(3) and so on.  This
// is called the recursive case of the function.  The base case of the function
// is when we return 0 when n == 0, stopping recursion.  This would be a very 
// typical way to solve this problem using recursion, but it is using neither 
// head or tail recursion.
//
int sum(int n)
{  
  if (n == 0) return 0;
  else return n + sum(n-1);
}

// Returns the sum of the integers from 1 ... n using head recursion.  Head 
// recursion is a type of recursion where the first statement in the function
// is a call to the function, and only a call to the function, where the 
// return value is not used in any operation.  Though we are allowed to 
// return the value and/or have the statement inside of an if and still have 
// it considered to be head recursion.  The function below conforms to those 
// rules, and so we call it head recursion.  In this function we accumulate 
// the result of the addition operations in the 2nd parameter result as part 
// of the recursive case, and then return the result in the base case when 
// n is no longer greater than 0.
//
int sumHead(int n, int result)
{
  if (n > 0) return sumHead(n - 1, result + n);
  else return result; 
}

// A tail recursive function has the recursive function call as the last 
// statement in the function, and only a call to the function, where the 
// return value is not used in any operation.  As with head recursion it's
// OK if the value returned by the function is returned or if the statement
// is part of an if-else control structure.  In this function we also 
// accumulate the result of the addition operations in the result parameter
// as part of the recursive case, before returning the result in the base 
// case when n == 0.  
//
// There is a potential problem with using recursion.  When a function 
// call is made, all the information for the function call such as 
// parameter values and return value is kept track of in a place called 
// the call stack.  The call stack has a limited amount of memory, but 
// recursive functions might involve so many function calls being made that
// the stack runs out of memory, and an error called a stack overflow occurs.
//
// Tail recursion can be removed by placing the function code inside of a 
// loop that will repeat forever, and assigning the recursive function call
// arguments to the parameter variables (instead of calling the function).  
// Below this function a sumTailModified() function illustrates how this can be 
// done.  We can remove tail recursion manually, but it's also possible for a 
// compiler to remove it automatically, perhaps with the right compiler 
// optimization settings.
// 
// We have switched the types to long in this version of the function compared
// to sumHead() so we can attempt to use an n value of 1,000,000 which 
// will cause a resulting sum that is outside the range of int.  A long 
// can store a greater range of integers.  If we do not compile the function
// with a compiler and/or setting that removes the tail recursion, a stack 
// overflow may occur with this high number of recursive function calls.
//
// With the gcc compiler we can have it use the level 2 optimizations to 
// remove the tail recursion with:
//
// gcc -O2 -o head_vs_tail_recursion head_vs_tail_recursion.c
//
long sumTail(long n, long result)
{
  if (n == 0) return result;
  else return sumTail(n - 1, result + n); 
}  

// The function is a modification of the above sumTail() function to 
// remove the tail recursion.  We do so by putting the function code inside a 
// loop that will repeat forever, and instead of calling the function, assigning
// the function arguments to the parameter variables.
//
long sumTailModified(long n, long result)
{
  while (true)
  {
    if (n == 0) return result;
    result = result + n;
    n = n - 1; 
  }
} 

int main(void)
{
  // Test out all the functions
  printf("sum(5): %d\n", sum(5));
  printf("sumHead(5,0): %d\n", sumHead(5, 0));
  printf("sumTail(5,0): %ld\n", sumTail(5, 0));
  printf("sumTailModified(5,0): %ld\n", sumTailModified(5, 0));

  // Because sumTailModified() uses iterative code it will be able to handle 
  // the high n value without a stack overflow error occurring. 
  printf("sumTailModified(1000000,0): %ld\n", sumTailModified(1000000, 0));

  // Unless we compile the program with a compiler and settings to remove the 
  // tail recursion, this below function call is likely to result in a stack
  // overflow error due to the high number of recursive function calls.
  printf("sumTail(1000000, 0): %ld\n", sumTail(1000000, 0));

  return 0;
}