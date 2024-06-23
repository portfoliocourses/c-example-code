/*******************************************************************************
*
* Program: Sum Array Elements Using Recursion
* 
* Description: Example of using recursion to sum the elements of an array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=cAVpNjpOiZU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int sum_array(int array[], int n);

int main(void)
{
  // A test array.  The algorithm works by continually adding the element at 
  // the index n-1 to the sum with each additional function call (until reaching
  // the start of the array).
  //
  //               <---n-1
  // indexes:    0 1 2 3
  int array[] = {2,1,4,3};
  
  // Sum the elements of the array
  int sum = sum_array(array, 4);
  
  // Output the resulting sum
  printf("sum: %d\n", sum);
  
  return 0;
}

// Returns the sum of the array.  When the function is first called it should be
// passed the length of the array as a 2nd argument.
//
// The function works by adding the element at the index n-1 to the sum, and 
// finding the sum of the remaining first n-1 elements in the array by calling 
// itself again with n-1.  In this way, the function goes through the elements 
// from the end to the start of the array, adding each element to the sum that 
// is built up over a series of function calls (one for each element).  This is
// the "recursive step" or "recursive case".
//
// Once n <= 0 this tells us we have reached the start of the array, and so we 
// stop recursion and have the function return 0 which will have no effect on 
// the sum that is being calculated.  We call this the "base step" or the 
// "base case".  
//
// Notably we can also think of the function as summing the first n elements 
// in the array, and the first time we call the function we want to sum all 
// the elements in the array so we call it with the length of the array as 
// the argument for n!
// 
int sum_array(int array[], int n)
{
  if (n <= 0) return 0;
  else return array[n - 1] + sum_array(array, n - 1);
}
