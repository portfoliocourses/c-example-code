/*******************************************************************************
*
* Program: Static Global Variable
* 
* Description: Example of how static global variables work in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=9Fs1tIWL-ac 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include "library.h"

int main()
{
  // the main function can access the functions defined in the external library
  add_one();
  print();
  
  // if we try to access the global variable defined in library.c, we will get
  // a compiler error because the variable is defined using the static keyword
  // number += 10;
  // print();

  return 0;
}
