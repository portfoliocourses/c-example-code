/*******************************************************************************
*
* Program: Move All Zeros In An Array To The End
* 
* Description: Example of how to move all the zeros in an array to the end of 
* the array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=CK7Xue5Y9Kw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void shift_zeros(int array[], int length);

int main(void)
{
  // This is what the array data[] should look like after moving all zeros to 
  // the end:   2,5,6,7,4,7,0,0,0,0
  int data[] = {2,0,5,6,0,0,7,0,4,7};
  int length = 10;
  
  // call the function to shift the zeros to the end of the array
  shift_zeros(data, length);
  
  // output the array
  for (int i = 0; i < length; i++)
    printf("%d ", data[i]);
  printf("\n");
  
  return 0;
}

// moves the zeros in array with the given length to the end of the array
void shift_zeros(int array[], int length)
{
  // We loop through the array with two counter variables... counter variable 
  // i will let us look at each element in the array, and the count variable 
  // will let us re-write non-zero elements to the front of the array.  We only
  // write the element at index i to the array at index count, as well as 
  // increment count, when the element at index i is non-zero.  This has the
  // effect of shifting up all the non-zero elements to the front of the array.
  int count = 0;
  for (int i = 0; i < length; i++)
  {
    if (array[i] != 0)
    {
      array[count] = array[i];
      count++;
    }
  }
  
  // write zeros into the remaining elements of the array from count - length to
  // move the zeros to the back of the array
  for (int i = count; i < length; i++)
    array[i] = 0;
}