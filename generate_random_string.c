/*******************************************************************************
*
* Program: Generate A Random String
* 
* Description: Generate a random string using C.  One technique involves 
* randomly selecting characters from a string of possible characters, the other
* involves randomly selecting characters from a range of ASCII characters.
*
* YouTube Lesson: https://www.youtube.com/watch?v=1W0hs55TLnQ  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char *random_string1(size_t size, char *possible);
char *random_string2(size_t size);

int main(void)
{
  // Seed the random number generator
  srand(time(NULL));

  // A string of possible characters to include in the string when using the
  // first technique
  char possible[] = "ABCD";

  // Test the first technique
  // char *new_string = random_string1(20, possible); 
  
  // Test the 2nd technique
  char *new_string = random_string2(20);
  
  // Output the new randomly generated string
  printf("New String: %s\n", new_string);
  
  // Free the memory for the new randomly generated string
  free(new_string);
  
  return 0;
}

// Returns a pointer to a randomly generated string of length size-1 (the extra
// character is for the null terminator) made up of characters randomly selected
// from the string possible.
char *random_string1(size_t size, char *possible)
{
  // Need at least one char for null terminator, return NULL if not the case
  if (size == 0) return NULL;

  // We need a string of possible characters, return NULL if not the case
  if (possible == NULL) return NULL;
  
  // Find the length of the string possible 
  size_t possible_length = strlen(possible);
  
  // We need at least one possible character, return NULL if not the case
  if (possible_length == 0) return NULL;
  
  // Allocate space for the string, have string store the pointer to the 
  // block of memory
  char *string = malloc(size);
  
  // If malloc fails it will return NULL, return NULL in this case
  if (string == NULL) return NULL;

  // The actual string length of the string is one less than size (because 
  // of the null terminator) so we calculate this.
  size_t length = size - 1;
  
  // The counter variable i goes through the index of the string from 0 until
  // length-1 to store a char randomly selected from possible at each index
  for (size_t i = 0; i < length; i++)
  {
    // rand() returns a random integer in the range of 0...RAND_MAX where 
    // RAND_MAX is a large positive integer, but we need an integer in the
    // range of 0...possible_length-1, i.e. the indexes of the char values 
    // in the string possible.  If we take 0...RAND_MAX and divide it by 
    // possible_length the remainder wil be in the range of 
    // 0...possible_length-1 (the range of indexes we want).  And the modulus
    // operator % will give us the remainder of a division operation so 
    // rand() % possible_length gives us an index in the range of 
    // 0...possible_length-1.
    string[i] = possible[ rand() % possible_length ];
  }

  // Store the null terminator at the last index to end the string
  string[length] = '\0';
  
  // Return the pointer to the string
  return string;
}

// Returns a pointer to a string of length size-1 with characters randomly
// selected from the range of ASCII characters between 33-126.
char *random_string2(size_t size)
{
  // Need at least one char for null terminator, return NULL if not the case  
  if (size == 0) return NULL;
  
  // Allocate space for the string, have string store the pointer to the 
  // block of memory
  char *string = malloc(size);
  
  // If malloc fails it will return NULL, return NULL in this case
  if (string == NULL) return NULL;
  
  // The actual string length of the string is one less than size (because 
  // of the null terminator) so we calculate this.
  size_t length = size - 1;
  
  // The counter variable i goes through the index of the string from 0 until
  // length-1 to store a char randomly selected from the range of ASCII chars 
  for (size_t i = 0; i < length; i++)
  {
    // Chars in C are "really just integers" (over-simplifying), where we have
    // for example that 'A' == 65.  The ASCII table here shows us which integers
    // represent which characters: https://www.ascii-code.com/.  If we generate
    // an integer in the range of 33...126 we'll get a character in the range 
    // shown in the table.  Using the same logic regarding random integer 
    // ranges as described in the above function, rand() % 94 will give us an
    // integer in the range of 0...93, and if we have 33 + (0...93) then we'll
    // have an integer in the range of 33...126, which we assign to the string
    // at the index currently being set.
    string[i] = 33 + (rand() % 94); 
  }
  
  // Store the null terminator at the last index to end the string
  string[length] = '\0';
  
  // Return the pointer to the string
  return string;
}