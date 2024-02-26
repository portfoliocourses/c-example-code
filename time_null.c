/*******************************************************************************
*
* Program: time(NULL) Explained
*
* Description: Example code to help explain what is returned when the time() 
* function is passed the argument NULL in C, including why it is often used 
* with srand() to provide a seed value for random number generation.
*
* YouTube Lesson: https://www.youtube.com/watch?v=7aijdLcJms0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int main(void)
{ 
  // The time function will return the current time as a time_t type value 
  // when it is called with NULL.  The exact type of time_t is not defined by
  // the C standard, other than being an arithmetic type which can represent
  // time.  Typically time_t is an integral type value (i.e. some type of 
  // integer value), and typically it is the number of seconds since 
  // January 1st, 1970 at 00:00:00 UTC (known as the Unix epoch).  For example
  // POSIX systems will represent time this way.
  //
  // We can store the current time returned by time(NULL) into a time_t type
  // variable (though we could use something like long instead)!
  //
  time_t current_time = time(NULL);
  
  // Output the current time using %ld because on the system/compiler this 
  // program was written in time_t is a long value, we'll see it's the 
  // number of seconds since the Unix epoch.
  printf("%ld\n", current_time);
  
  // We can divide the number of seconds by 60 (the number of minutes) and 
  // then by 60 again (the number of hours) and then by 24 (the number of days)
  // and then by 365 (the number of years) to get approximately the time in 
  // years since the Unix epoch.
  printf("%f\n", (((1708722118.00 / 60) / 60) / 24) / 365);
  
  // In examples online time(NULL) is often use to seed the random number 
  // generator in C using srand().  C has what is called pseudorandom number
  // generation, which means in order for the rand() function to return a 
  // potentially different sequence of random integers each time the program 
  // is run we need to provide it with a potentially different integer each
  // time the program is run.  The current time is likely to be different each
  // time our program is run, and so we supply it to srand() as a seed value.
  //
  srand( time(NULL) );
  
  // We'll see rand() returns a different sequence of random non-negative 
  // integers each time the program is run if we use srand() as above, but if
  // we were to comment out that line rand() would return the same sequence
  // of random integers each time the program is run.
  printf("%d\n", rand());
  printf("%d\n", rand());
  printf("%d\n", rand());

  return 0;
}