/*******************************************************************************
*
* Program: Share Global Variable
* 
* Description: Example of sharing a global variable across multiple files using
* the extern keyword.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Wqm1tSzmqkY 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include "library.h" 

int main()
{
  // we can use the functions defined in our library as normal, and they will 
  // have access to the global variable number
  print();
  add_one();
  add_one();
  print();

  // but main.c ALSO has access to the global variable number because we 
  // used extern to declare it in library.h which is included by main.c
  number += 10;
  print();

  return 0;
}
