/*******************************************************************************
*
* Program: Measure The Execution Time Of A Function
* 
* Description: Example of measuring the execution time of a function call in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=wENmybEjyjo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <time.h>

// A simple function which does some work
void function()
{
  for (int i = 0; i < 2000000000; i++)
  {
    int result = i + 1;
  }
}

int main(void)
{
  // Store clock ticks / "processor time"
  clock_t start, end;

  // Will be used to store time in seconds
  double time;
  
  // Record the clock ticks BEFORE running the function
  start = clock();
  
  // Run the function
  function();
  
  // Record the clock ticks AFTER running the function
  end = clock();
  
  // If we subtract the start clock ticks from the end clock ticks this will 
  // give us the total clock ticks for the function() to run.  We can then 
  // divide this number of clock ticks by CLOCKS_PER_SEC (i.e. the clock ticks
  // per second) to the total seconds elapsed.  We store this as a double 
  // value into time.
  time = (double) (end - start) / CLOCKS_PER_SEC; 
  
  // Output the execution time in seconds
  printf("Execution Time:\n%fs\n", time);

  // Important: the value returned by the clock() function will 'wrap around'
  // at some regular interval like 36 minutes or 72 minutes, i.e. the function
  // will return the same value again.  This means this technique is not 
  // suitable for measuring longer execution times.
  //
  // Also note that a call to system() in-between the calls to clock() *may* 
  // reset the values returned by  clock() and break this technique. 

  return 0;
}