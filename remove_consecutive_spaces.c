/*******************************************************************************
*
* Program: Remove Consecutive Spaces In A String
* 
* Description: Remove the consecutive spaces in a string using C, i.e. replace
* multiple consecutive spaces with a single space.
*
* YouTube Lesson: https://www.youtube.com/watch?v=liwJ3Gr-6z0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void remove_consecutive_spaces(char *string);

int main(void)
{
  // Test string with consecutive spaces, we want to remove them and replace
  // them with a single space
  char string[] = "String   with   consecutive  spaces.";
  
  // Output the string before removing the consecutive spaces
  printf("Before: '%s'\n", string);
  
  // Remove the consecutive spaces
  remove_consecutive_spaces(string);
  
  // Output the string after removing the consecutive spaces
  printf(" After: '%s'\n", string);

  return 0;
}

// Remove the consecutive spaces from the string provided as an argument
void remove_consecutive_spaces(char *string)
{
  // Find the length of the string
  int length = strlen(string);
  
  // A 'copy' of the the string with the consecutive characters removed will be
  // written over top of the existing string.  This copy may have less 
  // characters than the original string, so we create the counter variable 
  // j to keep track of the number of characters in this new 'copy' string.
  int j = 0;

  // We'll loop through the string one character at a time, only copying it into
  // the new string if it is not a consecutive character.  last_char_not_space 
  // will be set to true if the last character was not a space, allowing us 
  // to identify if we have a consecutive space or not.
  bool last_char_not_space = true;

  // Loop through the string one character at a time
  for (int i = 0; i < length; i++)
  {
    // If the character is NOT a space OR the last character was not a space 
    // then the character is not a consecutive space and we can write it to 
    // the new string.
    if (string[i] != ' ' || last_char_not_space)
    {
      // We write the new string over top of the old string.  Notice how j is 
      // only incremented if we write a character to the 'new copy string'
      string[j] = string[i];
      j++;
    }
    
    // Set last_char_not_space to true if the character is not a space, 
    // otherwise we set it to true.  In the next loop iteration the character
    // at the index i is the 'last character'.
    if (string[i] == ' ') last_char_not_space = false;
    else last_char_not_space = true;
  }

  // j has kept track of the number of chars in the new copy string, so we can
  // insert the null terminator at the index j to terminate the string  
  string[j] = '\0';
}
