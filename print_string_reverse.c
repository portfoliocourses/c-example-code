/*******************************************************************************
*
* Program: Print A String In Reverse
*
* Description: Program to print a string in reverse using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=OLEJy2gmvug
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
  // The characters in this string are stored in the indexes 0...3, with index
  // 4 storing the null terminator which terminates the string.
  //
  //               01234
  //                   \0
  char string[] = "maps";
  
  // strlen() returns the length of the string not including the null terminator
  // (4 in this case), which we store into length.
  int length = strlen(string);
  
  // The null terminator will be at the index length which means the last index
  // an actual string character is stored at will be length-1.  We start a loop
  // counter variable i off at this index, and with each loop iteration we print
  // the character at the index i and then decrement i.  In this way we go 
  // through the indexes of the string in reverse, from 3...0.  We stop the loop
  // once the counter variable i is no longer >= 0 as the last index in the 
  // string is 0.
  for (int i = length - 1; i >= 0; i--)
  {
    printf("%c", string[i]);
  }

  // Output a newline character after outputting the string in reverse
  printf("\n");
  
  return 0;
}
