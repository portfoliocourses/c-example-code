/*******************************************************************************
*
* Program: Sum The Digits In A String
* 
* Description: Program to sum the digits in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=RaHlFhPymQE  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int sum_digits(char *string);

int main(void)
{
  // Test string
  char string[] = "12AB,95 1A";
  
  // Test function to sum digits in the string
  int sum = sum_digits(string);

  // Output the result
  printf("sum: %d\n", sum);
  
  return 0;
}

// Returns the sum of the digits in the string passed as an argument
int sum_digits(char *string)
{
  // Start off with a sum of 0 (e.g. there may be no digits in the string)
  int sum = 0;

  // Call strlen() to find the length of the string not including the null 
  // terminator character, e.g. the above test string has a length of 10
  int length = strlen(string);
  
  // Use the counter variable i to loop through each index of the string from 
  // 0...length-1, e.g. the above test string has characters at indexes 0-9 
  // and this loop will use the counter variable i to go through each of them
  for (int i = 0; i < length; i++)
  {
    // isdigit() returns true if the character it is passed is a digit and 
    // false otherwise, so only if the character is a digit its value will be 
    // added to the sum
    if (isdigit(string[i]))
    {
      sum += (string[i] - '0');

      // char values in C are really integers, where char values are mapped to 
      // integers via some character encoding.  For example in the ASCII 
      // character encoding '0' = 48, '1' = 49, ..., '9' = 57.  So if we have 
      // '1' - '0' we get the integer 1 as a result, and for '9' - '0' we get
      // the integer 9 as a result.  We subtract '0' from the character in 
      // the string at the index i which we know is a digit character from 
      // '0'...'9' to get the integer value of that digit, and we add it to
      // the sum.  When we do this for all digit characters in the string, 
      // we will compute their sum. 
    }
  }
 
  return sum;
}