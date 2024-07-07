/*******************************************************************************
*
* Program: Print The Even Numbers In An Array
* 
* Description: Program to the print the even numbers in an array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wFerwn5RiWE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
 
void print_even(int array[], int length);

int main(void)
{
  // A test array with 4 even numbers: 2, 8, 20, 4.
  //
  // The algorithm works by iterating over each element in the array with 
  // each iteration of the loop using counter variable i. 
  //
  //             ->i->
  //   indexes:  0 1 2 3 4  5  6  7 8
  int array[] = {2,5,8,7,11,17,20,5,4};
  
  // Array length of 9 as the array has 9 elements
  int length = 9;
  
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
  // To print only the even numbers in the array we use a for loop with a 
  // counter variable i which goes from 0 to 1 to length-1 (i.e. 8 in the case
  // of this array) with each loop iteration.  So with each iteration of the 
  // loop we use i to access and check if the next number in the array is 
  // even, and only if it is do we print the number our.  We use \n to print 
  // each even number on a new line.
  //
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 0)
    {
      printf("%d\n", array[i]);
    }
  }

  // A function for printing out the even numbers in the array
  print_even(array, length);
  
  return 0;
}

// Prints out the even numbers in the array with the provided length using 
// the same algorithm as described above
void print_even(int array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 0)
    {
      printf("%d\n", array[i]);
    }
  }
}