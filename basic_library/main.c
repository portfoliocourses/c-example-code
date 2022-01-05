/*******************************************************************************
*
* Program: Basic Library Example
* 
* Description: An example of the basics of creating a library in C to split our
* program across multiple files.
*
* YouTube Lesson: https://www.youtube.com/watch?v=x8gsHFBW7zY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include "library.h"

int main()
{
  printf("%d + %d = %d\n", 4, 5, add(4,5));  
  printf("%d - %d = %d\n", 10, 7, sub(10,7));

  return 0;
}
