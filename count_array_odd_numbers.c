/*******************************************************************************
*
* Program: Count The Odd Numbers In An Array
* 
* Description: Program to the count the odd numbers in an array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=PVaIb2Y-Avw
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
 
int count_odd(int array[], int length);

int main(void)
{
  // A test array with 5 odd numbers: 3, 5, 15, 21, 33
  //
  // The algorithm works by iterating over each element in the array with 
  // each iteration of the loop using counter variable i. 
  //
  //             ->i->
  //   indexes:  0 1 2 3 4  5  6  7  8  9
  int array[] = {3,5,8,6,14,15,18,21,33,4};
  
  // Array length of 10 as the array has 10 elements
  int length = 10;
  
  // An odd number is an integer which when divided by 2 gives us a remainder of
  // 1.  The modulus operator % will return the remainder of a division 
  // operation, so for example:
  //
  // 8 % 2 == 0   (even number)
  // 9 % 2 == 1   (odd number)
  //
  // So we can test if a number is odd by using modulus to divide it by 2 and
  // check if the remainder is 1.
  //
  // To count the odd numbers in the array we use a for loop with a 
  // counter variable i which goes from 0 to 1 to length-1 (i.e. 9 in the case
  // of this array) with each loop iteration.  So with each iteration of the 
  // loop we use i to access and check if the next number in the array is 
  // odd, and only if it is do we increment a running count (total_odd) of 
  // the amount of odd numbers in the array.  
  //
  int total_odd = 0;
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 1)
    {
      total_odd++;
    }
  }

  // Output the result
  printf("Total Odd: %d\n", total_odd);

  // A function for counting the odd numbers in the array
  total_odd = count_odd(array, length);
  
  // Output the result
  printf("Total Odd: %d\n", total_odd);

  return 0;
}

// Counts the odd numbers in the array with the provided length using 
// the same algorithm as described above
int count_odd(int array[], int length)
{
  int total_odd = 0;
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 1)
    {
      total_odd++;
    }
  }

  return total_odd;
}