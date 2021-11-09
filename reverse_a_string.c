/*******************************************************************************
*
* Program: Reverse a String
* 
* Description: Example of a function to reverse a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=PtSHcou0WIs
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void reverse(char *string);

int main(void)
{
  // test string
  char test[] = "One small step for (a) man.";
  
  // reverse the test string
  reverse(test);
  
  // output the test string after it has been reversed
  printf("%s\n", test);
  
  return 0;
}

// reverses the string provided as an argument
void reverse(char *string)
{
  // get the length of the string, use it to compute the middle index
  int length = strlen(string);
  int middle = length / 2;

  // used to swap characters on either side of the string
  char temp;

  // Swaps characters at the beginning of the string with their corresponding 
  // character at the end of the string... i.e. the first character with the 
  // last character, the second character with the second last character, and 
  // on and on until the middle of the string is reached, at which point the 
  // string will be reversed!
  for (int i = 0; i < middle; i++)
  {
    temp = string[i];
    string[i] = string[length - i - 1];
    string[length - i - 1] = temp;
  }
}
