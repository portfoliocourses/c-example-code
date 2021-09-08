/*******************************************************************************
*
* Program: Remove trailing whitespace string characters demonstration
* 
* Description: Example of removing the trailing whitespace string characters
* in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=3ME0l0trRsE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void trim(char *s);

int main() 
{
  // string has trailing white space characters ' ' , \n (newline) and \t (tab)
  char s[] = "This is the way. \n\n\t ";
  
  // print out the string 
  printf("Before:\n\n %s", s);

  // remove the whitespace chars
  trim(s);
  
  // print out the string after the white chars have been removed
  printf("\nAfter:\n\n");
  printf("%s\n", s);

  return 0;
}

// removes trailing whitespace characters from string s
void trim(char *s)
{
  // start the index at the last character in the string (that is not the null
  // terminator)
  int i = strlen(s) - 1;
  
  // unless we've reached the end of the string, keep examining characters
  while (i >= 0)
  {
    // if we ecounter a whitespace character, keep checking backwards through 
    // the string, otherwise break as we have found the end of the trailing 
    // whitespace characters
    if (s[i] == ' ' || s[i] == '\n' ||
        s[i] == '\t') i--;
    else break;
  }
  
  // set the null terminator where the final whitespace character occurs to 
  // end the string here
  s[i + 1] = '\0';
}







