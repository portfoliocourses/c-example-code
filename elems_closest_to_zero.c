/*******************************************************************************
*
* Program: Find The Two Elements Of An Array Whose Sum Is Closest To Zero
*
* Description: Program to find the two elements of an array whose sum is closest
* to zero using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=3YFMiDk3TvE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void find_min_sum_pair(int array[], int length);

int main(int argc, char *argv[])
{
  int array[] = {25, 42, -31, 12, 55, -20, -18, -48, 16, 34};

  find_min_sum_pair(array, 10);

  return 0;
}

void find_min_sum_pair(int array[], int length)
{
  if (length < 2) return ;

  int min_sum = array[0] + array[1];
  int min_index1 = 0;
  int min_index2 = 1;

  for (int i = 0; i < (length - 1); i++)
  {
    for (int j = i + 1; j < length; j++)
    {
      int new_sum = array[i] + array[j];
      if (abs(new_sum) < abs(min_sum))
      {
        min_sum = new_sum;
        min_index1 = i;
        min_index2 = j;
      }
    }
  }

  printf("Min Sum: %d\n", min_sum);
  printf("Value1: %d (occurs at index %d)\n", array[min_index1], min_index1);
  printf("Value2: %d (occurs at index %d)\n", array[min_index2], min_index2);
}