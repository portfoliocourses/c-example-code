/*******************************************************************************
*
* Program: Seed With PID
* 
* Description: Example of seeding the random number generator in C with a 
* value that incorporates the process ID in addition to the current time.  If 
* we only use the current time, and the same program runs multiple times in 
* the same second, the sequence of random numbers will be the same in each 
* program's execution.  By incorporating the unique process ID for each 
* process into the seed value, we can make the seed value unique for each 
* process to prevent this from ocurring.
*
* YouTube Lesson: https://www.youtube.com/watch?v=zHZx9ByTo2s   
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
  // see the random number generator by factoring in the unique process ID 
  // TOGETHER with the current time, so that if multiple instances of the 
  // program run in the same second, the unique process ID of each will keep 
  // the seed value unique for each program
  srand( time(NULL) * getpid() );

  // generate the random value
  int rand_val = rand();

  // print out the random value, along with the process ID
  int pid = getpid();
  printf("rand: %10d, ", rand_val);
  printf("pid: %d\n", pid);
 
  return 0;
}