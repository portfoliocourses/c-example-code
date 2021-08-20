/*******************************************************************************
*
* Program: Random number generation
* 
* Description: Example of generating random numbers in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) 
{
  // seed the random number generator with the current time so the numbers 
  // generated are different each time the program is run
  srand( time(NULL) );

  // generate 6 random numbers between 1-20
  for (int i = 0; i < 6; i++)
  {
    // rand() will produce a random number between 0 and RAND_MAX (a verylarge
    // int value), we modulus the result by 20 to produce a number between 
    // 0-19, and then add 1 to shift the range of random numbers to 1-20
    int random = 1 + (rand() % 20);

    printf("%d\n", random );
  }

  // RAND_MAX is the highest possible random number
  printf("RAND_MAX: %d\n", RAND_MAX);
  
  return 0;
}