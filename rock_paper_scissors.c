/*******************************************************************************
*
* Program: Rock Paper Scissors Game
* 
* Description: Implementation of rock paper scissors game in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=e8NZrbhKXDs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// we define constants for ROCK, PAPER, SCISSORS to make our code easier to read
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main()
{
  // seed the random number generator with the current time to get different 
  // random numbers each time the program is run
  srand( time(NULL) );
  
  int player_throw = 0;
  int ai_throw = 0;
  bool draw = false;
  
  do
  {
    // accept the player throw
    printf("Select your throw.\n");
    printf("1) Rock\n");
    printf("2) Paper\n");
    printf("3) Scissors\n");
    printf("Selection: ");
    scanf("%d", &player_throw);
    
    // randomly generate the AI throw (where 1-3 represent rock/paper/scissors 
    // as defined above)
    ai_throw = (rand() % 3) + 1;
    
    // output the AI's throw to the player
    if (ai_throw == ROCK)
      printf("\nAI throws ROCK.\n");
    else if (ai_throw == PAPER)
      printf("\nAI throws PAPER.\n");
    else if (ai_throw == SCISSORS)
      printf("\nAI throws SCISSORS.\n");
    
    // determine and output the winner, if any
    draw = false;
    if (player_throw == ROCK && ai_throw == SCISSORS)
      printf("\nROCK beats SCISSORS. YOU WIN.\n\n");
    else if (player_throw == ROCK && ai_throw == PAPER)
      printf("\nPAPER beats ROCK. YOU LOSE.\n\n");
    else if (player_throw == SCISSORS && ai_throw == PAPER)
      printf("\nSCISSORS beats PAPER. YOU WIN.\n\n");
    else if (player_throw == SCISSORS && ai_throw == ROCK)
      printf("\nROCK beats SCISSORS. YOU LOSE.\n\n");
    else if (player_throw == PAPER && ai_throw == ROCK)
      printf("\nPAPER beats ROCK. YOU WIN.\n\n");
    else if (player_throw == PAPER && ai_throw == SCISSORS)
      printf("\nSCISSORS beats PAPER. YOU LOSE.\n\n");
    else
    {
      // if both player and AI throw the same, it's a draw
      printf("\nDRAW! Play again.\n\n");
      draw = true;
    }
  
  // in the case of a draw, the game is played again until there is a winner
  } while (draw);

  return 0;
}