/*******************************************************************************
*
* Program: Remove All Punctuation Marks From A String
*
* Description: Program to remove all punctuation marks from a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=LaVEDKSTYQs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void remove_punctuation(char string[]);

int main(void)
{
  // Test string with two punctuation marks . and ;
  char string[] = "4.5;";
  
  // Call function to remove punctuation marks
  remove_punctuation(string);
  
  // Output the resulting string
  printf("%s\n", string);
  
  return 0;
}

// Removes punctuation marks in the string
void remove_punctuation(char string[])
{
  // Find the length of the string not including the null terminator
  int length = strlen(string);
  
  // Counts the number of characters in the copy of the string without the
  // punctuation marks included
  int j = 0;
  
  // Builds a copy of the string without punctuation marks by writing over top
  // of the existing string.  The loop goes through each index of the string 
  // from 0...length-1 with each loop iteration.  Each time we check to see 
  // if the character is NOT a punctuation mark (using ispunct() which returns
  // true if the character it is passed as an argument is a punctuation mark
  // and false otherwise).  ONLY if the character is not a punctuation mark 
  // do we copy it to the new version of the string we are building, storing
  // the string at index j (the next index of the new string we are building)
  // and incrementing j (for the index of the next character to store).  The
  // impact will be to overwrite the existing string with a new copy of the 
  // string, e.g.
  //
  // indexes: 01234
  //              i
  //     old: 4.5;\0
  //     new: 45
  //            j
  //
  // This is the state after the loop executes, with j incremented twice 
  // and 4 and 5 stored at indexes 0 and 1.  Notably j is positioned where
  // the null terminator should be stored to end the string.
  //
  for (int i = 0; i < length; i++)
  {
    if (!ispunct(string[i]))
    {
      string[j] = string[i];
      j++;
    }
  }
  
  // Store the null terminator at index j to end the string
  string[j] = '\0';
}