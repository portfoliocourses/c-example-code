/*******************************************************************************
*
* Program: abort() Demonstration
* 
* Description: Example of using the abort() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=yi4nomTUR6U 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void cleanup();

int main(void)
{
  // set the cleanup function to run on exit
  atexit(cleanup);

  printf("Hello, World!\n");

  // We call the abort function with no arguments, notice how in comparison 
  // to exit it does not run the cleanup function.  Depending on the C 
  // implementation abort may also not close files, delete temporary files, 
  // or flush the stream buffer.  It will however do a core dump which may 
  // be useful for debugging our program. 
  abort();
  
  // the exit function will run the cleanup function, comment out abort above
  // and uncomment exit below to see the difference!
  // exit(0);

  return 0;
}

// a cleanup function like this might normally be run on exit to do some 
// cleanup work for our program
void cleanup()
{
  printf("Doing cleanup!\n");
}
