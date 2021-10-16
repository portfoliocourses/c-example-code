/*******************************************************************************
*
* Program: qsort() demonstration
* 
* Description: Example of using qsort() to sort an array in C.  The qsort() 
* function uses the quicksort algorthim to sort:
*   https://en.wikipedia.org/wiki/Quicksort
*
* YouTube Lesson: https://www.youtube.com/watch?v=rHoOWG6Ihs4
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// special comparison function will determine the order of the sorted array
int compare(const void *x_void, const void *y_void)
{
  // we need to cast the pointer to point to the type of element our array 
  // contains, and then dereference the pointer to get at the value itself
  // pointed to by the pointer... this is convoluted, but we need to do it as 
  // qsort() is built to work with *any* potential types
  int x = *(int *)x_void;
  int y = *(int *)y_void;

  // what we return will influence the order the list is sorted, see the 
  // large comment at the end of the file for an explanation... in this case 
  // when x is < y we will be returning a positive number, which tells 
  // qsort() to order x *after* y
  return y - x;
}

int main()
{
  // test data
  int a[] = {8, 7, 2, 4, 6, 3, 5, 1, 9, 0};
  int length = 10;
  
  // test the function
  qsort(a, length, sizeof(int), compare);
  
  // output the array to observe whether and how it has been sorted
  for (int i = 0; i < length; i++)
    printf("a[%d] = %d\n", i, a[i]);
  
  return 0;
}


// We need to provide a special function...
//
// int comparator(const void *x, const void *y);
//
// return value of the function will effect the sorting order
//
// < 0 if x should go before y
// 0   if x is equivalent to y
// > 0 if x should go after y
//
// and in the above breakdown, by 'x' and 'y' we *really* mean
// the values pointed to by x and y as x and y are pointers
// in the above function!
//
