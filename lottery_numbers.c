/*******************************************************************************
*
* Program: Lottery Number Generator
* 
* Description: Example of generating lottery numbers in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=iIqjvB22APU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Generate 6 random numbers between 1-59 with no repeating values, as in a real
// lottery which will use 59 balls from 1-59 each with a unique value.
//
// Example: 7 14 21 33 42 55
//
int main()
{
  // seed the random number generator
  srand( time(NULL) );
 
  int number;
  int numbers[6];  // keeps track of the numbers generated so far
  bool unique;
  
  // generate and print the 6 numbers
  for (int i = 0; i < 6; i++)
  {
    // generate a unique number
    do
    {
      // generate a random number between 1-59
      number = (rand() % 59) + 1;

      // start off with the assumption the number is unique but check the
      // numbers we've generated so far to see if it is not unique
      unique = true;
      for (int j = 0; j < i; j++)
        if (numbers[j] == number) unique = false;

    // try again so long as the number generated is not unique
    } while (!unique);
    
    // add the number to the numbers array and print it out
    numbers[i] = number;
    printf("number %d: %d\n", i+1, number);
  }
  
  return 0;
}