/*******************************************************************************
*
* Program: Sleep
* 
* Description: Example of using sleep functions in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <unistd.h>

int main(void) 
{
  // printf before and after sleep functions to see the sleep time
  printf("before\n");

  // usleep will sleep for the number of microseconds given, a very small unit 
  // of time... the below will sleep for 0.75 seconds
  usleep(750000);

  // will sleep for 5 seconds
  // sleep(5);

  printf("after\n");

  return 0;
}
