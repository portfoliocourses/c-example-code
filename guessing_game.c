/*******************************************************************************
*
* Program: Number Guessing Game
* 
* Description: Example of a number guessing game in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=41NmcgA1HF0  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // seed the random number generator to ensure pseudorandom number generation
  srand(time(NULL));
  
  // generate a random number between 1-100
  // rand() will return a random int value between 0 and a large number, mod 100
  // will turn that number into a 0-99 range, and +1 shifts that range to 1-100!
  int number = (rand() % 100) + 1;
  int guess = 0;
  
  do
  {
    // ask the user to guess
    printf("Enter a Guess: ");
    scanf("%d", &guess);
    
    // if they get the answer right let them know, otherwise guide them in the 
    // right direction lower or higher
    if (guess == number) printf("You got it!\n");
    else if (guess < number) printf("Guess higher!\n");
    else printf("Guess lower!\n");
    
    // keep allowing the user to guess until they get it right
  } while (guess != number);
  
  return 0;
}
