/*******************************************************************************
*
* Program: Remove First Occurrence Of A Character From A String
*
* Description: Program to remove the first occurrence of a character in a string
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=80AuxBTYSeA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void remove_first(char string[], const char to_remove);

int main(void)
{
  // Test string and char to remove
  char string[] = "courses";
  char to_remove = 's';

  // Call function to remove first occurrence of char from string
  remove_first(string, to_remove);

  // Output resulting string
  printf("string: %s\n", string);
  
  return 0;
}

// Removes first occurrence of char to_remove from string
void remove_first(char string[], const char to_remove)
{
  // Find length of string (not including null terminator at the index length)
  int length = strlen(string);

  // Counter variable to iterate over string, initialize to first char index
  int i = 0;

  // Loop to find the index of the first occurrence of the character to_remove.
  //
  // We check if the character at the index i is the character we are looking 
  // for and if it is we stop the loop with break.  Otherwise we increment i
  // to check the next character in the string with the next loop iteration.
  //
  // The loop condition i < length will stop the loop once i == length, this
  // will occur if the characte NEVER occurs in the string.
  //
  while (i < length)
  {
    if (string[i] == to_remove) break;
    i++;
  }

  // Deletes the first occurrence of the character in the string by pulling 
  // forward all remaining characters in the string by one index.
  //
  // The character to remove is at the index i after the above loop executes.
  // With each loop iteration we take the character at the index i+1 (i.e. the
  // next character to the right) and copy it into the index i.  So the first 
  // time the loop body runs, the character to be deleted will be overwritten
  // by the character at the index i+1.  We increment i with each loop 
  // iteration to continue shifting over the remaining characters in the 
  // string.  Notably, the null terminator will also be shifted over by 
  // one index, lessening the length of the string by one character.  We stop
  // the loop once i == length.
  //
  //
  //      0    1    2    3    4    5    6    7     
  //                          i    i + 1
  //      c    o    u    r    s    e    s    \0
  //                          ^    |
  //                          |____|
  //
  // Notably if after executing the above loop i == length because the 
  // character to remove never occurs in the string, then this loop body 
  // will never execute (which is desired as there is no character to remove).
  //
  while (i < length)
  {
    string[i] = string[i + 1];
    i++;
  }
}
