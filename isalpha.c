/*******************************************************************************
*
* Program: isalpha() Demonstration
*
* Description: Example of using the isalpha() function in C to check if a char
* is alphabetic or not.
*
* YouTube Lesson: https://www.youtube.com/watch?v=qacVTseCeF8
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // The alphabetic characters are the characters: A-Z a-z
  //
  // All other characters are not alphabetic characters.
  
  // Try modifying what char c is set to and see the result!
  char c = 'T';
  
  if (isalpha(c))
  {
    printf("%c is an alphabetic character\n", c);
  }
  else
  {
    printf("%c is not an alphabetic character\n", c);
  }
  
  return 0;
}
