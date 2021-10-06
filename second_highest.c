/*******************************************************************************
*
* Program: Find Second Highest Array Element
* 
* Description: Example of finding the second highest number in an array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=k__ZO0e1OHQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int second_highest(int a[], int length);

int main()
{
  // test the function
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  int result = second_highest(a, 10);
  printf("second highest: %d\n", result);
  
  return 0;
}

// returns the second highest number in an array 'a' with the given 'length'
int second_highest(int a[], int length)
{
  // max1 will store the highest number, max2 will store the 2nd highest 
  int max1;
  int max2;
  
  // determine which of the first two elements is initially the highest number 
  // and which is the second highest number
  if (a[0] > a[1])
  {
    max1 = a[0];
    max2 = a[1];
  }
  else
  {
    max1 = a[1];
    max2 = a[0];
  }
  
  // loop through and examine each of the remaining elements of the array
  for (int i = 2; i < length; i++)
  {
    // if the current element is higher than the highest number, we need to 
    // update BOTH the highest number AND the second highest number... where 
    // this current element becomes the new highest number, and the previous 
    // highest number becomes the new 2nd highest number
    if (a[i] > max1)
    {
      max2 = max1;
      max1 = a[i];
    }
    // if the number is lower than the highest number but higher than the 2nd 
    // highest number (i.e. it is in-between the two numbers) then we only 
    // need to update the second highest number as this number is the new 
    // second highest number
    else if (a[i] > max2 && a[i] < max1)
    {
      max2 = a[i];
    }
  }
  
  return max2;
}



