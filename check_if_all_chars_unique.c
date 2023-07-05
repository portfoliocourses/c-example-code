/*******************************************************************************
*
* Program: Check If All String Characters Are Unique
* 
* Description: Check if all the characters in a string are unique using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4E0IVfYJZcQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Two solutions to this problem are provided
bool all_unique(char *string);
bool all_unique2(char *string);

int main(void)
{
  // Test strings... string1 contains all unique chars, string2 does not
  char string1[] = "abcdefghi";
  char string2[] = "abcdbfghi"; 
  
  // Test the first function
  if (all_unique(string1))
  {
    printf("All string1 characters are unique.\n");
  }
  else
  {
    printf("All string1 characters are NOT unique.\n");
  }
   
  if (all_unique(string2))
  {
    printf("All string2 characters are unique.\n");
  }
  else
  {
    printf("All string2 characters are NOT unique.\n");
  } 

  // Test the 2nd function
  if (all_unique2(string1))
  {
    printf("All string1 characters are unique.\n");
  }
  else
  {
    printf("All string1 characters are NOT unique.\n");
  }
   
  if (all_unique2(string2))
  {
    printf("All string2 characters are unique.\n");
  }
  else
  {
    printf("All string2 characters are NOT unique.\n");
  }
  
  return 0;
}

// Returns true if all the characters in the string are unique, and false 
// otherwise.  Uses a simpler but less efficient algorithm.
bool all_unique(char *string)
{
  // Find the length of the string using the strlen() function 
  int length = strlen(string);
  
  // Loop through the string one character at a time from the first character
  // in the string to the last character in the string
  for (int i = 0; i < length; i++)
  {
    // For each character, we check the remaining characters in the string 
    // from the index 'i + 1' onwards.
    for (int j = i + 1; j < length; j++)
    {
      // If we find a character in the remaining portion of the string (index j)
      // that matches the character we are 'currently looking at' with the 
      // counter variable i of the outer loop, we have found a repeating 
      // character, and we can return false.
      if (string[i] == string[j])
      {
        return false;
      }
    }
  }
  
  // If we check all characters in the string and NONE of them repeat then all
  // the characters must be unique so we return true
  return true;
}

// Returns true if all the characters in the string are unique and false 
// otherwise.  Uses a more efficient algorithm than the above algorithm, as 
// the above algorithm involves "looping through" the string (or at least 
// portions of it) many times potentially, where as this algorithm involves 
// only one "pass/loop" through the string.
bool all_unique2(char *string)
{
  // There are 256 possible ASCII chars, and this function assumes our string
  // is made up of ASCII chars.  So we create a bool array of length 256, one
  // for each char, and initialize all elements to false.
  //
  // Each char is associated with an integer, so for example 'a' is equivalent
  // to the integer '97' in C.  So we'll set the index in the array associated
  // with each char to true when we encounter that character, to keep track of
  // which characters we've found so far!  
  bool found[256] = {false};
  
  // Using strlen() to find the length of the string involves another pass of 
  // the string in order for the function to determine it's length, so instead 
  // of using strlen() we'll stop the loop when we encounter the null terminator
  // \0 that is at the end of each string.
  //
  // Instead of using a counter variable 'i' we'll access the string characters
  // using pointer arithmetic and de-referencing.  string is initially a pointer
  // to the first character in the string, and:
  //
  // string++ will set string to point to the next character in the string
  // *string will de-reference the pointer and give us the char it's pointing to
  //
  while (*string != '\0')
  {
    // If the character in the string has already been found, we've found a 
    // repeat and can return false
    if (found[*string])
    {
      return false;
    }
    
    // Otherwise we have not found this character before, so we set the index
    // in the found array associated with this character to true to recognize 
    // that we have now found it.
    found[*string] = true;
    
    // Increment the string pointer so that it now points to the next char in
    // the string
    string++;
  }

  // Again if we go through all characters in the string and none of them are 
  // repeating all characters must be unique and we can return true 
  return true;
}