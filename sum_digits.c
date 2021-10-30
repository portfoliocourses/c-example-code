/*******************************************************************************
*
* Program: Sum The Digits Of A Number
* 
* Description: Sum the digits of a number in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=_fHTUj6BzY0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main()
{
  // variables for storing the number, the sum, and each digit
  int number = 0;
  int sum = 0;
  int digit = 0;
  
  // ask the user for the number, store it into number
  printf("Enter number: ");
  scanf("%d", &number);
  
  // repeatedly apply modulus 10 to extract the next digit, add it to the sum,
  // and then do divide by 10 to reduce the number to the remaining digits, 
  // until the number is zero... see below comment for an 'example run' of 
  // this algorithm to see how it works!
  while (number != 0)
  {
    digit = number % 10;
    sum += digit;
    number = number / 10;
  }
  
  // output the sum
  printf("sum: %d\n", sum);
  
  return 0;
}

//
// Example run of the algorithm of repeatedly extracting the next digit with 
// modulus 10 and then reducing the number to the remaining digits with 
// divide by 10.
//
// number = 237
//
// 237 % 10 -> 7 (digit)
// 237 / 10 -> 23
//
// number = 23
//
// 23 % 10 -> 3
// 23 / 10 -> 2
//
// number = 2
//
// 2 % 10 -> 2
// 2 / 10 -> 0
//
// sum = 2 + 3 + 7 = 12
//