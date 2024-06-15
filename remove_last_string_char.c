/*******************************************************************************
*
* Program: Remove The Last Character In A String
* 
* Description: Program to remove the last character in a string using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=pMEWGLlairs
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
  // A string with 4 characters.  At the index 4 the null terminator character
  // terminates the string.  We can remove the last character of the string by
  // storing a null terminator one index earlier.
  //
  //        index: 01234
  //                   \0
  char string[] = "abcd";
  
  // We can manually find the index of the null terminator by creating a counter
  // variable i, and incrementing i using a loop until i reaches the index of 
  // the null terminator.
  int i = 0;
  while (string[i] != '\0') i++;
  
  // Then we can store a null terminator one index earlier, at i - 1
  string[i - 1] = '\0';

  // Another technique would be to use the strlen() function to find the length
  // of the string (i.e. the number of characters in the string not including 
  // the null terminator).  So for this string the length would be 4, which is
  // also where the null terminator is currently stored.  If we then store 
  // a null terminator one index earlier this would remove the last character
  // in the string.
  //
  // string[strlen(string) - 1] = '\0';
  
  // Output the resulting string
  printf("%s\n", string);
  
  return 0;
}