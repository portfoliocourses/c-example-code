/*******************************************************************************
*
* Program: Word Scramble Game
* 
* Description: A word scramble guessing game implemented in C.  The 
* implementation includes a word scrambler function that's a bit more 
* sophisticated than most implementations found online in that ensures the word 
* is sufficiently scrambled. 
*
* YouTube Lesson: https://www.youtube.com/watch?v=loa5eBDONHw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

void scramble(char *s);

int main()
{
  // seed the random number generator to ensure different random numbers each 
  // time the program is run
  srand(time(NULL));
  
  // the original word will be stored into original, the scrambled word into 
  // scrambled, and the player's answer into answer
  char original[100] = "friends";
  char scrambled[100];
  char answer[100];
  
  // copy the original word into scrambled, and then scramble the word using 
  // the scramble function
  strcpy(scrambled, original);
  scramble(scrambled);

  bool game_over= false;
  do
  {
    // present the user with the scrambled word
    printf("Unscramble the word: %s\n\n", scrambled);
    
    // ask them to enter the word
    printf("Answer: ");
    scanf("%s", answer);
    
    // if they guess correctly, let them know and end the game, if they 
    // gues incorrectly tell them to try again
    if (strcmp(answer,original) == 0)
    {
      printf("\nYou got it!\n\n");
      game_over = true;
    }
    else printf("\nTry again!\n\n");
    
  // repeat until the user gets the answer right
  } while (!game_over);
  
  return 0;
}

// scramble the word/string s
void scramble(char *s)
{
  int length = strlen(s);
  
  // make all characters lowercase for consistency... otherwise an uppercase 
  // letter could "give away" it is the first letter in the word
  for (int i = 0; i < length; i++)
    s[i] = tolower(s[i]);
  
  // special case: we can't scramble a word of 1 character
  if (length == 1) return ;

  // special case: there is only one way to scramble a word of 2 characters
  if (length == 2)
  {
    char temp = s[0];
    s[0] = s[1];
    s[1] = temp;
    return ;
  }
  
  // keep a copy of the original unscrambled word so we can compare our 
  // scrambled version to it to determine if is sufficiently scrambled 
  char original[length + 1];
  strcpy(original, s);
  
  // variables to help determine when to end the below (outer) loop
  double diff = 0;
  bool same_start = false;
  bool same_end = false;
  int times_stuck = 0;

  // keep attempting to scramble the word until it is sufficiently scrambled
  do
  {
    // Scramble the word by finding two indexes at random in the string and 
    // swapping the characters at those indexes (so long as they are not the
    // same index), and do this as many times as their are characters in the 
    // word. 
    int i = 0;
    while (i < length)
    {
      // finds the two random positions in the string
      int pos1 = rand() % length;
      int pos2 = rand() % length;
      
      // swap the characters at these positions so long as they are not the same
      if (pos1 != pos2)
      {
        char temp = s[pos1];
        s[pos1] = s[pos2];
        s[pos2] = temp;
        i++;
      }
    }
    
    // compute how many characters are different when comparing the original 
    // string to the now scrambled string
    int differences = 0;
    for (int j = 0; j < length; j++)
      if (original[j] != s[j]) differences++;
    
    // compute the fraction of how many characters are different (i.e. 0.5 means
    // that half the characters are different)
    diff = (double) differences / length;
    
    // check if the scrambled string has the same start and same end character 
    // as the original string
    same_start = s[0] == original[0];
    same_end = s[length - 1] == original[length - 1];
    
    // increment times_stuck so we know how many times we've run the loop
    times_stuck++;

  // keep attempting to scramble the string if:
  //    - the scrambled string and the original string have the same starting 
  //      AND ending character... this is too easy for people to guess
  //    - less than half the characters are different when comparing the 
  //      scrambled string to the original
  //
  // BUT stop trying to scramble the string if we have tried to scramble the 
  // string 100 times and still haven't been able to scramble it sufficiently.  
  // This is to account for a possibly infinite loop if we are never able to 
  // meet the above scrambling conditions for some "weird reason" (maybe the 
  // word has many of the same letter or letters, etc.).
  // 
  } while ( ((same_start && same_end) ||
             (diff < 0.5)) &&
            (times_stuck < 100));
  
}
