/*******************************************************************************
*
* Program: Find The First Occurrence Of A Character In A String
* 
* Description: Example of how to find the index of the first occurrence of a 
* character in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=yMOtjV1NuGw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int first_occurrence(char string[], char character);

int main()
{
  // Store a test string into a test char array
  char string[] = "A string containing a sentence.";
  //               0123456789... <-- each char occurs at an index
  
  // We will attempt to find the first occurrence of the character 'n which
  // should be at the index 6
  char character = 'n';

  // Call first_occurrence() to find the first occurrence of the char 
  // 'character' in the string 'string'.  
  int index = first_occurrence(string,character);

  // first_occurrence() will return -1 if it can't find ANY occurrence of the 
  // character in the string, we output a suitable message in this case
  if (index == -1)
  {
    printf("%c not found in string.\n", character);
  }
  // Otherwise we output the first index in the string where the char was found
  else
  {
    printf("%c found at index %d.\n", character, index);
  }

  return 0;
}

// Returns the index of the first occurrence of the char 'character' in the 
// string 'string', returning -1 if it cannot find any occurrence.
int first_occurrence(char string[], char character)
{
  // Find the length of the string not including the null terminator using the 
  // strlen() function from string.h, store the returned length into the length
  // variable.
  int length = strlen(string);
  
  // Check each index in the string from the first (0) until the length of the 
  // string, if we find the character at that index, return the index.
  for (int i = 0; i < length; i++)
  {
    if (string[i] == character)
    {
      return i;
    }
  }

  // If the above loop ends without finding the character in the string we 
  // return the special value -1 to signify no occurrence was found.
  return -1;
}