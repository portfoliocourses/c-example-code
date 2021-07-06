/*******************************************************************************
*
* Program: Replace char
* 
* Description: Example of how to replace one character with another in a string
* with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0OjJc-Qyd4E
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void replace_char(char *string, char replace, char new);

int main(void)
{
  // test the function with some example arguments

  char s1[] = "This is my string!";
  replace_char(s1, 'i', 'Z');
  printf("s1: %s\n", s1);

  char s2[] = "aaaaBBBBaBBBBaaaBBBBcdea";
  replace_char(s2, 'a', 'Z');
  printf("s2: %s\n", s2);

  return 0;
}

// replaces occurrences of replace in string with new
void replace_char(char *string, char replace, char new)
{
  int slen = strlen(string);

  // check each index for the replace char, replace with new if necessary
  for (int i = 0; i < slen; i++)
    if (string[i] == replace)
      string[i] = new;
}