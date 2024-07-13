/*******************************************************************************
*
* Program: Count The Even And Odd Numbers In An Array
* 
* Description: Program to the count the even and odd numbers in an array using 
* C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=XidlkXpowb0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
 
int main(void)
{
  // A test array with 4 even numbers: 2, 12, 16, 14
  // And 6 odd numbers: 1, 3, 5, 19, 13, 11
  //
  // The algorithm works by iterating over each element in the array with 
  // each iteration of the loop using counter variable i. 
  //
  //             ->i->
  //   indexes:  0 1 2 3 4  5  6  7  8  9
  int array[] = {2,1,3,5,12,19,16,14,13,11};

  // Array length of 10 as the array has 10 elements
  int length = 10;
  
  // An even number is an integer which is divisible by 2, which means when we 
  // divide the number by 2 we will have a remainder of 0.  An odd number is 
  // an integer which when divided by 2 gives us a remainder of 1.  The modulus
  // operator % will return the remainder of a division operation, so for 
  // example:
  //
  // 8 % 2 == 0   (even number)
  // 9 % 2 == 1   (odd number)
  //
  // So we can test if a number is even or by using modulus to divide it by 2 
  // and check if the remainder is 0 or 1.  That said, if an integer is not even
  // then it is odd, we we really only need to check if the number is even and 
  // if it is not we know it must be odd.
  //
  // To count the even and odd numbers in the array we use a for loop with a 
  // counter variable i which goes from 0 to 1 to length-1 (i.e. 9 in the case
  // of this array) with each loop iteration.  So with each iteration of the 
  // loop we use i to access and check if the next number in the array is 
  // even or odd, and only if it is do we increment a running count (total_even
  // or total_odd) or the total number of even or odd numbers in the array.
  //  
  int total_even = 0;
  int total_odd = 0;
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 0)
    {
      total_even++;
    }
    else
    {
      total_odd++;
    }
  }
  
  // Output the results
  printf("Total Even: %d\n", total_even);
  printf("Total Odd: %d\n", total_odd);
  
  return 0;
}