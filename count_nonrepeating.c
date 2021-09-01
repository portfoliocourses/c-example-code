/*******************************************************************************
*
* Program: Count non-repeating array elements demonstration
* 
* Description: Counts all non-repeating elements in an array.  Note that 
* non-repeating elements does not mean the count of unique elements, it means 
* the count of all elements that do not have any repeat.
*
* YouTube Lesson: https://www.youtube.com/watch?v=pX3H_0oHQvA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int non_repeating(int a[], int length);

int main(void) 
{
  int array[] = {1,3,5,7,3,7,6,6,4,2,9};
  
  // test the function with the example array
  int count = non_repeating(array, 11);
   
  printf("count: %d\n", count);

  return 0;
}

// returns the non-repeating elements of an array with the given length
int non_repeating(int a[], int length)
{
  int i = 0, j = 0, count = 0;
  
  // outer loop count is used to check each element in the array
  for (i = 0; i < length; i++)
  {
    // inner loop also checks each element in the array, if we find a match 
    // (that is not the same element, which is why we check i != j), then we 
    // break
    for (j = 0; j < length; j++)
      if (a[i] == a[j] && i != j) break;
    
    // if j is equal to the length that means the inner loop did not find a 
    // match (otherwise we would've break'd out of the loop before j reaches 
    // the length), in which case we've found a non-repeating element and we 
    // increment count
    if (j == length) count++;
  }
  
  return count;
}



