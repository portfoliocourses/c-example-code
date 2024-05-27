/*******************************************************************************
*
* Program: Remove Last Occurrence Of A Character In A String
*
* Description: Program to remove the last occurrence of a character in a string
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=_3-R2l0mh7w 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void remove_last(char string[], const char to_remove);

int main(void)
{
  // Test string and character to remove
  char string[] = "Microsoft";
  char to_remove = 'o';
  
  // Call function to remove last occurrence of to_remove from string
  remove_last(string, to_remove);
  
  // Output the resulting string
  printf("%s\n", string);

  return 0;
}

// Remove the last occurrence of to_remove from string
void remove_last(char string[], const char to_remove)
{
  int length = strlen(string);
  int i = length - 1;
  
  // Find the index of the last occurrence of the character in the string by 
  // searching backwards from the last index to the front of the string.  Stop
  // the loop using break if we find the character to_remove, with i set to 
  // the index of the character.  Otherwise stop the loop if we go past the
  // end of the string and i == -1.
  while (i >= 0)
  {
    if (string[i] == to_remove) break;
    i--;
  }
  
  // If i is >= 0 that means we found an occurrence of the character in the 
  // string and will remove it, otherwise i == -1 and there is no occurrence
  // to remove 
  if (i >= 0)
  {
    // Pull forward the characters at the indexes i + 1 onwards (INCLUDING the
    // null terminator) to effectively shrink the string by one index while 
    // overwriting the last occurrence of to_remove at the index i.
    while (i < length)
    {
      string[i] = string[i + 1];
      i++;
    }
  }
}
