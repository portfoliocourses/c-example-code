/*******************************************************************************
*
* Program: Trim leading whitespace characters demonstration
* 
* Description: Example of how to trim leading whitespace characters from a 
* string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=f0BqwfVACKY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void trim(char *s);

int main() 
{
  // string has space, newline and tab leading whitespace characters
  char s[] = "  \n\n\t  This is the way.";
  
  // print out the string before trimming the leading whitespace characters
  printf("before: \n%s\n", s);
  
  // call the function to trim the leading whitespace characters
  trim(s);
  
  // print out the string after trimming the leading whitespace characters
  printf("after: \n%s\n", s);

  return 0;
}

// the function to trim the leading whitespace characters accepts the string 
// as an argument
void trim(char *s)
{
  // count the number of leading whitespace characters
  int count = 0;
  while (s[count] == ' ' || s[count] == '\n' || s[count] == '\t') count++;

  // if no whitespace characters were found, we don't need to do anything!
  if (count != 0)
  {
    // shift the remainder of the string contents up by the number of leading
    // white space characters found
    int i = 0;
    while (s[i + count] != '\0')
    {
      s[i] = s[i + count];
      i++;
    }

    // terminate the string earlier given that the contents are being reduced,
    // the null terminator is shifted up by the number of leading whitespace 
    // characters as well
    s[i] = '\0';
  }
}




