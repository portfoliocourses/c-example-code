/*******************************************************************************
*
* Program: Coin Toss Simulator
* 
* Description: Example of simulating a coin flip in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1hUF8IAP-P8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// create a new type coin that cain be either HEADS or TAILS
typedef enum coin {HEADS, TAILS} coin;

coin flipCoin();

int main()
{
  // seed the random number generator to ensure pseudorandom random numbers
  srand(time(NULL));
  
  // perform 10 coin flips and output the result
  for (int i = 0; i < 10; i++)
    if (flipCoin() == HEADS) printf("HEADS\n");
    else printf("TAILS\n");

  return 0;
}

// performs a coin flip and returns either HEADS or TAILS
coin flipCoin()
{
  // rand() returns a positive int value, so if we take that and mod it by 2 
  // we will get 0 if the number is even (divisible by 2) and 1 if it is not...
  // we'll use this to determine whether to return HEADS or TAILS given it is a 
  // 50/50 chance the number is even or odd
  if (rand() % 2 == 0) return HEADS;
  else return TAILS;
}
