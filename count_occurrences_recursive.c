/*******************************************************************************
*
* Program: Count The Occurrences Of A Value In An Array Using Recursion
* 
* Description: Program to count the occurrences of a value in an array using 
* recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Ev7ZkWCHHoU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int count_occurrences(int array[], int n, int value);

int main(void)
{
  // Test array.  The recursive function works by moving n-1 from the last index
  // of the array to the start of the array by one index with each function 
  // call.  
  //
  //              <- n-1 <-
  //             0 1 2 3 4
  int array[] = {1,3,4,3,5};
  
  // Call the recursive function, passing it the length of the array as the 2nd
  // argument the first time it is called.  We'll count the occurrences of the 
  // value 3 in the array (there are two).
  int occurrences = count_occurrences(array, 5, 3);
  
  // Output the result
  printf("Occurrences: %d\n", occurrences); 
  
  return 0;
}

// Counts the occurrences of the value in the array using recursion, and 
// should be initially called with the length of the array as the 2nd 
// argument.
//
// The function checks if the value occurs at the index n-1, which on the 
// first function call will be the last index of the array.  The function 
// then returns the count of the occurrences of the value in the remaining
// portion of the array, BUT adds 1 to this count ONLY if the value does
// occur at the index n-1 (this occurs in the else if and else cases).  
//
// The function calls itself to find the number of the occurrences of the 
// value in the remaining portion of the array, passing n-1 as the 2nd 
// argument so that the NEXT time the function calls the NEXT index going 
// towards the start of the array will be examined to see if the value 
// occurs at this index.  Over a series of function calls a series of 
// addition operations (1 + ...) will occur, one for each occurrence of 
// the value, summing the total number of occurrences.
//
// The function stops calling itself once n <= 0 as this means the start
// of the array has been reached.  The function returns 0 at this point 
// as adding it to the sum will have no effect on the result.
//
int count_occurrences(int array[], int n, int value)
{
  if (n <= 0)
  {
    return 0;
  }
  else if (array[n-1] == value)
  {
    return 1 + count_occurrences(array, n-1, value);
  }
  else
  {
    return count_occurrences(array, n-1, value);
  }
}