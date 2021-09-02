/*******************************************************************************
*
* Program: String length function demonstration
* 
* Description: Creating our own string length function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=0EOKOlV8Dbg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int string_length(char *string);

int main(void) 
{
  // string.h includes a strlen() function built-in that can find the length of
  // a string, which we test here, but it does NOT include the null terminator 
  // in the length of the string
  char *s1 = "This is the way.";
  int length = strlen(s1);
  printf("length: %d\n", length);
  
  // let's test our string length function
  int our_length = string_length(s1);
  printf("our length: %d\n", our_length);

  return 0;
}

// accepts a string as an argument and returns the length of the string 
// INCLUDING the null terminator
int string_length(char *string)
{
  // loop through each char of the string until we encounter the null terminator
  // that signifies the end of the string, return the number of chars 
  // encountered (which we keep track of with length) plus one for the null 
  // terminator too
  int length = 0;
  while (string[length] != '\0') length++;
  return length + 1;
}



