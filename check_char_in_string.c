/*******************************************************************************
*
* Program: Check If A Character Is In A String Algorithm
*
* Description: Check if a character is in a string algorithm implementation in
* C, i.e. without using the built-in strchr() function but instead implementing
* a solution.
*
* YouTube Lesson: https://www.youtube.com/watch?v=WcagDRFHeMo
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool find_character(char string[], char to_find);

int main(void)
{
  // Test string and character to find
  char string[] = "abcdefg"; 
  char to_find = 'z';
  
  // Call function to check if character is in the string
  bool found_character = find_character(string, to_find);
  
  // Output whether the character was found or not
  if (found_character)
  {
    printf("Found '%c'.\n", to_find);
  }
  else
  {
    printf("Did not find '%c'.\n", to_find);
  }
  
  return 0;
}

// Returns true if character 'to_find' is found in the string 'string'
bool find_character(char string[], char to_find)
{
  // Find the length of the string
  int length = strlen(string);
  
  // Loop through each index in the string with counter variable i 
  // going from 0...length-1.  We check all characters in the string
  // to see if any is equal to to_find, when we find one we can just 
  // return true because there is no need to search the rest of the string.
  for (int i = 0; i < length; i++)
  {
    if (string[i] == to_find) return true;
  }
  
  // If we go through all characters in the string and never find the 
  // character is must not be in the string so we can return false
  return false;
}


