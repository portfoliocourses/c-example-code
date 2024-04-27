/*******************************************************************************
*
* Program: Check If Strings Are Equal Using Recursion
*
* Description: Program to check if two strings are equal using recursion in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=qkvtPbM3A1o 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>

bool string_equals(const char *s1, const char *s2);

int main(void)
{
  char string1[] = "ABCD";
  char string2[] = "ABCD";
  
  if (string_equals(string1, string2))
  {
    printf("Strings are equal.\n");
  }
  else
  {
    printf("Strings are not equal.\n");
  }
   
  return 0;
}

bool string_equals(const char *s1, const char *s2)
{
  if (*s1 != *s2) return false;
  else if (*s1 == '\0' && *s2 == '\0') return true;
  else return string_equals(++s1, ++s2);
}
