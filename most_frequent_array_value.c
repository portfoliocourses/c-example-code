/*******************************************************************************
*
* Program: Find The Most Frequently Occurring Value In An Array
*
* Description: Find the most frequently occurring value in an array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=mIIvVze8xWc 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // Test array and array length
  int array[] = {4,2,7,4,7,5,7,4,7,6};
  int length = 10;
  
  // Keeps track of the number of occurrences of each value in the array
  int occurrences = 0;

  // Keeps track of the number of occurrences of the most frequently occurring
  // value found in the array (so far)
  int max_occurrences = 0;

  // Keeps track of the most frequently occurring value found in the array
  int max_value = 0;
  
  // The outer loop will go through each index in the array with the counter 
  // variable i going from 0 ... length-1 by 1.  We'll count the occurrences of
  // the value at each index in the array using an inner loop.  If the number
  // of occurrences of the value at the index i is greater than the number of 
  // occurrences of the most frequently occurring value found so far, then 
  // we'll update max_occurrences and max_value to reflect the number of 
  // occurrences of the new most frequently occurring value and the 
  // value itself.
  for (int i = 0; i < length; i++)
  {
    // Reset occurrences to 0, loop through each index in the array with the 
    // inner loop taking counter variable j from 0 ... length-1 by 1, and 
    // count the occurrences of the value at the index i.
    occurrences = 0;
    for (int j = 0; j < length; j++)
    {
      if (array[j] == array[i])
      {
        occurrences++;
      }
    }

    // If the number of occurrences of the value in the array at the index i 
    // is greater than the number of occurrences of the most frequently 
    // occurring value found so far, update max_occurrences and max_value.
    // Notably because we initialized max_occurrences to 0, the first value 
    // in the array stored at index 0 will always have more occurrences than 
    // 0 (as even one occurrence is greater than zero), and so will become 
    // at least temporarily the most frequently occurring value found 'so far'.  
    if (occurrences > max_occurrences)
    {
      max_occurrences = occurrences;
      max_value = array[i];
    }
  }

  // When the loop is done and all values in the array have been checked, 
  // max_value will be set to the most frequently occurring value in the 
  // array and max_occurrences will be set to the number of occurrences of
  // that value. 
  printf("max_occurrences: %d\n", max_occurrences);
  printf("max_value: %d\n", max_value);
   
  return 0;
}