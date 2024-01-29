/*******************************************************************************
*
* Program: Repeat A String
* 
* Description: Program to repeat a string using C.  For example, if we repeat 
* the string "abc" 3 times the resulting string would be "abcabcabc".
*
* YouTube Lesson: https://www.youtube.com/watch?v=2tgDzFSip00 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *repeat(char *string, size_t repeats);

int main(void)
{
  // Test string to repeat
  char string[] = "abc";
  
  // Call function to repeat the string 3 times
  char *returned_string = repeat(string, 3);
  
  // Output the repeating string "abcabcabc"
  printf("returned_string: %s\n", returned_string);
  
  // Free the dynamically allocated memory for the string
  free(returned_string);

  // Assuming that we know the size of the string and number of times we want
  // to repeat the string at compile-time (when writing the program) we could
  // simply repeat a string by using sprintf() like below.  We know to make the
  // repeat_string char array which stores the repeating string 7 characters in
  // length because we know the original string is 3 characters in length so if
  // we want to repeat it 2 times we'll need 2 * 3 = 6 characters + 1 more for
  // the null terminator == 7 characters total.  We use sprintf() to produce
  // the repeating string, it works like printf() except it "outputs" the string
  // into the char array repeat_string that we pass as an argument.
  //
  /*
  char string[] = "abc";
  char repeat_string[7];
  sprintf(repeat_string, "%s%s", string, string);
  printf("repeat_string: %s\n", repeat_string);
  */

  return 0;
}

// Creates a new string containing the string pointed to by string repeated
// repeats number of times and returns a pointer to the dynamically allocated 
// memory where the new repeating string is stored.
char *repeat(char *string, size_t repeats)
{
  // If the string 'points to nothing' or we have 0 repeats we can't really
  // do anything to repeat the string so we just return NULL
  if (string == NULL || repeats == 0) return NULL;
  
  // Find the length of string to help determine the amount of space needed
  // in memory to store the new repeating string
  size_t length = strlen(string);

  // For the new repeating string we'll need to store length * repeats number
  // of characters + 1 more character for the null terminator to end the string.
  // So we multiply the length of the original string by the number of repeats
  // and 1 to get the number of characters necessary to store the new repeating
  // string, and pass this value to malloc() to allocate space on the heap. 
  // Note that malloc() will actually allocate space in "char sized units" 
  // (i.e. bytes) so there is no need to have something like sizeof(char) 
  // multiplied by the number of chars we need to store.  malloc() returns a
  // pointer to the allocated memory.
  char *new_string = malloc((length * repeats) + 1);
  
  // If malloc() fails it will return NULL so in this case we can't do anything
  // and return NULL from this function
  if (new_string == NULL) return NULL;
  
  // Start new_string off as "the empty string" by just having it contain the
  // null terminator and no actual "content characters".
  new_string[0] = '\0';

  // Then continually concatenate string on to the end of new_string using
  // strcat() repeats number of times.  We do this with a do-while loop 
  // because we know we will always have that repeats > 1 at this point. 
  do
  {
    strcat(new_string, string);
    repeats--;
  } while (repeats > 0);

  // Return a pointer to the repeating string 
  return new_string;
}