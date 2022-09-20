/*******************************************************************************
*
* Program: Truncate A String
*
* Description: Example of truncating a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=x0s2k06uYTg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>

void truncate_string(char string[], int n);

int main(int argc, char *argv[])
{
  // The characters in the string are at the following indexes, with the null
  // terminator that stops the string at index 7.  We can truncate the string
  // by inserting a null terminator earlier in the string.  For example if
  // we want to truncate the string to the first 5 characters, we would insert
  // the null terminator at the index 5 giving us "abcde" as the string.  In
  // general we can insert the null terminator at index n to truncate the
  // string to its first n characters.
  //
  // indexes:      01234567
  char string[] = "abcdefg";

  // Output the string before truncating it
  printf("%s\n", string);

  // Truncate the string to the first 5 characters
  string[5] = '\0';

  // Output the string after truncating it
  printf("%s\n", string);

  // Declare and initialize another test string
  char quote[] = "Treat the problem, not the symptom.";

  // Print the string before truncating it
  printf("quote before: %s\n", quote);

  // Call the truncate_string function to truncate the string to the first 17
  // characters that will guve us "Treat the problem" as the remaining string
  truncate_string(quote, 17);

  // Output the string after truncating the string
  printf(" quote after: %s\n", quote);

  return 0;
}

// Truncates the given string to its first n characters
void truncate_string(char string[], int n)
{
  // Insert the null terminator at index n to truncate the string to the first
  // n characters. When arrays are passed to functions what is really passed
  // is a pointer to the array, and so when we modify the array it will modify
  // the actual string that was passed to the function in main.
  string[n] = '\0';
}