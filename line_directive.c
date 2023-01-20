/*******************************************************************************
*
* Program: #line Preprocessor Directive
* 
* Description: Example of using the line preprocessor directive in C to alter
* the __FILE__ and __LINE__ predefined macros.
*
* YouTube Lesson: https://www.youtube.com/watch?v=m3d5XIv3Fr4 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

int main(void)
{
  #line 51 "origin.c" 
  printf("error @ %s:%d\n", __FILE__, __LINE__);
  
  printf("again @ %s:%d\n", __FILE__, __LINE__);

  return 0;
}

//  origin.c   ->   file.c   
//
//  line 51    ->   line 9 code