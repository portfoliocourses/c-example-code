/*******************************************************************************
*
* Program: Print The Odd Numbers In An Array
* 
* Description: Program to the print the odd numbers in an array using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=bpP6MRDXRSs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
 
void print_odd(int array[], int length);

int main(void)
{
  // A test array with 7 odd numbers: 5, 9, 17, 15, 21, 3, 1
  //
  // The algorithm works by iterating over each element in the array with 
  // each iteration of the loop using counter variable i. 
  //
  //             ->i->
  //   indexes:  0 1 2 3 4  5  6  7 8
  int array[] = {2,5,9,17,15,14,20,21,3,1};
  
  // Array length of 10 as the array has 10 elements
  int length = 10;
  
  // An odd number is an integer which when divided by 2 will give us a 
  // remainder of 1.  The modulus operator % will return the remainder of a 
  // division operation, so for example:
  //
  // 8 % 2 == 0   (even number)
  // 9 % 2 == 1   (odd number)
  //
  // So we can test if a number is odd by using modulus to divide it by 2 and
  // check if the remainder is 1.
  //
  // To print only the odd numbers in the array we use a for loop with a 
  // counter variable i which goes from 0 to 1 to length-1 (i.e. 9 in the case
  // of this array) with each loop iteration.  So with each iteration of the 
  // loop we use i to access and check if the next number in the array is 
  // odd, and only if it is do we print the number out.  We use \n to print 
  // each odd number on a new line.
  //
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 1)
    {
      printf("%d\n", array[i]);
    }
  }

  // A function for printing out the odd numbers in the array
  print_odd(array, length);
  
  return 0;
}

// Prints out the odd numbers in the array with the provided length using 
// the same algorithm as described above
void print_odd(int array[], int length)
{
  for (int i = 0; i < length; i++)
  {
    if (array[i] % 2 == 1)
    {
      printf("%d\n", array[i]);
    }
  }
}