/*******************************************************************************
*
* Program: isalnum() Demonstration
* 
* Description: Example of using the isalnum() function in C to check if a 
* character is alphanumeric or not (where an alphanumeric character is a letter
* or digit).
*
* YouTube Lesson: https://www.youtube.com/watch?v=pQka0CyFa7o
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // The alphanumeric characters are the characters: A-Z a-z 0-9
  //
  // All other characters are not alphanumeric characters.

  // Declare a test char variable c and assign it lowercase d which is an 
  // alphanumeric character.  Try setting c to different values and seethe 
  // effect.
  char c = 'd';   
  
  // The isalnum() function will return true if is passed an alphanumeric 
  // character and false otherwise. 
  if (isalnum(c)) 
  {
    printf("%c is alphanumeric\n", c);
  }
  else
  {
    printf("%c is not alphanumeric\n", c);
  }
  
  return 0;
}