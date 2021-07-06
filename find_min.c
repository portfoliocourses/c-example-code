/*******************************************************************************
*
* Program: Find min in an array
* 
* Description: Example of finding the minimum value in an array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=sepK5w4Uep0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int find_min(int array[], int length);

int main(void)
{
  // test data
  int myarray1[] = {5,9,10,11,4,3,1,6,7};
  int myarray2[] = {2,5,9,2,5,3,0};

  // run tests
  int min1 = find_min(myarray1, 9);
  int min2 = find_min(myarray2, 7);

  // output test results
  printf("min1: %d\n", min1);
  printf("min2: %d\n", min2);

  return 0;
}

// returns the minimum number in an array with the given length
int find_min(int array[], int length)
{
  // assume the first element is the min value
  int min = array[0];

  // check all remaining elements, every time we find a lower value, make it
  // the new min value
  for (int i = 1; i < length; i++)
  {
    if (array[i] < min) 
    {
      min = array[i];
    }
  }

  return min;
}
