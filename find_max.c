/*******************************************************************************
*
* Program: Find max in an array
* 
* Description: Example of finding the maximum value in an array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=VnsmgHEZiLA  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int find_max(int array[], int length);

int main(void)
{
  // test data
  int myarray1[] = {8,7,5,3,9,10,1,2,4};
  int myarray2[] = {9,6,3,1,0,8};

  // run test
  int max1 = find_max(myarray1, 9);
  int max2 = find_max(myarray2, 6);

  // output test results
  printf("max1: %d\n", max1);
  printf("max2: %d\n", max2);

  return 0;
}

// returns the max value in an an array with the given length >=1
int find_max(int array[], int length)
{
  // assume the first element is the max
  int max = array[0];

  // check all elements, updating the max whenever a larger number is found
  for (int i = 1; i < length; i++)
  {
    if (array[i] > max) 
    {
      max = array[i];
    }
  }

  return max;
}

