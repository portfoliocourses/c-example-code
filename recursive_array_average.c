/*******************************************************************************
*
* Program: Recursive Array Average Computation
* 
* Description: Example of using recursion to find the average of an array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=RRtA0GxRijo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

double average(double a[], int n);

int main(void)
{
  // test data for our function
  double array[] = {1,2,3,4,5,6,7,8,9,10};
  int length = 10;
  
  // test out the function
  printf("average: %f\n", average(array, length));
  
  return 0;
}

// returns the average of array a of length n using recursion, see the 
// explanation below about how the function works
double average(double a[], int n)
{
  if (n == 1) return a[n-1];
  else return (average(a, n-1) * (n-1) + a[n-1]) / n;
}

// To imagine how this function works, let's pretend we have an array with 
// 5 elements 1,2,3,4,5, then we would compute the average like this:
//
// (1 + 2 + 3 + 4 + 5) / 5 = avg
//
// In order to recursively solve the problem, we need to break the problem 
// down into smaller parts.  What we do here is find the sum of the first 
// 4 elements (n-1 elements) by recognizing that:
//
// (1 + 2 + 3 + 4) / 4 = avg
//
// and therefore the sum of those first 4 elements is:
//
// (1 + 2 + 3 + 4) = avg * 4
//
// so if we can find the average of the first 4 elements, we can use *that* 
// to get the portion of the average computation highlighted in []
//
// ([1 + 2 + 3 + 4] + 5) / 5
//
// This is *essentially* how our function works, by example.  The else 
// case in our function is the "recursive case" that recursively applies 
// the process outlined above.  When we call average with a and n-1, we 
// are finding the average of the first n-1 elements, and multiplying it 
// by n-1 to get the sum of those first n-1 elements!  We then add in the 
// additional final element and divide by the total length n to get the 
// average of the entire array.
// 
// Eventually in this process we'll be left with an array of one element, 
// this is the "base case" of our recursive logic, handled by in the 
// if-case when we return the value of that one element (which is by 
// definition the average of that one element).  This "base case" also 
// handles the case of finding the average of an array of one element too!
//