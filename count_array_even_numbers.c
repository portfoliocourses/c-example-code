/*******************************************************************************
*
* Program: Count The Even Numbers In An Array
* 
* Description: Program to the count the even numbers in an array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=c7ng6QEvmxk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
 
int count_even(int array[], int length);

int main(void)
{
  // A test array with 4 even numbers: 2, 4, 8, 12
  //
  // The algorithm works by iterating over each element in the array with 
  // each iteration of the loop using counter variable i. 
  //
  //             ->i->
  //   indexes:  0 1 2 3 4 5 6 7 8 9
  int array[] = {2,4,1,7,9,3,5,7,8,12};
  
  // Array length of 10 as the array has 10 elements
  int length = 10;
  
  // An even number is an integer which is divisible by 2, what this means is 
  // that if we divide a number by 2 and have a remainder of 0 then we have 
  // an even number.  The modulus operator % will return the remainder of a 
  // division operation, so for example:
  //
  // 8 % 2 == 0   (even number)
  // 9 % 2 == 1   (odd number)
  //
  // So we can test if a number is even by using modulus to divide it by 2 and
  // check if the remainder is 0.
  //
  // To count the even numbers in the array we use a for loop with a 
  // counter variable i which goes from 0 to 1 to length-1 (i.e. 9 in the case
  // of this array) with each loop iteration.  So with each iteration of the 
  // loop we use i to access and check if the next number in the array is 
  // even, and only if it is do we increment a running count (total_even) of 
  // the amount of even numbers in the array.  
  //
  int total_even = 0;
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 0)
    {
      total_even++;
    }
  }

  // Output the result
  printf("Total Even: %d\n", total_even);

  // A function for counting the even numbers in the array
  total_even = count_even(array, length);
  
  // Output the result
  printf("Total Even: %d\n", total_even);

  return 0;
}

// Counts the even numbers in the array with the provided length using 
// the same algorithm as described above
int count_even(int array[], int length)
{
  int total_even = 0;
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 0)
    {
      total_even++;
    }
  }

  return total_even;
}