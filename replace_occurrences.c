#include <stdio.h>
/*******************************************************************************
*
* Program: Replace All Occurrences Of A Value In An Array
* 
* Description: Example of a function to replace all occurrences of a value in
* an array with another value.
*
* YouTube Lesson: https://www.youtube.com/watch?v=kQuHxfPS9xE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
void replace(int array[], int length, int value, int new);

int main(void)
{
  // test array
  int a[] = {1,2,1,2,1,2,1,2,1,2};
  int length = 10;
  
  // call the function to replace occurrences of 2 with 3
  replace(a, length, 2, 3);
  
  // output the array to check if the function worked correctly
  for (int i = 0; i < length; i++)
    printf("%d ", a[i]);
  printf("\n");
  
  return 0;
}

// replaces all occurrences of value with new in the array with the given length
void replace(int array[], int length, int value, int new)
{
  // loop through each array element, replace value for new wherever it occurs
  for (int i = 0; i < length; i++)
    if (array[i] == value)
      array[i] = new;
}