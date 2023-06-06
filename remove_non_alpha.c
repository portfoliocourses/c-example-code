/*******************************************************************************
*
* Program: Remove Non Alphabet Characters From A String
* 
* Description: Remove the non-alphabetic characters from a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=pQOJT4C6ypk  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_non_alpha(char *string);

int main(void)
{
  // Test string stored in a char array
  char string[] = "a2%cd more 123(&% string 22";
  
  // Output the string before removing the non-alphabetic characters
  printf("Before: %s\n", string);
  
  // Call the function to remove the non-alphabetic characters.  Note that if 
  // you remove the below statement and replace it with the exact code in the
  // function body this will also work, if you prefer not to use a function.
  remove_non_alpha(string); 

  // Output the string after removing the non-alphabetic characters
  printf(" After: %s\n", string);
 
  return 0;
}

// Removes the non-alphabetic characters in the string pointed to by the 
// char pointer 'string'.
void remove_non_alpha(char *string)
{
  // Find the length of the string (not including the null terminator char)
  // and store it into the variable length.
  int length = strlen(string);
 
  // The algorithm to remove the non-alphabetic characters from the string works
  // by creating a 'new' string in the same char array that stores the original 
  // string, overwriting the original string with a new version of the string 
  // that does not include the null terminator.
  //
  // The loop uses a counter variable i that will go through each index of the 
  // original string from 0...length-1.  We use the isalpha() function to check
  // if the char is alphabetic (a-Z or A-Z) or not.  If the char is alphabetic,
  // we copy it into the new string.
  //
  // The new string is created using the help of the counter variable j that 
  // is also initialized to 0... j will track the length of the new string.  We 
  // copy the alphabetic character in the original string at the index i to the
  // new string at the index j, and we ONLY increment j in the case we have 
  // found an alphabetic character at the index i (the char in the original 
  // string we are 'currently examining' with our loop).  In this way, j keeps
  // track of the length of the new string, and the next index to copy the next 
  // alphabetic character into the new string.
  //
  // When the loop is done executing j will be set to the length of the new 
  // string with the non-alphabetic characters removed, and so we insert a 
  // null terminator character \0 at this index to terminate the new string.
  //
  int j = 0;
  for (int i = 0; i < length; i++)
  {
    if (isalpha(string[i]))
    {
      string[j] = string[i];
      j++;
    }
  }
  string[j] = '\0';
}