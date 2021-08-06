/*******************************************************************************
*
* Program: Exit function
* 
* Description: Examples of using the exit() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=8RucxSeAemw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void func();

int main(void)
{
  printf("Hello, World!\n");

  // We can use exit to exit the program at any point during its execution
  // the exit status of our program (0 for success, anything else is failure) 
  // is given as an argument to the exit function.
  // exit(1);
  printf("Some other text!\n");

  func();

  // Normally our program exits when a return statement is encountered in main
  return 0;
}

void func()
{
  printf("In the func()\n");

  // With exit() we can exit the program in the middle of a function, e.g. 
  // perhaps due to some error our program can on longer continue.  We can 
  // use constants EXIT_FAILURE an EXIT_SUCCESS to exit with success or 
  // failure.
  exit(EXIT_FAILURE);
  printf("Below the exit in func!\n");
}
