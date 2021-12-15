/*******************************************************************************
*
* Program: Armstrong Number Checker 
* 
* Description: Check to see if a number is an Armstrong number in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Hb0sQVEnxCg  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_armstrong(int number);

int main(void)
{
  // check if the number 371 is an armstrong number or not... it should be!
  if (is_armstrong(371))
    printf("371 is an armstrong number!\n");
  else
    printf("371 is NOT an armstrong number!\n");
  
  // output all armstrong numbers between 0 - 10000
  for (int i = 0; i <= 10000; i++)
    if (is_armstrong(i)) printf("%d\n", i);
  
  
  return 0;
}

// returns true if number is an armstrong number, and false othrwise
bool is_armstrong(int number)
{
  // total_digits will keep track of the total number of digits, digits_left 
  // will be used to process the number one digit at a time to count the 
  // total digits in the number
  int total_digits = 0;
  int digits_left = number;
  
  // count the number of digits in number by continually dividing it by 10 
  // until it is 0 and counting how many divisions this takes... dividing 
  // by 10 effectively eliminates the rightmost digit of the number each 
  // time given how integer division works (i.e. there is no remainder)
  while (digits_left != 0)
  {
    total_digits++;
    digits_left /= 10;
  }
  
  // digit will store each digit, total will store the sum of raising the digits
  // to the power of the total number of digits, and number_left will be used to
  // keep track of the remaining portion/digits of the original number as we 
  // process each digit one at a time
  int digit = 0;
  int total = 0;
  int number_left = number;
  
  // follow the same process above of continually dividing the number by 10 
  // each time until it is 0
  while (number_left != 0)
  {
    // extract the first digit in the remaining number each time using the 
    // modulus operator which returns the REMAINDER of divide by 10, effectively
    // giving us the rightmost digit of the remaining number
    digit = number_left % 10;

    // take the digit and raise it to the power of the number of digits, add 
    // the result to the sum total 
    total += pow(digit, total_digits);

    // continually removes the rightmost digit of the number 
    number_left /= 10;
  }
  
  // return whether the number is equal to the total or not... if it is, 
  // then number is an armstrong number, otherwise it is not
  return (total == number);
}

// An Armstrong number is a number that is the sum of its
// own digits raised to the power of the number of digits.
//
// 371 - 3 digits long
//
// 3^3 = 27
// 7^3 = 343
// 1^3 = 1
//
// 27 + 343 + 1 = 371
