/*******************************************************************************
*
* Program: Fill An Array With Random Values
* 
* Description: Example of filling an array with random values between 1 and a
* max value using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=5OFLit1Zf-Q
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_random(int array[], int length, int max);

int main(void)
{
  // seed the random number generator with a different value (the current time)
  // each time the program runs to ensure we get different random numbers each
  // time the program runs
  srand( time(NULL) );
  
  // create an int array of length 100
  int a[100];

  // fill the array a with random integers between 1-200
  fill_random(a, 100, 200);
  
  // output the numbers in the array to verify correctness
  for (int i = 0; i < 100; i++)
    printf("a[%d]=%d\n", i, a[i]);
  
  return 0;
}

// fills the array of the given length with random integers between 1 - max
void fill_random(int array[], int length, int max)
{
  // loop through each index of the array... rand() % max will produce a 
  // random number between 0 - (max-1), adding 1 will shift it to 1 - max
  for (int i = 0; i < length; i++)
    array[i] = (rand() % max) + 1;
}