/*******************************************************************************
*
* Program: Selection Sort
* 
* Description: Example of selection sort algorithm implemented in C.  See the 
* wikipedia article: https://en.wikipedia.org/wiki/Selection_sort
*
* YouTube Lesson: https://www.youtube.com/watch?v=YepJ7fDmyjI  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// An example of applying each step of the selection sort algorithm...
//
// Initial array: 5, 9, 7, 6, 4, 0, 2, 3, 8, 1
//
//        Step 0: 0, 9, 7, 6, 4, 5, 2, 3, 8, 1
//        Step 1: 0, 1, 7, 6, 4, 5, 2, 3, 8, 9
//        Step 2: 0, 1, 2, 6, 4, 5, 7, 3, 8, 9
//        Step 3: 0, 1, 2, 3, 4, 5, 7, 6, 8, 9
//        Step 4: 0, 1, 2, 3, 4, 5, 7, 6, 8, 9
//        Step 5: 0, 1, 2, 3, 4, 5, 7, 6, 8, 9
//        Step 6: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//        Step 7: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//        Step 8: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

int main()
{
  // a test array and array length
  int a[] = {5, 9, 7, 6, 4, 0, 2, 3, 8, 1};
  int length = 10;
  
  // Loop through each index of the array, as we do so the elements < i are 
  // considered the sorted portion of the array, and the elements >= i are 
  // considered the unsorted portion of the array.  The algorithm repeatedly 
  // finds the minimum element in the unsorted portion of the array and if 
  // necessary swaps it with the element at index i, increasing the portion 
  // of the sorted array with each iteration.
  for (int i = 0; i < length - 1; i++)
  {
    // find the position of the minimum element in the unsorted portion of 
    // the array
    int min_pos = i;
    for (int j = i + 1; j < length; j++)
      if (a[j] > a[min_pos]) min_pos = j;
    
    // if that element is NOT the element at index i, then swap that element 
    // with the element at index i
    if (min_pos != i)
    {
      int temp = a[i];
      a[i] = a[min_pos];
      a[min_pos] = temp;
    }
  }
  
  // print out the array so we can be sure it is sorted correctly
  for (int i = 0; i < length; i++)
    printf("a[%d] = %d\n", i, a[i]);
  
  return 0;
}