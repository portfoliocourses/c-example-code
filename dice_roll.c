/*******************************************************************************
*
* Program: Dice roll simulator
* 
* Description: An example of how to simulate dice rolls.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4FCxXG44SFM
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  // Seeds the random number generator
  srand( time(NULL) );

  // dice stores the number of dice rolls, roll will store each roll
  int dice = 10;
  int roll = 0;

  // conduct each dice roll and output the result
  for (int i = 1; i <= dice; i++)
  {
    // rand() % 6 produces a random number between 0-5, add 1 to shift to 1-6
    roll = rand() % 6 + 1;
    printf("Dice %d: %d\n", i, roll);
  }

  return 0;
}
