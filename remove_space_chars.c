/*******************************************************************************
*
* Program: Remove All Space Characters From A String
* 
* Description: Program to remove the space characters in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=y3rnTVwWmBY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void remove_spaces(char *string);

int main(void)
{
  // Create a test string
  char string[] = "A string with spaces in it";
  
  // Print the string before removing the space characters
  printf("Before:\n\n'%s'\n\n", string);
  
  // Call the function to remove the space characters from the string
  remove_spaces(string);
  
  // Print the string after removing the space characters
  printf("After:\n\n'%s'\n\n", string);
  
  return 0;
}

// Removes all space characters from the string provided as an argument
void remove_spaces(char *string)
{
  // Find the length of the string and store it into length.  The strlen()
  // function returns the length of the string not including the null
  // terminator character.
  int length = strlen(string);
  
  // Create a new "copy" of the string *inside* the existing string by copying 
  // each character from the string to the "copy" one character at a time EXCEPT
  // the space characters.  We use the counter variable j to keep track of the 
  // next index to use in the "copy" of the string, and we use counter variable 
  // i to loop through each index of the original string.  If we encounter a 
  // character that is NOT a space character we copy it from the original string
  // to the "copy" with string[j] = string[i], and we increment j as we have 
  // another character in the new "copy" string.  If the character we encounter
  // IS a space character, we DON'T increment j, but i will still be incremented
  // by the for loop.  This means we don't copy the character to the new "copy"
  // string.  We'll continue to overwrite the original string with the copy as 
  // we find more non-space characters, at which point j will continue to 
  // increment.
  //
  // So for example if we have the string:
  //
  // string:  a  ' '  b  ' '  \0
  //  index:  0   1   2   3   4
  //
  // By the end of this loop we'll have:
  //
  // string: a   b   b  ' '  \0
  //  index: 0   1   2   3    4
  //                 j        i
  //     i = 4
  //     j = 2
  //
  // Try tracing through the loop to observe this!  The last thing to do is 
  // put the null terminator at index j to end the string.
  //
  int j = 0;
  for (int i = 0; i < length; i++)
  {
    if (string[i] != ' ')
    {
      string[j] = string[i];
      j++;
    }
  }
  
  // Insert the null terminator to end the string
  string[j] = '\0';
}



// In this modification of the program, we use the isspace() function of the 
// ctype.h library to remove all whitespace characters from the string.  So
// newline \n and tab \t characters will be removed in addition to the space
// character, for example.

/*

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_spaces(char *string);

int main(void)
{
  char string[] = "A\tstring with\nspaces in it";

  printf("Before:\n\n'%s'\n\n", string);
  
  remove_spaces(string);
  
  printf("After:\n\n'%s'\n\n", string);
  
  return 0;
}

void remove_spaces(char *string)
{
  int length = strlen(string);
  
  int j = 0;
  for (int i = 0; i < length; i++)
  {
    if (!isspace(string[i]))
    {
      string[j] = string[i];
      j++;
    }
  }
  
  string[j] = '\0';
}

*/