/*******************************************************************************
*
* Program: Shuffle A String
*
* Description: Program to shuffle a string using C (i.e. randomly rearrange the
* characters in a string).
*
* YouTube Lesson: https://www.youtube.com/watch?v=MjDAQ_yeNmk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffle_string(char *string, size_t length);

int main(void)
{
  // Create a test string.
  char string[] = "ABCDEFGHI";
  
  // Seed random number generator with the current time to help ensure the 
  // sequence of random numbers returned by rand() may be different each time
  // our program runs (we assume it runs at different times).
  srand(time(NULL));
  
  // Find the length of the string using strlen(), which is from the string.h
  // library and returns the length of the string not including the null 
  // terminator character.
  size_t length = strlen(string);
  
  // Call the function to shuffle the string.
  shuffle_string(string, length);
  
  // Output the shuffled string.
  printf("%s\n", string);
  
  return 0;
}

// Shuffles the string of the provided length
void shuffle_string(char *string, size_t length)
{
  // Stop function if string is 'pointer to nothing' (i.e. string stores NULL).
  if (string == NULL) return ;

  // Stores indexes of the string which are randomly generated.
  int random_index = 0;

  // Used as temp variable to perform swaps of string characters.
  char temp;
  
  // Algorithm: 
  //
  // We loop through each index of the string with counter variable i
  // which goes through the indexes of the string from 0...length-1 with each
  // loop iteration.  
  // 
  // Each loop iteration we generate a random index in the range of 0...length-1
  // as our 'random index'.  The rand() function returns a random integer from 
  // 0 to a very large positive integer (RAND_MAX) and when we divide this 
  // integer by length the remainder must be from 0...length-1.  The modulus 
  // operator (%) will return the remainder of a division operation, so 
  // rand() % length give us an integer in the range of 0..length-1.
  //
  // We then use the classic swap algorithm to swap the characters stored at
  // the indexes i and random_index.  We store the character at random_index
  // into temp so we can safely overwrite it, then we overwrite that index
  // with what is stored at the index i, and then we store the original 
  // character that was at random_index (but is now in temp) at the index i.
  //
  for (int i = 0; i < length; i++)
  {
    random_index = rand() % length; // 0 ... length-1
    
    temp = string[random_index];
    string[random_index] = string[i];
    string[i] = temp;
  }
}