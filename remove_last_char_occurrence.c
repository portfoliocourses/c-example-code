/*******************************************************************************
*
* Program: Remove Last Occurrence Of A Character In A String
*
* Description: Program to remove the last occurrence of a character in a string
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=98tA7W9Hm1k
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void remove_last(char string[], const char to_remove);

int main(void)
{
  // Create a test string
  char string[] = "Microsoft";

  // Character to remove the last occurrence of in the string
  char to_remove = 'o';
  
  // Call function to remove last character
  remove_last(string, to_remove);
  
  // Output the resulting string
  printf("%s\n", string);

  return 0;
}

// Removes last occurrence of the character to_remove from string
void remove_last(char string[], const char to_remove)
{
  // Find the length of the string
  int length = strlen(string);

  // Will store the index of the last occurrence of the character found in
  // the string
  int last_occurrence_index = -1;
  
  // Loop through each string index from 0...length-1, if the character at
  // the index i is equal to to_remove we have found a 'later' occurrence of
  // the character in the string and so we update last_occurrence_index
  for (int i = 0; i < length; i++)
  {
    if (string[i] == to_remove)
    {
      last_occurrence_index = i;
    }
  }
  
  // If after the above loop runs last_occurrence_index is still -1 that means
  // we NEVER found an occurrence of the character in the string and so we 
  // do nothing, only if we found an occurrence of the character (at an index 
  // that will be greater than -1) do we remove the last occurrence of the 
  // character from the string.
  if (last_occurrence_index > -1)
  {
    // Loop through the string indexes with the counter variable i beginning 
    // at the index of the last occurrence of the character and "pull forward"
    // all the remaining characters in the string (including the null 
    // terminator at the end of the string).  We do this by storing the 
    // character at the index i + 1 at the index i.  
    for (int i = last_occurrence_index; i < length; i++)
    {
      string[i] = string[i + 1];
    }

    // So for example in the first iteration of the loop f at the index 7 
    // will be copied to the index 6...
    //
    //                           i  i + 1
    //                            __
    //                           |  | 
    // string: M  i  c  r  o  s  o  f  t  \0
    //  index: 0  1  2  3  4  5  6  7  8  9
    //                           |                        
    //                           last_occurrence_index
  }
}