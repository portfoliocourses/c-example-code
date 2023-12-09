/*******************************************************************************
*
* Program: Find The Frequency Of Digits In An Integer Number
*
* Description: Program to find the frequency of digits 0-9 in an integer number
# using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=HZc57hqkmjU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  // We can identify each digit in an integer number by continually dividing the
  // number by 10 until the resulting quotient is equal to 0.  The remainder of
  // each division is each digit in the number, see below:
  //
  // 415 / 10 = 41 remainder 5
  //  41 / 10 =  4 remainder 1
  //   4 / 10 =  0 remainder 4
  
  // Variables to store the number, each digit, and total digits in the number
  int number = 0;
  int digit = 0;
  int total = 0;

  // Stores a count of each digit 0-9 at indexes 0-9, initialized to 0 as no 
  // digits have been counted yet.
  int frequency[10] = {0};

  // Prompt the user to enter a number, store it into the number variable
  printf("Enter Number: ");
  scanf("%d", &number);
  
  // The below algorithm will not work if the number is negative, so if the 
  // number is negative we multiply it by -1 to make it positive.  The sign
  // of the number doesn't matter from the perspective of the frequency of
  // the digits.  Note that the algorithm doesn't work because number % 10
  // will give us a negative number if number is negative.
  if (number < 0) number *= -1;

  do
  {
    // The modulus operator % will give us the remainder of dividing the 
    // number by 10, i.e. each digit in the number, which we store into 
    // digit.
    digit = number % 10;
    
    // We increment the count for the digit in the frequency array at the 
    // index for that digit in the array.
    frequency[digit]++;

    // Divide the number by 10 and store the quotient into number.
    number /= 10;

    // Increment the count of the total amount of digits
    total++;

  // continue this process until the number/quotient reaches 0
  } while (number != 0);
  
  // Output the frequency of each digit in a simple list with digit - frequency
  // by having a loop with a counter variable go from 0...9, outputting the 
  // counter variable (digit) and associated count of that digit in frequency[].
  printf("\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d - %d\n", i, frequency[i]);
  }
  
  // We could also ouput the data in a neatly formatted table.  We output a row
  // of column headings, followed by a row of stars, followed by rows of data. 
  // We use %-9d to output the digits into a a field of width 9 left-aligned, 
  // and similarly with %-13d.  We output the percentage as a floating point
  // number with %f and %.2f outputs the percentage with 2 decimal digits of 
  // precision.  The %% will output a % symbol.
  printf("\n");
  printf("Digit    Frequency    Percentage\n");
  printf("********************************\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%-9d%-13d%.2f%%\n",
           i,
           frequency[i],
           ((double) frequency[i] / total) * 100
           );
  }
    
  return 0;
}