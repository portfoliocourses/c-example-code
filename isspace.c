/*******************************************************************************
*
* Program: isspace() Demonstration
* 
* Description: Example of using the isspace() function in C to check if a 
* character is a whitespace character or not.
* or digit).
*
* YouTube Lesson: https://www.youtube.com/watch?v=2uws6w63wUU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // The whitespace characters are the characters:
  //
  //   ' '   space
  //   '\n'  newline
  //   '\t'  horizontal tab
  //   '\v'  vertical tab
  //   '\f'  form feed
  //   '\r'  Carriage return  
  //
  // All other characters are not whitespace characters.

  // Declare a test char variable c and assign it the tab char which is an
  // whitespace character.  Try setting c to different values and see the 
  // affect.
  char c = '\t';
  
  // The isspace() function will return true if is passed a whitespace 
  // character and false otherwise.   
  if (isspace(c)) 
  {
    printf("'%c' is a whitespace character.\n", c);
  }
  else
  {
    printf("'%c' is not a whitespace character.\n", c);
  }
  
  return 0;
}