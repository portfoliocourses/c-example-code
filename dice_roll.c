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
  srand( time(NULL) );

  int dice = 10;
  int roll = 0;

  for (int i = 1; i <= dice; i++)
  {
    roll = rand() % 6 + 1;
    printf("Dice %d: %d\n", i, roll);
  }

  return 0;
}