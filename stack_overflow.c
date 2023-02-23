/*******************************************************************************
*
* Program: Stack Overflow Errors
* 
* Description: Examples of stack overflow errors in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=D3scXBzRQUk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

//  Imagine we have a program like this where a main() function calls a function 
//  f1() that calls another function f2()...
//
//
//  void f2(int a, int b)
//  {
//    printf("%d %d", a, b);
//  }
//
//  void f1(int x, int y)
//  {
//    f2(x, y);
//  }
//
//  int main(void)
//  {
//    int r = 8;
//    int t = 3;
//
//    f1(r, t);
//
//    return 0;
//  }
//
//
//  The data associated with each function call (parameters, local variables,
//  etc.) gets stored in a data structure called the call stack.  Each function
//  call is represented with a stack frame on this stack.  When a function calls
//  another its stack frame is placed on top of the other function's stack 
//  frame, and when it completes its work it then comes off the stack as in 
//  the below illustrations.
//
//  The call stack has a limited capacity, and it can only store so much data 
//  and so many stack frames.  If the capacity is exceeded, a stack overflow 
//  error occurs.  A recursive function which calls itself too many times can
//  create enough stack frames to exceed the capacity of the stack.  Functions 
//  with large local variables can also exceed the capacity of the stack.
//
//  The size of the call stack is system dependent (OS, compiler settings, 
//  etc.) and in the below examples stack overflow errors occurred on a Mac 
//  OS X machine using the gcc compiler.
//
//
//   Call Stack Progression:
//
//                   f2
//                   |
//           f1      f1      f1
//           |       |       |
//   main -> main -> main -> main -> main
//     
//
//  Call Stack After f1() Call (Simplified)
//
//                       top of stack where
//                       next stack frame
//            <--------- will go
//   ----------
//  |  x = 8  |     
//  |  y = 3  |     <--- stack frame (f1)
//  |  f1     |
//  |----------
//  |  r = 8  |     
//  |  t = 3  |     <--- stack frame (main)
//  |  main   |
//   ---------- 
//
//
//  Call Stack After f2() Call (Simplified)
//  
//   ----------     <--- new top
//  |  a = 8  |     
//  |  b = 3  |     <--- stack frame (f2)
//  |  f2     |                     
//   ----------
//  |  x = 8  |     
//  |  y = 3  |     <--- stack frame (f1)
//  |  f1     |
//  |----------
//  |  r = 8  |     
//  |  t = 3  |     <--- stack frame (main)
//  |  main   |
//   ---------- 


#include <stdio.h>

// A recursive function that returns the sum of the values in the array 'a' 
// with the provided length, beginning from index i in the array.  The intention
// is that the function is called with the array, its length, and an initial 
// index i of 0, to find and return the sum of the array elements.
int sum(int a[], int length, int i)
{
  // base case, recursion stops when i reaches the length of the array
  if (i == length)
  {
    return 0;
  }
  // Recursive step, the value in the array at the index i is added to the 
  // sum of the remaining elements in the array by calling sum with the 
  // index i + 1.  The function cannot return until it receives the return 
  // value from its own recursive function call, which means the call stack 
  // will have a stack frame for each element in the array as the function 
  // sums the elements 'one per function call'.  For a large enough array, 
  // a stack overflow error will occur as the number and size of the stack 
  // frames exceeds the capacity of the call stack.  Infinite recursion where 
  // a function calls itself an infinite number of times, or deep recursion 
  // where a function call itself many times, are two ways that a stack 
  // overflow error can occur.
  else 
  {
    return a[i] + sum(a, length, i + 1);
  }
}

// A stack overflow can also occur if we have very large variables in the 
// call stack... here function1() and function2() both create arrays of 
// one million int values.  The size of the call stack is dependent on 
// the system.  But on the system this code was tested on (a Mac OS machine 
// using gcc), calling function1() from main() was enough to cause a stack 
// overflow error when it makes the call to function2().  When the call to 
// function2() is removed from function1() it was not enough to cause a 
// stack overflow error, demonstrating that the issue is not the size of the 
// individual array so much as the total size of everything on the call stack.
//
void function2()
{
  int big_array[10000000];
}

void function1()
{
  int big_array[1000000];
  function2();
}

int main(void)
{
  // Declare a large int array
  int a[1000000];
  int length = 1000000;

  // Initialize all elements in the array to 1
  for (int i = 0; i < length; i++)
  {
    a[i] = 1;
  }
   
  // The size of the array itself is not a problem... we can sum the values
  // of the array OK using iterative code like the below loop.
  int array_sum = 0;
  for (int i = 0; i < length; i++)
  {
    array_sum += a[i];
  }
  
  // Output the sum of the array produced from the iterative code above
  printf("sum: %d\n", array_sum);

  // Calling the recursive function produces a stack overflow error when the 
  // call stack is overwhelmed with too many stack frames being created.
  //
  // printf("sum: %d\n", sum(a, length, 0));

  // function1() calls function2() and both create large int arrays, which 
  // also causes a stack overflow error when the call stack cannot hold these 
  // arrays (in addition to the large array created in main above).
  //
  // function1();

  return 0;
}