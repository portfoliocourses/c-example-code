/*******************************************************************************
*
* Program: Loop Through A String Without Using strlen()
* 
* Description: An example of how to loop through a string without using the 
* strlen() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=dxrKTGGsGqI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
 
int main(void)
{
  // Store a test string into a char array.  Let's imagine the string has come
  // from somewhere like user input at runtime and so we don't know the length
  // of the string until the program execute.
  // 
  //               0123456   <-- each char in the string is stored at an index
  char string[] = "ABCDAB";
  //                     \0  <-- the last index stores the null terminator 
  //                             which ends the string
  
  // To iterate over a string means to "loop through and access" each character
  // in the string.

  // Approach #1 - Use strlen()
  //
  // The strlen() function returns the length of the string not including the
  // null terminator character, so we will get a length of 6 with the above
  // string.  We use a loop with a counter variable i to go through each 
  // index of the string from 0...length-1 with each iteration, and we
  // output the character.
  //
  /*
  int length = strlen(string); 

  for (int i = 0; i < length; i++)
  {
    printf("%c\n", string[i]);
  }
  */

  // Approach #2 - Detect Null Terminator 
  //
  // We know that a null terminator ends the string so we stop iterating i
  // once the character at that index is equal to the null terminator!
  //
  for (int i = 0; string[i] != '\0'; i++)
  {
    printf("%c\n", string[i]);
  }

  // Alternatively we could just have...
  //
  // for (int i = 0; string[i]; i++)
  //
  // Because characters that are not the null terminator are considered true
  // in C and the null terminator is considered false.

  // We may want to consider checking to ensure i does not exceed some upper
  // bound (say the length of the char array in which the string is stored)
  // in order to make sure we don't access memory that we shouldn't IF it's
  // possible that the string doesn't end with the null terminator (which 
  // would no longer be a proper string in C, but perhaps it's possible in 
  // the context of what our program is doing).
  //
  // for (int i = 0; string[i] && i < MAX; i++)

  return 0;
}