/*******************************************************************************
*
* Program: Insertion Sort demonstration
* 
* Description: Implementation of the insertion sort algorithm in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Tz7vBodZqo8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void insertion_sort(int a[], int length);

int main()
{
  // test the algorithm implementation with an example array
  int a[] = {8,4,9,5,7,6,3,2};
  insertion_sort(a, 8);
  for (int i = 0; i < 8; i++)
    printf("a[%d] = %d\n", i, a[i]);

  return 0;
}

// sorts the array a with the given length using the insertion sort algorithm:
//   https://en.wikipedia.org/wiki/Insertion_sort
void insertion_sort(int a[], int length)
{
  // the outer loop examines each element on the right-hand side of the array 
  // from the 2nd element on to the end of the array
  for (int i = 1; i < length; i++)
  {
    // the inner loop shifts over elements on the sorted left hand side of the 
    // list until the correct sorted position for the key element is found, at 
    // which point we place it there
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = key;
  }
}

