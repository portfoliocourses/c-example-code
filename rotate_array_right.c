/*******************************************************************************
*
* Program: Rotate array right demonstration
* 
* Description: Examples of rotating an array to the right in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=3_CFbQOSIBI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void rotate_once_right(int array[], int length);
void rotate_right(int array[], int length, int n);

int main(void) 
{
  int a1[] = {1,2,3,4,5,6};
  
  // print out array before rotation
  for (int i = 0; i < 6; i++)
    printf("%d ", a1[i]);
  printf("\n");
 
  // comment and uncomment to try different function calls
  // rotate_once_right(a1, 6);
   rotate_right(a1, 6, 2);
  // rotate_right(a1, 6, 6);

  // print out array after rotation
  for (int i = 0; i < 6; i++)
    printf("%d ", a1[i]);
  printf("\n");

  return 0;
}

// we rotate the array with the provided length n indexes right by calling the 
// rotate_once_right function n times
void rotate_right(int array[], int length, int n)
{
  for (int i = 0; i < n; i++)
    rotate_once_right(array, length);
}

// rotates an array with the given length one index to the right
void rotate_once_right(int array[], int length)
{
  // store the last element of the array as it will be overwritten when we shift
  // the other elements to the right
  int temp = array[length - 1];

  // for indexes 1 to the end of the array, set the element equal to the element
  // to immeadiate left 
  for (int i = (length - 2); i >= 0; i--)
    array[i + 1] = array[i];
  
  // set the first element of the array to the previous last element of the array
  array[0] = temp;
}
