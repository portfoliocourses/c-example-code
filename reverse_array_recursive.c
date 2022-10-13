/*******************************************************************************
*
* Program: Reverse An Array Using Recursion
*
* Description: A program to reverse an array by using a recursive function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=YKoM4udWNKM
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

void reverse(int array[], int low, int high);
void reverse_array(int array[], int length);

int main(int argc, char *argv[])
{
  // test array and length
  int array[] = {1,2,3,4,5,6,7,8};
  int length = 8;

  // We can call the reverse() function directly to reverse the array and
  // supply it with the array, the first index (0), and the last index of the
  // array (length - 1) as arguments.  This will reverse the array, but the
  // "interface" for the function may not be ideal for programmers who may
  // prefer to just pass the array and the length of the array to a function.
  //
  // reverse(array, 0, length - 1);

  // Call the wrapper function reverse_array to reverse the array, which only
  // requires the array and length as arguments and may be considered a better
  // "interface" for the programmer to use.
  reverse_array(array, length);

  // Output the array elements to confirm the array has been reversed.  The
  // counter variable i is set to each index in the array from 0 to the last
  // element in the array (length - 1) and we output the element at each index.
  for (int i = 0; i < length; i++)
    printf("%d ", array[i]);
  printf("\n\n");

  return 0;
}

// A wrapper function that reverses an array with the given length, by calling
// the reverse function which uses recursion to reverse the array.  It passes
// the reverse function the array, and the initial 'low' index 0 (the first
// element in the array) and the initial 'high' index length-1 (the last
// element in the array).  It may be considered inconvenient for the programmer
// to call the reverse() function, which requires them to know how to call the
// function with a low and high index, rather than just call the wrapper and
// provide the array and the length of the array which is a more familiar
// interface.
void reverse_array(int array[], int length)
{
  reverse(array, 0, length - 1);
}

// Reverses the array by swapping the elements at the low and high index, and
// then recursively calling itself again with a low index incremented by 1
// and a high index decremented by 1.  The expectation is that the function is
// initially called with 0 as the low index and the last index of the array
// as the high index, to swap the first element in the array with the last
// element in the array.  When the function calls itself again with the low
// index low + 1 and the high index high - 1, the 2nd element in the array
// will then be swapped with the 2nd last element.  And the algorithm will
// proceed this way, so long as the low index is less than the high index.
// Recursion will stop when the low index is no longer less than the high
// index, as at that point we will have reached the middle of the array, and
// the array will have been reversed.
void reverse(int array[], int low, int high)
{
  if (low < high)
  {
    int temp = array[low];
    array[low] = array[high];
    array[high] = temp;
    reverse(array, low + 1, high - 1);
  }
}