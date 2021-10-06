/*******************************************************************************
*
* Program: Find Second Lowest Array Element
* 
* Description: Example of finding the second lowest number in an array in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Fczwe3h8oJM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int second_lowest(int a[], int length);

int main()
{
  // test the function
  int a[] = {9,8,7,6,5,0,1,2,3,4};
  int result = second_lowest(a, 10);
  printf("second lowest: %d\n", result);
  
  return 0;
}

// returns the second lowest number in an array 'a' with the given 'length'
int second_lowest(int a[], int length)
{
  // min1 will store the lowest number, min2 will store the 2nd highest 
  int min1;
  int min2;

  // determine which of the first two elements is initially the lowest number 
  // and which is the second lowest number  
  if (a[0] < a[1])
  {
    min1 = a[0];
    min2 = a[1];
  }
  else
  {
    min1 = a[1];
    min2 = a[0];
  }
  
  // loop through and examine each of the remaining elements of the array
  for (int i = 2; i < length; i++)
  {
    // if the current element is lower than the lowest number, we need to 
    // update BOTH the lowest number AND the lowest highest number... where 
    // this current element becomes the new lowest number, and the previous 
    // lowest number becomes the new 2nd lowest number    
    if (a[i] < min1)
    {
      min2 = min1;
      min1 = a[i];
    }
    // if the number is higher than the lowest number but lower than the 2nd 
    // lowest number (i.e. it is in-between the two numbers) then we only 
    // need to update the second lowest number as this number is the new 
    // second lowest number    
    else if (a[i] < min2 && a[i] > min1)
    {
      min2 = a[i];
    }
  }
  
  return min2;
}
