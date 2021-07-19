/*******************************************************************************
*
* Program: Main return value tutorial
* 
* Description: Examples of main return values in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

int main(void)
{
  int input = 0;
  printf("Enter: ");
  scanf("%d", &input);

  // Returning the value 0 signals to the shell/terminal that the program has 
  // exited successfully, and anything else signals an issue/error.
  if (input > 5) return 0;
  else return 1;
}


