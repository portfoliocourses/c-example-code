/*******************************************************************************
*
* Program: Rotate array left demonstration
* 
* Description: How to rotate an array to the left in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=2Rsd5mphXnY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void rotate_left_once(int array[], int length);
void rotate_left(int array[], int length, int n);

int main(void) 
{
  int a1[] = {1,2,3,4,5,6};
  
  // print out array before rotation
  for (int i = 0; i < 6; i++)
    printf("%d ", a1[i]);
  printf("\n");
  
  // if we rotate left 6 times we get back the original array!
  rotate_left(a1, 6, 6);
  
  // other examples, try by uncommenting
  // rotate_left_(a1, 6, 2);
  // rotate_left_once(a1, 6);
  
  // print out array after rotation
  for (int i = 0; i < 6; i++)
    printf("%d ", a1[i]);
  printf("\n");

  return 0;
}

// rotate the array left n times
void rotate_left(int array[], int length, int n)
{
  // apply the rotate_left_once function n times
  for (int i = 0; i < n; i++)
    rotate_left_once(array,length);
}

// rotates the array with the given length to the left by one index
void rotate_left_once(int array[], int length)
{
  // store the first element in the array so we can put it on the end after
  int temp = array[0];
  
  // rotate elements from index 0 until the 2nd last index to the left 
  for (int i = 0; i < (length - 1); i++)
    array[i] = array[i + 1];

  // put the former first element of the array as the new last element
  array[length - 1] = temp;
}
