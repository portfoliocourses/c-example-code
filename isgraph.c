/*******************************************************************************
*
* Program: isgraph() Demonstration
*
* Description: Example of using the isgraph() function in C to check if a char
* is graphical or not.  
*
* YouTube Lesson: https://www.youtube.com/watch?v=9mGHjuQoXK0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // The graphical characters are the alphanumeric characters and punctuation
  // characters which have a graphical representation.  i.e. A-Z a-z 0-9 and 
  // symbols like .; etc.
  //
  // Characters like the space character ' ' or newline \n and tab \t are not 
  // graphical characters, and neither are control characters, e.g. backspace.
  
  // Try modifying what char c is set to and see the result!
  char c = 'T';
  
  if (isgraph(c))
  {
    printf("'%c' is a graphical character\n", c);
  }
  else
  {
    printf("'%c' is not a graphical character\n", c);
  }
  
  return 0;
}