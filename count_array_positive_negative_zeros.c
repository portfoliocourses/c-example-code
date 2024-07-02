/*******************************************************************************
*
* Program: Count The Positive, Negative And Zero Numbers In An Array
* 
* Description: Program to the count the positive, negative and zero numbers in 
* an array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=eb5w_E1LhcM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // Declare and initialize a test array.
  //
  // The algorithm below works by having a loop counter variable i go through
  // each index of the array with each loop iteration, from 0, 1, ..., length-1.
  // With each loop iteration we then examine the number at the index i to 
  // determine if it is either a positive, negative or zero number, and 
  // increment a relevant running count for that number type.
  //
  //             ->i->
  //    indexes: 0 1 2  3  4   5   6  7 8 9
  int array[] = {5,0,-3,56,-79,100,45,3,0,-6};

  // Store the length of the array
  int length = 10;

  // Store the 'running counts' of the number of positive, negative and zero 
  // numbers found in the array.  They begin at 0 because before we examine
  // any numbers in the array we have not found any numbers of any category yet.
  int positive_count = 0;
  int negative_count = 0;1
  int zero_count = 0;    
  
  // The loop counter variable i will go from index 0 to 1 all the way to 
  // length-1 (i.e. 9 in this case) with each loop iteration.  So with each 
  // loop iteration i will be set to each index of the array.  We access the 
  // array element at that index using array[i].  We first check to see if it 
  // is positive, if it is we increment positive_count to acknowledge we have 
  // found another positive number.  Otherwise we check if it is negative, and
  // if it is we increment negative_count to acknowledge we have found another
  // negative number.  The only other possibility left is that the number is
  // zero, so if neither of the above is the case we increment zero_count.  By
  // the time this loop is done we will have counted all the positive, negative
  // and zero numbers in the array.
  for (int i = 0; i < length; i++)
  {
    if (array[i] > 0) positive_count++;
    else if (array[i] < 0) negative_count++;
    else zero_count++;
  }
  
  // Output the resulting counts
  printf("Positive Count: %d\n", positive_count);
  printf("Negative Count: %d\n", negative_count);
  printf("Zero Count: %d\n", zero_count);

  return 0;
}