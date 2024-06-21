/*******************************************************************************
*
* Program: Check If Two Arrays Are Equal Or Not
* 
* Description: Program to check if two arrays are equal or not using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vPpmd0i7SD0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool array_equals(int *a1, int len1, int *a2, int len2);

int main(void)
{
  // Test arrays
  int array1[] = {1,2,3,4,5};
  int array2[] = {1,2,3,8,5};
   
  // Check if the two arrays are equal, report the result
  if (array_equals(array1, 5, array2, 5))
  {
    printf("Arrays are equal.\n");
  }
  else
  {
    printf("Arrays are not equal.\n");
  }
  
  return 0;
}

// Returns true if the arrays pointed to by a1 and a2 with lengths len1 and len2
// are equal, and false otherwise.
//
// We consider two arrays to be equal if they have the same length and have the
// same values stored at the same indexes.
//
bool array_equals(int *a1, int len1, int *a2, int len2)
{
  // If a1 or a2 are "pointing to nothing" (i.e. NULL), e.g. because somewhere 
  // in a program dynamically allocation failed, then we just return false as
  // we can't work with an array if we can't access it
  if (a1 == NULL || a2 == NULL) return false;

  // In standard C we cannot have arrays of length 0 and arrays with a negative
  // length do not make sense, so we just return false if either array is not 
  // at least 1 element in length, i.e. if the length of either is <= 0
  if (len1 <= 0 || len2 <= 0) return false;
  
  // If the arrays do not have same length, then we know they are not equal
  if (len1 != len2) return false;
  
  // Otherwise go through each array index and compare the pairs of elements in 
  // each array at each index, if we find that the arrays ever do not have the
  // same value at the same index we know the arrays are not equal
  for (int i = 0; i < len1; i++)
  {
    if (a1[i] != a2[i]) return false;
  }
  
  // Only if the arrays have the same length and all indexes of both arrays
  // store the same value do we return true as the arrays are equal
  return true; 
}