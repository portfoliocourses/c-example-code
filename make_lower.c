/*******************************************************************************
*
* Program: Make All String Letters Lowercase
* 
* Description: Example of making all letters in a string lowercase in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=_8iq-iTh-Ns 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void make_lower(char *s);

int main()
{
  // test out the function
  char s[] = "Some String With LOTS OF Capitals";
  make_lower(s);
  printf("%s\n", s);
  
  return 0;
}

// makes all letters of the string s lower case
void make_lower(char *s)
{
  // get the length of the string
  int length = strlen(s);
  
  // convert each letter in the string to lowercase... tolower() will always
  // return the lowercase version of a letter if it is passed an uppercase 
  // letter, otherwise it will just return the original character it was passed 
  for (int i = 0; i < length; i++)
    s[i] = tolower(s[i]);
}
