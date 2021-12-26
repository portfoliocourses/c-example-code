/*******************************************************************************
*
* Program: Shuffle An Array
* 
* Description: Example of shuffling an array in C.  Shuffling an array means 
* to randomly re-arrrange the elements of the array.
*
* YouTube Lesson: https://www.youtube.com/watch?v=7OIZ_W75lAM 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

void shuffle(int array[], int length);

int main(void)
{
  // we'll simulate shuffling a deck of cards by creating an array of 52 ints
  int cards[DECK_SIZE];
  
  // store the numbers 1-52 in sequence in the array
  for (int i = 0; i < DECK_SIZE; i++)
    cards[i] = i + 1;
  
  // call the shuffle function to shuffle the array
  shuffle(cards, DECK_SIZE);
  
  // print out the array elements... notice the numbers 1-52 have been randomly 
  // re-arranged
  for (int i = 0; i < DECK_SIZE; i++)
    printf("cards[%d] = %d\n", i, cards[i]);
  
  return 0;
}

// shuffles the array with the given length
void shuffle(int array[], int length)
{
  // seed the random number generator with the current time to ensure random 
  // numbers generated are different each time our program runs
  srand( time(NULL) );
  
  // for each element in the array, randomly swap it with an element in the 
  // array, possibly even itself (it's possible when shuffling a deck of cards
  // that a card ends up in the same spot it started in)
  for (int i = 0; i < length; i++)
  {
    // randomly find an index from 0 - length
    int swap_index = rand() % length;
    
    // swap whatever is at index i with whatever is at the swap_index
    int temp = array[i];
    array[i] = array[swap_index];
    array[swap_index] = temp;
  }
  
}
