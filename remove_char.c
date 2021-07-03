/*******************************************************************************
*
* Program: Remove character from a string
* 
* Description: Example of how to to remove all occurrences of a character from 
* a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=OAMPGC032AQ  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void remove_char(char *string, char r);

int main(void)
{
  // test case 1
  char s1[] = "A string with some words!";
  printf("s1 before: %s\n", s1);
  remove_char(s1, 'i');
  printf("s1 after: %s\n", s1);

  // test case 2
  char s2[] = "aaaAAAxxAAAaaaBBBCCaaaaAa";
  printf("s2 before: %s\n", s2);
  remove_char(s2, 'a');
  printf("s2 after: %s\n", s2);

  return 0;
}

// removes all occurrences of the character r from string
void remove_char(char *string, char r)
{
  // start checking for r from the first position in the string
  int pos = 0;

  // keep checking the current position until we reach the null terminator
  while (string[pos] != '\0')
  {
    // if we encounter the char we are attempting to remove...
    if (string[pos] == r)
    {
      // ...shift the entire remaining string over one character to the left...
      int newpos = pos;
      while (string[newpos] != '\0')
      {
        string[newpos] = string[newpos+1];
        newpos++;
      }
    }
    // Because we shift the string over one position to the left if we 
    // encounter the character at the current position, the string will have 
    // a new character at position!  It's only if we do NOT encounter the 
    // character at the current position that we need to increment to the next 
    // position in the string to check.
    else pos++;
  }

}


