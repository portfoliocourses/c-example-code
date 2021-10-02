/*******************************************************************************
*
* Program: Make All String Letters uppercase
* 
* Description: Example of making all letters in a string uppercase in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=HJupPQVx2QI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void make_upper(char *s);

int main()
{
  // test out the function
  char s[] = "Some string with many lowercase LETTERS";
  make_upper(s);
  printf("%s\n", s);
  
  return 0;
}

// makes all letters of the string s upper case
void make_upper(char *s)
{
  int length = strlen(s);

  // convert each letter in the string to uppercase... toupper() will always
  // return the uppercase version of a letter if it is passed an lowercase 
  // letter, otherwise it will just return the original character it was passed   
  for (int i = 0; i < length; i++)
    s[i] = toupper(s[i]);
}
