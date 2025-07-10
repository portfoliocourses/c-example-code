/*******************************************************************************
*
* Program: Slot Machine
* 
* Description: A simple slot machine game in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=h4sO97LT_NU
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(void) 
{
  // Slot machine symbols stored in array of pointers to string literals, the
  // program assumes UTF-8 as these symbols are part of UTF-8
  const char *symbols[] = {"🍒", "🍋", "🔔", "💎", "7", "🍀"};

  // Use sizeof() to calculate the number of elements in the array, allows 
  // for programmer to add more symbols at compile time
  const int symbol_count = sizeof(symbols) / sizeof(symbols[0]);

  // Stores choice to continue the game or not
  char choice;
  
  // Seed the random number generator with the current time
  srand( (unsigned int) time(NULL) );

  printf("🎰 Welcome to the Slot Machine! 🎰\n");

  do 
  {
    // Generate 3 random indexes in the array as the symbols of the slot 
    // machine spin
    int i1 = rand() % symbol_count;
    int i2 = rand() % symbol_count;
    int i3 = rand() % symbol_count;
    
    // Output the results
    printf("\nSpinning...\n\n");
    printf("| %s | %s | %s |\n\n", symbols[i1], symbols[i2], symbols[i3]);

    // Anaylze how many symbols matched, output corresponding message
    if (i1 == i2 && i2 == i3)
    {
      printf("🎉 JACKPOT! All three match!\n");
    }
    else if (i1 == i2 || i2 == i3 || i1 == i3)
    {
      printf("✨ Nice! You got two matching symbols!\n");
    }
    else 
    {
      printf("🙁 No match. Try again!");
    }
    
    // Prompt the user to continue or not
    printf("\nPlay again? (y/n): ");
    scanf(" %c", &choice); 

  } while (choice == 'y' || choice == 'Y');

  printf("\nThanks for playing! 🎲\n");

  return 0;
}