/*******************************************************************************
*
* Program: Count The Occurrences Of A Character In A String Using Recursion
*
* Description: Program to count the occurrences of a character in a string using
* recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0CyNbF_pcrY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int count_occurrences(char *string, char c);

int main(void)
{
  char test[] = "Some characters in the string.";

  printf("a count: %d\n", count_occurrences(test, 'a'));

  return 0;
}

int count_occurrences(char *string, char c)
{
  if (*string == '\0')
    return 0;
  else if (*string == c)
    return 1 + count_occurrences(string + 1, c);
  else
    return count_occurrences(string + 1, c);
}
