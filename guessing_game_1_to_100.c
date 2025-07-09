/*******************************************************************************
*
* Program: Number Guessing 1-100 Game
* 
* Description: Example of a number guessing 1-100 game in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=3F3XpSJ5obk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
  int number = 0;
  int guess = 0;
  int attempts = 0;
  const int max_attempts = 6;
  
  srand(time(0));
  number = rand() % 100 + 1;
  
  printf("\n********** Guessing Game **********\n");
  printf("I have selected a number between 1 and 100.\n");
  printf("You have %d attempts to guess it.\n", max_attempts);

  while (attempts < max_attempts) 
  {
    printf("\nEnter your guess: ");
    scanf("%d", &guess);
    attempts++;

    if (guess > number) 
    {
      printf("\nToo high!\n");
    } 
    else if (guess < number) 
    {
      printf("\nToo low!\n");
    } 
    else 
    {
      printf("\nCongratulations!\n");
      printf("You guessed the number in %d attempts!\n", attempts);
      break;
    }

    if (attempts == max_attempts) 
    {
      printf("\nYou've used all %d attempts.\n", max_attempts);
      printf("The correct number was %d.\n", number);
      printf("Better luck next time!\n");
    } 
    else 
    {
      printf("You have %d attempt(s) left.\n", max_attempts - attempts);
    }
  }

  printf("\nThanks for playing!\n");

  return 0;
}