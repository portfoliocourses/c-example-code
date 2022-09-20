/*******************************************************************************
*
* Program: Print An Array In Reverse
*
* Description: Example of printing out the elements of an array in reverse using
* C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=CoecB74aSV0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

void print_reverse(int array[], int length);

int main(int argc, char *argv[])
{
  // Declare and initialize an array of length 6
  //             0,1,2,3,4,5
  int array[] = {5,6,7,8,9,10};

  // We could keep track of the length of the array in a variable
  int length = 6;

  // Call the function to print out the array in reverse
  print_reverse(array, length);

  // Create another test array with 10 elements
  int b[] = {0,1,2,3,4,5,6,7,8,9};

  // Call the function to print out array b in reverse
  print_reverse(b, 10);

  return 0;
}

// Prints out the elements of the given array of the given length in reverse
void print_reverse(int array[], int length)
{
  // The counter variable starts at length - 1 because the last element of the
  // array will be at the index one less than the length of the array, and
  // then decrements the counter variable by 1 with each loop iteration.  The
  // loop stops when the counter variable reaches 0 (the last index of the
  // array).  In this way the indexes of the array are "looped through" from
  // the end to the start of the array, and we print out the array elements
  // at each counter variable index in the array body separated by spaces.
  for (int i = length - 1; i >= 0; i--)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}
