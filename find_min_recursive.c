/*******************************************************************************
*
* Program: Find Minimum Number In Array With Recursion
* 
* Description: Example of using recursion to find the smallest number in an 
* array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=BrO7hfdC8So 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int min(int array[], int n);

int main()
{
  int array[] = {4,1,8,6,0,9,5,2,3,7};
  int length = 10;
  
  printf("min: %d\n", min(array, length));
  
  return 0;
}

int min(int array[], int n)
{
  if (n == 1) return array[n - 1];
  
  int possible_min = min(array, n - 1);
  
  if (possible_min < array[n - 1]) return possible_min;
  else return array[n - 1];
}
