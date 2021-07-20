/*******************************************************************************
*
* Program: Comments tutorial
* 
* Description: Examples of using comments in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

/*
* Multi-line comments might be used to create a "header" comment like this 
* explaining the purpose of the file... like this comment (or the header comment
* above!).
*
* Program Name: C program to demo comments
*
* Author: Kevin Browne
* 
* Date: July 11th 2021.
*
*/
#include <stdio.h>

#define LENGTH 10

int main(void)
{
  // set array to 0,1,2,3,4,5,6,7,8,9
  int array[] = {0,1,2,3,4,5,6,7,8,9};

  // computes the average of the array
  int total = 0;
  for (int i = 0; i < LENGTH; i++)
    total += array[i]; // add element to total

  /*
    Output the average to the user!

    Uses %d placeholder to ouput the average!


  */
  printf("Average: %d\n", total / LENGTH);

  return 0;
}
