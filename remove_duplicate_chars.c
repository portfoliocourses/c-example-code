/*******************************************************************************
*
* Program: Remove Duplicate Characters From A String
*
* Description: How to remove duplicate occurrences of characters from a string
* in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4iaYlp-axac
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void remove_duplicates(char *string);

int main(int argc, char *argv[])
{
  // Create a test string with many duplicate characters
  char s[] = "aaaaabbbbbcccccaaaaddddeeee";

  // Call the remove_duplicates() function remove the duplicates from the string
  remove_duplicates(s);

  // Output the resulting string to confirm the duplicates have been removed
  printf("%s\n", s);

  return 0;
}

// Removes the duplicates from the string provided as an argument
void remove_duplicates(char *string)
{
  // Find the length of the string (not including the null terminator character
  // that ends the string) using the string length strlen() function of the
  // string.h library.
  int length = strlen(string);

  // The outter-most loop will have a counter variable i go from 0 to the length
  // of the string, incrementing by 1 with each loop iteration, so that we
  // loop through each index of the string.  We can say that the character at
  // the index i is the character we are currently examining to establish if
  // any duplicates exist in the string.
  for (int i = 0; i < length; i++)
  {
    // We search the remaining portion of the string from character we are
    // currently examining to see if there are any duplicate occurrences of the
    // character. We have counter variable j go from i+1 (the index of the next
    // character from the one we are currently examining) up until the length
    // of the string, so that we can use j to check the remaining characters
    // in the string for any that match the character we are currently
    // examining (i.e. a duplicate).
    for (int j = i + 1; j < length; )
    {
      // Check if we've found a duplicate character
      if (string[i] == string[j])
      {
        // If we have found a duplicate charater at index j, we remove it by
        // shifting forward by one index all the remaining characters in
        // the string.
        for (int k = j; k < length; k++)
          string[k] = string[k + 1];

        // This will shorten the string by one character, so we decrement
        // length by one to reflect this.
        length--;
      }
      // If we DID find a duplicate character at the index j it will have been
      // removed and a new character (the character previously at index j + 1)
      // wil have taken its place.  So we only increment j to check the next
      // character in the remaining portion of the string if the character at
      // index j was NOT removed (i.e. it was not a duplciate).
      else j++;
    }
  }
}