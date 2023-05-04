/*******************************************************************************
*
* Program: Bubble Sort Implementation
* 
* Description: Example of implementing bubble sort in C.  See the Wikipedia
* article on Bubble Sort: https://en.wikipedia.org/wiki/Bubble_sort
*
* YouTube Lesson: https://www.youtube.com/watch?v=YqzNgaFQEh8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int a[], int length);

int main(void)
{
  int a[] = {1,3,7,0,2,4,9,5,8,6};
  
  int length = 10;

  bubble_sort(a, length);
  
  // output the array to see it has been sorted
  for (int i = 0; i < length; i++)
    printf("a[%d] = %d\n", i, a[i]);

  return 0;
}

// Accepts an array and its length and sorts it using the bubble sort algorithm
//
// Bubble sort works by continually passing through the elemnts of an array 
// and swapping those that are found to be out of order, see:
//   https://en.wikipedia.org/wiki/Bubble_sort
//
void bubble_sort(int a[], int length)
{
  bool swapped = false;
  int i = 0;

  // The outer loop will continue to attempt to sort the array so long as it 
  // may still be out of order.  We know the array might still be out of order
  // if a swap has taken place... if no swap has taken place, we know that the
  // array is sorted.  So we used the bool swapped to keep track of whether a 
  // swap has taken place, and to decide when to terminate the algorithm.
  do 
  {
    swapped = false;

    // The inner loop makes a pass through the array elements, and if any 
    // element and the element next to it are out of order, it swaps them. 
    // After the first pass through the array, we know for sure that the last 
    // element of the array is sorted, and after the 2nd pass through we know 
    // for that the 2nd last element of the array is sorted... and so we can 
    // progressively pass through less elements of the array each time we run 
    // this loop.  We use i to keep track of how many passes through the array 
    // we have made, and lessen the number of elements we go through each time!
    for (int j = 0; j < (length - 1 - i); j++)
    {
      // we could flip < to > to have it sort in ascending order instead of 
      // descending order as it will now
      if (a[j] < a[j + 1])
      {
        // swaps elements that are detected to be out of order using a temporary
        // variable to store one value before we need to overwrite it with the
        // other, see: https://en.wikipedia.org/wiki/Swap_(computer_programming)
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
      } 
    }
    i++;
  } while (swapped);
}
