/*******************************************************************************
*
* Program: Generate A Random Character
* 
* Description: Generate a random character using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=nRmEWUQ2nQ8 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// We could use a preprocessor constant to define a string of possible 
// characters to randomly generate (i.e. randomly select from)
#define POSSIBLE_CHARACTERS "ABCDEFGHIJ0123456789"

// Two functions for two different techniques (including a variation on 
// the first technique).  The first technique involves randomly selecting a 
// character from a string (random_char1()), the second technique involves 
// randomly generating an integer (random_char2()).
//
// char random_char1(const char *possible_characters);
char random_char1();
char random_char2();

int main(void)
{
  // Seed the random number generator with the current time so that the random
  // numbers we get back when calling rand() should be different each time the 
  // program runs.
  srand(time(NULL));

  // We can comment/uncomment the below test code to test out the functions.
  // If we want to test out the variation of random_char1() we will need 
  // to comment/uncomment the relevant function declarations above and 
  // definitions below.
  
  // Test out the function random_char1() which returns a random character
  char random_character = random_char1();

  // Test out the variation of the function random_char1() which returns a 
  // random character
  //
  // const char *possible_characters = "abcdefhij0123456789";
  // char random_character = random_char1(possible_characters);

  // Test out the function random_char2() which returns a random character
  //
  // char random_character = random_char2();

  // Output the randomly generated character
  printf("random: %c\n", random_character);

  return 0;
}

// Returns a randomly generated character from the POSSIBLE_CHARACTERS string
char random_char1()
{
  // Set possible_characters to point to the POSSIBLE_CHARACTERS string
  const char *possible_characters = POSSIBLE_CHARACTERS;
  
  // Find the length of the string and store it into length
  int length = strlen(possible_characters);
  
  // Set random_index to a random integer in the range of 0...length-1, as these
  // are the indexes of the string pointed to be possible_characters.  This works
  // because rand() returns a random integer between 0 and some very large 
  // positive integer (RAND_MAX), and the modulus operator % returns the 
  // remainder of a division operation.  If we take the integer between 
  // 0...RAND_MAX and divide it by length the only possible remainders are
  // 0...length-1, e.g. if length is 5 the only possible remainders are going 
  // to be 0,1,2,3,4, i.e. 0-length-1.
  //
  int random_index = rand() % length;
  
  // return the character in possible_characters string at the random index to
  // "generate" / select a random character
  return possible_characters[random_index];
}

// In a variation of the above approach, we instead have the function accept the
// possible_characters string as an argument.
//
/*
char random_char1(const char *possible_characters)
{
  int length = strlen(possible_characters);
  
  int random_index = rand() % length;
  
  return possible_characters[random_index];
}
*/

// Returns a random characters in the range of characters represented by the 
// integers 33...126.  
//
// In C char values are integers, for example 'A' == 65.  In the ASCII (and 
// UTF-8) encodings, the characters represented by the integers 33-126 would
// all be good to use as potentially random characters (they are all printable
// and recognizable).  This function works by returning a random integer (i.e.
// a char) in the range of 33...126, essentially returning a random character
// represented by the range of integers from 33...126.
char random_char2()
{
  // rand() % 94 will give us a random integer in the range of 0...93, and then
  // when we add 33 to this number we will have a random integer in the range
  // of 33...126.
  return 33 + (rand() % 94);
}