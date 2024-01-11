/*******************************************************************************
*
* Program: Find The First Non-Repeating Element In An Array
* 
* Description: Find the first non-repeating element in an array using C, i.e. 
* find the first unique value in an array.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4xlJ7eWL-ok 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  // Declare and initialize the array, the first non-repeating element is 3 at 
  // index 2 because 7 and 8 both repeat in the array.
  int array[] = {7,8,3,4,5,8,7,9,2,1};
 
  // Stores the length of the array
  int length = 10;
  
  // Keeps track of whether the element currently being examined is repeating or not
  bool repeating = false;

  // Keeps track of whether a non-repeating element was ever found, initialized to 
  // false because we assume no such element exists until we find one
  bool found_non_repeating = false;
  
  // Examine each element in the array from the first index in the array to the
  // last using the loop counter variable i to go through each array index 
  // in order...
  for (int i = 0; i < length; i++)
  {
    // Assume that the element does repeat by setting repeating to false
    repeating = false;

    // Then loop through all the array elements again in the same way using 
    // counter variable j to try to find a repeating element
    for (int j = 0; j < length; j++)
    {
      // if we find an element in array that matches/equals the element 
      // currently being examined, we have found a repeat, as long as the 
      // element is at a different index as well (i != j) otherwise if i==j
      // all we've found is that the same element matches itself
      if (array[i] == array[j] && i != j)
      {
        // Set repeating to true to acknowledge this element is repeating and
        // stop the loop using break because there is no need to continue 
        // searching
        repeating = true;
        break;
      }
    }
    
    // If repeating is STILL set to false a repeat must never have been found
    // for the element being examined at the index i, and we output this 
    // element as the first non-repeating element and stop the loop.  We also
    // set found_non_repeating to true to acknowledge that a non-repeating 
    // element was found. 
    if (!repeating)
    {
      printf("First Non-Repeating Element: %d\n", array[i]);
      found_non_repeating = true;
      break;
    }
  }
  
  // If we never found a non-repeating element (because all elements repeat)
  // then output this 
  if (!found_non_repeating)
  {
    printf("No non-repeating element found!\n");
  }

  return 0;
}