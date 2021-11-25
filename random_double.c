/*******************************************************************************
*
* Program: Random Double Generation
* 
* Description: Example of a function to generate a random double value between
* a min and max value in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=3jnrbtoWgDo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rand_range(double min, double max);

int main(void)
{
  // seed the random number generator with the current time to ensure different 
  // random numbers each time the program executes
  srand(time(NULL));
  
  // generate and print out 50 random numbers between -5 and 5
  for (int i = 0; i < 50; i++)
    printf("%f\n", rand_range(-5,5));
  
  return 0;
}

// returns a negative double number in the range of min-max
double rand_range(double min, double max)
{
  // rand() will produce a random integer between 0 ... RAND_MAX where RAND_MAX 
  // is a very large number... by dividing this number by RAND_MAX we will get 
  // a number in the range 0 ... 1.  We typecast rand() to a double to ensure 
  // that double division takes place as opposed to interger division which 
  // would result in 0 OR 1 exactly.
  double random = ((double) rand()) / RAND_MAX;
  
  // Take the number between 0-1 above and multiply it by (max - min) to get a 
  // number in the range of 0 ... (max - min)
  double range = (max - min) * random;
  
  // take this number in the range of 0 - (max-min) above and add min to it to 
  // get a number in the range of min ... max (adding min to 0 give us min, 
  // adding min to max-min gives us back max!)
  double number = min + range;
  
  return number;
}