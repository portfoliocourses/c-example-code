/*******************************************************************************
*
* Program: Check If A Value Is In An Array
* 
* Description: Check if an array includes a value as a member in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=5mIvuE4ugOg  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

bool includes(int array[], int length, int value);

int main(void)
{
  // test array
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  int length = 10;
  
  // the array should not include 11
  if (includes(a, length, 11))
    printf("Found 11 in array a\n");
  else
    printf("Could not find 11 in array a\n");
  
  return 0;
}

// returns true if the array with the given length contains value
bool includes(int array[], int length, int value)
{
  // increment i over all indexes of the array from 0...length-1
  for (int i = 0; i < length; i++)
  {
    // if an element matches the value, the array contains the value
    if (array[i] == value) return true;
  }
  
  // if we check all elements and none match the value, the array does not 
  // contain the value
  return false;
}