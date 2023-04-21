/*******************************************************************************
*
* Program: ispunct() Demonstration
*
* Description: Example of using the ispunct() function in C to check if a char
* is a punctuation mark or not.
*
* YouTube Lesson: https://www.youtube.com/watch?v=E19Qni8HCmY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // The following characters are considered punctuation marks in C:
  //
  //      !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
  //
  // The ispunct() function will return true (i.e. a non-zero integer) if the
  // character it is passed as an argument is a punctuation mark, and false 
  // otherwise (i.e. the integer zero).


  // Try modifying what char c is set to and see the result!
  char c = '%'; 
  
  if (ispunct(c))
  {
    printf("%c is a punctuation mark.\n", c);
  }
  else
  {
    printf("%c is not a punctuation mark.\n", c);
  }
  
  return 0;
}
