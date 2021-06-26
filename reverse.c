/*******************************************************************************
*
* Program: Reverse an array
* 
* Description: An example of a function for reversing the contents of an array.
*
* YouTube Lesson: https://www.youtube.com/watch?v=7EfA0cwZGC0  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void reverse(int array[], int length);

int main(void)
{
  // two example arrays
  int myarray1[] = {1,2,3,4,5,6,7,8,9};
  int myarray2[] = {6,5,4,3,2,1};

  // reverse the arrays
  reverse(myarray1, 9);
  reverse(myarray2, 6);
  
  // output the arrays after they have been reversed
  for (int i = 0; i < 9; i++) printf("myarray1[%d] = %d\n", i, myarray1[i]);
  printf("\n");
  for (int i = 0; i < 6; i++) printf("myarray2[%d] = %d\n", i, myarray2[i]);

  return 0;
}

// Reverses the array with the given length (no need for a return value)
void reverse(int array[], int length)
{
  int temp = 0;

  // Uses the temp variable to swap corresponding values at the start and end 
  // of the array, incrementing by 1 until we reach the middle of the array. 
  for (int i = 0; i < (length / 2); i++)
  {
    // classic swap algorithm using a temp variable to store one variable's 
    // value before we overwrite it with the other variable's value
    temp = array[i];
    array[i] = array[length - i - 1];
    array[length - i - 1] = temp;
  }  
}

