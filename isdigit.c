/*******************************************************************************
*
* Program: isdigit() Demonstration
*
* Description: Example of using the isdigit() function in C to check if a char
* is a digit or not.
*
* YouTube Lesson: https://www.youtube.com/watch?v=tzwdohXjB_Q
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // The characters 0-9 are digits, all other characters are not.
  //
  // Try modifying what the char variable c is set to below and see the effect!

  char c = '7';
  
  if (isdigit(c)) 
  {
    printf("%c is a digit\n", c);
  }
  else
  {
    printf("%c is not a digit\n", c);
  }
  
  return 0;
}