/*******************************************************************************
*
* Program: atexit() Demonstration
* 
* Description: Example of how to use the atexit() function in C to assign a 
* function to run when the program exits.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Ik3nzpn5LoE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t start, end;

void cleanup();

int main(void)
{
  // record the start time of the program's execution
  time(&start);
  
  // set the cleanup function to run when the program exits
  atexit(cleanup);
  
  // ask the user to enter a value and output the value in order to have our 
  // program "do some work", we can decide how long to pause to enter the 
  // value which will cause different execution times to be output by the 
  // cleanup function
  int value = 0;
  printf("Enter: ");
  scanf("%d", &value);
  printf("value: %d\n", value);

  // it doesn't matter whether our program exits due to a return statement or 
  // using the exit() function, functions assigned to run on exit by atexit()
  // will run in either case
  // exit(0);
  
  return 0;
}

// cleanup function that is scheduled to run at exit will record the end time, 
// find the difference between start and end time, and output that difference
void cleanup()
{
  time(&end);
  double diff = difftime(end, start);
  printf("Execution time: %f\n", diff);
}